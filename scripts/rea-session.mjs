import {Client} from "../.tools/rea/node_modules/@modelcontextprotocol/sdk/dist/esm/client/index.js";
import {StdioClientTransport} from "../.tools/rea/node_modules/@modelcontextprotocol/sdk/dist/esm/client/stdio.js";
import {mkdir,writeFile} from "node:fs/promises";
import {createWriteStream} from "node:fs";
import {resolve} from "node:path";
import {createInterface} from "node:readline";

await mkdir("analysis/rea",{recursive:true});
const transport=new StdioClientTransport({command:process.execPath,
  args:[resolve(".tools/rea/node_modules/rea-agents/scripts/rea.mjs"),"--mcp"],
  env:{...process.env,GHIDRA_INSTALL_DIR:resolve(".tools/ghidra_12.1.4_PUBLIC"),
    JAVA_HOME:"/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home",
    REA_GHIDRA_STARTUP_TIMEOUT_MS:"300000",
    ...(process.argv.includes("--seeded")?{REA_GHIDRA_SEED_FILE:resolve("analysis/seeds/compiler-prologues.tsv")}:{} )},stderr:"pipe"});
const log=createWriteStream("analysis/rea/server.log",{flags:"a"});
transport.stderr?.pipe(log);
const client=new Client({name:"type-tutor-investigation",version:"1.0.0"});
let count=0;
async function call(name,args={},label) {
  const request={name,arguments:args};
  const result=await client.callTool(request,undefined,{timeout:600000});
  const file=resolve("analysis/rea",label??String(++count).padStart(3,"0")+"-"+name+".json");
  await writeFile(file,JSON.stringify({request,result},null,2)+"\n");
  console.log(JSON.stringify({saved:file,isError:result.isError??false,preview:JSON.stringify(result.structuredContent??result.content).slice(0,650)}));
  return result;
}
try {
  await client.connect(transport);
  const catalog=await client.listTools();
  await writeFile("analysis/rea/tool-schemas.json",JSON.stringify(catalog,null,2)+"\n");
  await call("binary_session",{},"session-before.json");
  console.log("READY: send JSON {name, arguments, save}; close_binary ends the session.");
  for await(const line of createInterface({input:process.stdin,crlfDelay:Infinity})) {
    if(!line.trim())continue;
    try {
      const request=JSON.parse(line);
      await call(request.name,request.arguments??{},request.save);
      if(request.name==="close_binary")break;
    } catch(error) {console.log(JSON.stringify({error:String(error)}));}
  }
} finally {
  await client.close();log.end();process.stdin.pause();
}
