// swift-tools-version: 5.10
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "ClamshellChecker",
    platforms: [.macOS(.v13)],
    products: [
        .library(name: "ClamshellChecker", targets: ["ClamshellChecker"])
    ],
    targets: [
        .target(name: "libclamshell", dependencies: [], exclude: []),
        .target(name: "ClamshellChecker", dependencies: ["libclamshell"]),
       
    ]
)