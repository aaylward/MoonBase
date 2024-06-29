load("@buildifier_prebuilt//:rules.bzl", "buildifier", "buildifier_test")

buildifier(
    name = "buildifier",
    exclude_patterns = [
        "./.bazelbsp/*",
        "./vcpkg_installed/*",
    ],
    lint_mode = "fix",
)

buildifier_test(
    name = "buildifier_test",
    size = "small",
    timeout = "short",
    exclude_patterns = [
        "./.bazelbsp/*",
        "./vcpkg_installed/*",
    ],
    lint_mode = "warn",
    mode = "diff",
    no_sandbox = True,
    workspace = "//:MODULE.bazel",
)
