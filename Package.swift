// swift-tools-version: 5.10
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Grape",
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(name: "Grape", targets: ["Grape"]),
        .library(name: "GrapeCXX", targets: ["GrapeCXX"]),
        .library(name: "GrapeObjC", targets: ["GrapeObjC"])
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.d
        .target(name: "Grape", dependencies: ["GrapeObjC"]),
        .target(name: "GrapeCXX", sources: [""], publicHeadersPath: "include", swiftSettings: [
            .interoperabilityMode(.Cxx)
        ]),
        .target(name: "GrapeObjC", dependencies: ["GrapeCXX"], publicHeadersPath: "include", swiftSettings: [
            .interoperabilityMode(.Cxx)
        ])
    ],
    cLanguageStandard: .c2x,
    cxxLanguageStandard: .cxx2b
)
