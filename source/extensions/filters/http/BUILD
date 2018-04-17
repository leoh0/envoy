licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
)

envoy_package()

envoy_cc_library(
    name = "well_known_names",
    hdrs = ["well_known_names.h"],
    deps = [
        "//source/common/config:well_known_names",
        "//source/common/singleton:const_singleton",
    ],
)

envoy_cc_library(
    name = "filter_base",
    hdrs = ["filter_base.h"],
    deps = [
        "//include/envoy/server:filter_config_interface",
    ],
)
