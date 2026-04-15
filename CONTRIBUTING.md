# Contributing

## Development Setup

- Build with CMake from repository root.
- Prefer separate build directory (`build/`).
- Keep local runtime config in `autoexec.cfg` (never commit real secrets).

## Pull Requests

- Keep PRs focused and small when possible.
- Describe behavior changes and test steps.
- If you add config or commands, update docs in `README.md` and/or headers.
- Ensure project still builds before opening PR.

## Style

- Follow existing code style and naming in touched files.
- Avoid unrelated refactors in feature/fix PRs.
- Add comments only when logic is non-obvious.

## Security

- Do not commit credentials, tokens, webhook URLs, private keys, or dumps.
- Use placeholder values in examples and documentation.
