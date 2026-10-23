# Static deployment

Live site: **https://tt.xcstudio.dev**. GitHub Pages hosts the app, Cloudflare CNAME DNS is verified, the TLS certificate is approved and HTTPS is enforced. Pushes to main deploy automatically after tests/build pass.

## Build the artifact

From the repository root:

~~~sh
npm run package:web
~~~

Python 3 is only a packaging tool here. The output artifacts/typing-tutor-remake-v0.2.0-web.zip contains the complete static app, including the verified original Intro, earlier prototype, license scope, provenance and deployment notes. Its adjacent .sha256 and .manifest.json files record archive/file checksums. The uncompressed site is also staged under .runtime/site/.

The packager reads only dist/ and the named release notices. It rejects symlinks and excludes DOS references, analysis archives, tools, dependencies, private saves and server code. No build framework or server interpreter is needed at runtime.

Verify the extracted archive in installed Google Chrome with npm run test:package after packaging. This checks both root and project-path hosting, the current Intro, local Disk files and the preserved prototype.

## Deploy to a static host

Extract the ZIP and publish its contents as the website root. index.html must sit directly in that root. Use HTTPS and serve .js files with a JavaScript MIME type so module imports work. Disk-test hashing requires a secure browser context. The ZIP is portable to static hosting providers; it is not a standalone file:// HTML package.

The included CNAME records tt.xcstudio.dev for branch-based GitHub Pages hosting. Other providers may ignore it. .nojekyll preserves static files when applicable. Link LICENSE, COPYING.md and THIRD_PARTY.md with any redistributed build.

Configure the host for tt.xcstudio.dev, then add the DNS record supplied by that host. The correct DNS target depends on the provider.

## Automatic GitHub Pages deployment

The owner selected GitHub Pages hosting instead of the VPS/tunnel. The Deploy static site workflow runs on every push to main and can also be started manually. It runs unit tests, packages the current static site, uploads the artifact and deploys it to Pages. A failed build/test prevents that deployment.

GitHub Pages and the custom-domain setting have been enabled for this repository. No VPS credentials or Cloudflare Tunnel are needed for this site.

### One-time Cloudflare DNS step

In Cloudflare, select xcstudio.dev → DNS → Records → Add record:

| Field | Value |
| --- | --- |
| Type | CNAME |
| Name | tt |
| Target | xichuanxc.github.io |
| Proxy status | DNS only (grey cloud) |
| TTL | Auto |

Use the hostname without https:// or a repository path. If a record named tt already exists, update that record rather than creating a conflicting duplicate. This applies only to tt; the other websites/tunnel records remain separate.

After DNS resolves, GitHub provisions a certificate. Enable Enforce HTTPS in [repository Pages settings](https://github.com/xichuanxc/typing-tutor-remake/settings/pages) once available, then verify https://tt.xcstudio.dev. The owner completed this DNS step in Cloudflare on 2026-10-24. Authoritative/public DNS, certificate validation, HTTPS enforcement and the public app have been verified.

### Future updates

Push the desired code to main. Follow [Deploy static site runs](https://github.com/xichuanxc/typing-tutor-remake/actions/workflows/pages.yml) to see test/build/deployment status. GitHub hosts the app; Cloudflare provides DNS. No manual ZIP upload is required. An already-open browser tab still needs save/reload to load a new version.

For an Actions deployment, GitHub ignores CNAME files; the Pages custom-domain setting is still required. Until a custom domain is connected, the workflow may serve at the normal GitHub Pages project address. Relative app imports and the prototype link work under a project path.

These instructions follow [GitHub's workflow documentation](https://docs.github.com/en/pages/getting-started-with-github-pages/using-custom-workflows-with-github-pages) and [custom-domain documentation](https://docs.github.com/en/pages/configuring-a-custom-domain-for-your-github-pages-site/managing-a-custom-domain-for-your-github-pages-site).

## Updates and saved progress

Replace the static files as one release. Revalidate HTML and JavaScript after publishing rather than keeping old modules cached across deployments. Visitors with an already-open tab need to save and reload to load an update.

Progress stays in each visitor's browser at its origin. localhost, a Pages preview and tt.xcstudio.dev have separate storage. Moving the site does not transfer existing practice history; JSON export exists, but backup import is not implemented yet. No account, upload service or shared database is part of this artifact.

## Open source and provenance

New implementation code is MIT licensed; recovered original content is separately identified in COPYING.md and THIRD_PARTY.md. The bundle contains original-derived resources needed for the faithful display, so the MIT grant must not be represented as a license to the historical programme's content.

## Live verification — 2026-10-24

GitHub approved the certificate for tt.xcstudio.dev (reported expiry 2027-01-22). HTTP returns 301 to HTTPS and HTTPS returns 200. Installed Chrome verified the live original Intro (Page 1 / 7), secure-context APIs and local Disk-file hashing/loading without page errors. The verification browser temporarily mapped the hostname to a GitHub Pages IP because this machine retained a stale negative DNS cache; normal TLS verification remained enabled. Cloudflare authoritative DNS and resolver 1.1.1.1 both returned the correct CNAME. See [the live receipt](../analysis/pages-live-verification.json).
