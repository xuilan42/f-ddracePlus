# Security Policy

## Reporting a Vulnerability

If you find a security issue, do not open a public issue with exploit details.

Use a private channel with the maintainer team and include:

- affected component/path;
- impact and attack scenario;
- minimal reproduction steps;
- suggested mitigation (if available).

## Scope

Security-sensitive areas include, but are not limited to:

- authentication/account flows;
- remote admin/console access;
- network packet parsing and validation;
- any feature handling secrets or external service keys.

## Secret Handling

- Never commit production credentials.
- Keep server secrets in local config files excluded by `.gitignore`.
