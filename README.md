# Modern CMake Examples

These are a set of CMake project examples using modern CMake.

## single_library_with_no_external_deps
A project which compiles into a single
shared or static library. It contains unit tests as well.

## single_library_with_no_external_deps

Project which uses a single external library (libpng). The code is the same as
**single_library_with_no_external_deps**

## multi_library_no_external_deps

This is the same as **single_library_with_no_external_deps** except it breaks
the single library into multiple smaller libraries under a single namespace. The
unit tests compile against a specific library which it is testing.
