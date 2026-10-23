# Earlier and Y2K-fixed help comparison

Recorded 2026-10-24 from read-only comparison of the supplied OLD/TT.HLP and the preserved TT/TT.HLP. This compares help bytes, not executable behavior. The file dates and owner's account identify the earlier version; they do not establish that every supplied byte is pristine.

| Copy | Bytes | SHA-256 |
| --- | --- | --- |
| OLD/TT.HLP | 12,508 | 2584400a6f63f44f9f8cbbecdb30901dc3da44935b6d0c1cec3e1ac12e328140 |
| Y2K-fixed TT/TT.HLP | 12,651 | 5c787383d36fdb07dbb48a222b747309bc2aa91b1bdf45c769673f3a469c8bca |

## Findings

The fixed copy splits the original welcome paragraph and inserts the TiANWEi Y2K credit and contact details. The email address contains @, the programme's page delimiter, so the existing reader treats the contact line as two pages.

The earlier file also has damaged/non-text regions. Starting at offset 0x400, binary-looking bytes replace menu explanations in Intro. A second region, 0x2000–0x2800, contains 2,043 zero bytes out of 2,048, interrupting Reports and Options help. The file has 2,134 zero bytes and 477 bytes above ASCII overall; the fixed copy has neither. We have not established the cause of the damage.

A credit-free candidate uses the intact earlier welcome through its first @, followed by the fixed copy from “This introduction will explain” onward. This candidate is exactly 12,508 bytes. It matches the earlier file byte for byte except in these ranges (end exclusive):

| Range | Length | Content affected |
| --- | --- | --- |
| 0x400–0x800 | 1,024 | Intro menu/help explanations and onboarding description |
| 0x2000–0x2800 | 2,048 | Reports and Options help |

The initial comparison supported this reconstruction. Subsequent Internet Archive verification confirmed every byte of the candidate, including both missing regions.

## Verified Intro text

[Reconstructed Intro text](../analysis/help-comparison/intro-reconstructed.txt) contains 17 pages separated by the original @ delimiter. It combines the intact earlier opening with the readable fixed text; the entire text was subsequently confirmed byte for byte against the archived DOS distribution. Literal * and # home-key placeholders are retained for the normal display substitutions.

The app now uses this verified text for Options → Intro. The builder validates its SHA-256 before substituting only the Intro section. Other Help sections retain the existing fixed reference. Source @ boundaries define 17 text parts; the existing browser reader groups them into fitted screens. Programmer attribution remains in THIRD_PARTY.md. Neither original reference has been replaced.

[Machine-readable comparison](../analysis/help-comparison/comparison.json) records hashes, ranges, counts and the reconstruction recipe. Reproduce from the project root with:

~~~sh
python3 scripts/compare-tt-help.py --original /path/to/OLD/TT.HLP
~~~

The public GitHub repository and its initial commit already exist, and CI passed. No v0.2.0 GitHub release was published; release publication is on hold. The owner subsequently authorized applying and committing the verified Intro; release publication remains separate.

## Internet verification and application

[Internet Archive](https://archive.org/details/Typing_Tutor_IV_DOS) lists a 12,508-byte [tt.hlp](https://archive.org/download/Typing_Tutor_IV_DOS/tt.hlp). Its downloaded SHA-1 ca89875d21cf47e8a132117d79dbf9ad675b27c0 and MD5 6449edf2a52d837c936d0b53b12822ed match archive metadata. SHA-256 is b7dc2e9a7e3c30e8bd817c3c4e4c61f7d03c841784d6f861746d5876afadc8cf.

All bytes match the prior credit-free candidate. There are no zero bytes or bytes above ASCII. The first section exactly matches the included intro-reconstructed.txt (SHA-256 4d8dd081f16f7eb6f110e093442e32590bf2e1eb8c15afb2f1c1953a78193bc5). See [the verification receipt](../analysis/help-comparison/internet-verification.json).

The raw downloaded HLP stays in ignored .runtime/help-research/ia-tt.hlp. Rebuilding uses the checked-in verified Intro excerpt, so it does not require internet access or the ignored download. Existing original references/unpacked executable are still required by the full resource builder. This is independently archived content, not publisher-certified original media; no original executable was downloaded or run.
