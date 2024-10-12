# Clamshell Checker

Provides a simple `isLidClosed() -> Bool` interface to check if the laptop lid is closed on macOS.

Also available, a Combine publisher: `func updates() -> AnyPublisher<Bool, Never>`

With thanks to:
- https://github.com/alin23/Lunar/blob/b519b28a80aae8388204509f8234285f1bcfe45f/Lunar/DDC/DDC.swift#L968 for ClamShell code
- https://www.bensnider.com/posts/wrapping-c-code-within-a-single-swift-package/ for how to use C in a SPM package