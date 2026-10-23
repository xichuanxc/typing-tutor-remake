# Static deployment

Intended domain: **tt.xcstudio.dev**. The domain is recorded as proposed; it has not been connected or deployed by this packaging step.

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

## Optional GitHub Pages workflow

A manual Deploy static site workflow is included; it does not run automatically on push. To use it:

1. In this repository, open Settings → Pages and select GitHub Actions as the publishing source.
2. Run Actions → Deploy static site → Run workflow from main. It checks unit tests, packages the same site and deploys its staged files.
3. In Pages settings, set the custom domain to tt.xcstudio.dev. Configure that setting before adding the DNS record.
4. At the DNS provider for xcstudio.dev, add CNAME host tt pointing to xichuanxc.github.io (no repository path).
5. After DNS validation and certificate provisioning, enable Enforce HTTPS.

For an Actions deployment, GitHub ignores CNAME files; the Pages custom-domain setting is still required. Until a custom domain is connected, the workflow may serve at the normal GitHub Pages project address. Relative app imports and the prototype link work under a project path.

These instructions follow [GitHub's workflow documentation](https://docs.github.com/en/pages/getting-started-with-github-pages/using-custom-workflows-with-github-pages) and [custom-domain documentation](https://docs.github.com/en/pages/configuring-a-custom-domain-for-your-github-pages-site/managing-a-custom-domain-for-your-github-pages-site).

## Updates and saved progress

Replace the static files as one release. Revalidate HTML and JavaScript after publishing rather than keeping old modules cached across deployments. Visitors with an already-open tab need to save and reload to load an update.

Progress stays in each visitor's browser at its origin. localhost, a Pages preview and tt.xcstudio.dev have separate storage. Moving the site does not transfer existing practice history; JSON export exists, but backup import is not implemented yet. No account, upload service or shared database is part of this artifact.

## Open source and provenance

New implementation code is MIT licensed; recovered original content is separately identified in COPYING.md and THIRD_PARTY.md. The bundle contains original-derived resources needed for the faithful display, so the MIT grant must not be represented as a license to the historical programme's content.
