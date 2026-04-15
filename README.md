# F-DDrace

This repository is built on top of F-DDrace and keeps F-DDrace as the gameplay and architecture foundation.
It is also a vibe-coded project: rapid, iterative development with AI-assisted workflows and practical in-server testing.

## Highlights

- Supports both 0.7 and DDNet clients.
- Extended gameplay systems (accounts, plots, economy, minigames, custom weapons).
- High-player-count server architecture.
- Large set of server and chat commands for administration and customization.

## Repository Layout

- `src/` - game/server/engine source code.
- `datasrc/` - data generation sources.
- `scripts/` - helper scripts for development and tooling.
- `cmake/` - CMake modules.
- `F-DDrace_Entities/` - entity references for mapping/editor usage.
- `other/` - third-party and platform-specific support artifacts.

## Build

This project follows the DDNet/Teeworlds CMake build workflow.

### Linux (example)

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

Server binary is produced in the build output (for example `teeworlds_srv`).

## Quick Start (Server)

1. Build the project.
2. Copy the example config:
   ```bash
   cp autoexec.example.cfg autoexec.cfg
   ```
3. Edit `autoexec.cfg` and set server name/port and passwords.
4. Run the server binary.

## Configuration and Commands

Primary references in source:

- Server variables: `src/game/variables.h`
- Console/admin commands: `src/game/ddracecommands.h`
- Chat commands: `src/game/server/ddracechat.h`

## Security Notes

- Never commit real secrets (`sv_rcon_password`, API keys, webhook URLs, etc.).
- Keep production values only in local `autoexec.cfg` (ignored by git).
- Use `autoexec.example.cfg` as a safe template.

## Contributing

See `CONTRIBUTING.md`.

## License

See `LICENSE`.
