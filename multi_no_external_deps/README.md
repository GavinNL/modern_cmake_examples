# Multiple Library Project with No External Dependencies

This builds the same library as `single_library_with_no_external_deps` but
instead of building it as a single library called `libmath.so` we are going
to build it into three separate libraries (`libadd.so`, `libsubtract.so` and
`libmult.so`). All three libraries will be housed under a single namespace
called `math`

The intent here is that the `math` library is supposed to be built as one, but
we can choose which sub libraries we want to link to depending on our needs.

## Things to Note

1. The function `mult(a,b)` calls `add(a,b)` therefore `libmult` must link against
`libadd`.

2. Our folder hierarchy is a little bit different. This is to keep the submodules
separate from each other.

3. Instead of including `#include<math/add.h>` we will now include `#include<math/add/add.h`.
