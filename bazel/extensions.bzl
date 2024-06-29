"bzlmod extensions"

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

def _hedron_impl(ctx):  # buildifier: disable=unused-variable
    hedron_compile_commands_setup()

hedron_setup = module_extension(
    implementation = _hedron_impl,
)

def _http_impl(ctx):  # buildifier: disable=unused-variable
    http_archive(
        name = "mongoose_cc",
        strip_prefix = "mongoose-7.14",
        patch_args = ["-p1"],
        patches = ["//bazel/patches:mongoose.patch"],
        sha256 = "7c4aecf92f7f27f1cbb2cbda3c185c385f2b7af84f6bd7c0ce31b84742b15691",
        urls = ["https://github.com/cesanta/mongoose/archive/refs/tags/7.14.tar.gz"],
    )

non_module_deps = module_extension(implementation = _http_impl)
