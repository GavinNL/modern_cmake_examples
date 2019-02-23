# Single Library with  External Dependencies

This builds the same library as `single_library_with_no_external_deps` but
this time the `math` library we are building will call some functions in
the `libpng` library.

## Things to note

1. You will need to have the libpng installed somewhere in your system. This is recommended since it's easier and would install libz.h
```bash
sudo apt install libpng-dev
```
Or have it manually downloaded/compiled somewhere. Here we are installing libpng to `/tmp/png_install`
```bash
cd /tmp
git clone https://github.com/glennrp/libpng
cd libpng
./configure --prefix /tmp/png_install
make install
```

2. libPNG actually depends on zlib. On linux this should be installed in your system already. When linking with libpng, we will be linking with the
CMAKE target `PNG::PNG`. `PNG::PNG` knows that it requires zlib so it will
automatically link with it. We do not have to manually compile against zlib.


## Compiling

We are going to build/install into a sub folder.

```
cd single_library_with_no_external_deps
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS:BOOL=TRUE -DCMAKE_INSTALL_PREFIX=$PWD/install
cmake --build .
cmake --build . --target install
```

Once you install, the install folder should look like this.
```bash
install
├── include
│   └── math
│       ├── add.h
│       ├── mult.h
│       └── subtract.h
└── lib
    ├── cmake
    │   └── math
    │       ├── mathTargets.cmake
    │       └── mathTargets-noconfig.cmake
    └── libmath.so

```

Calling `ldd` on the `libmath.so` will show you that it links against libpng and
libz.

```bash
?> ldd install/lib/libmath.so

	linux-vdso.so.1 (0x00007ffeb8bdf000)
	libpng16.so.16 => /usr/lib/x86_64-linux-gnu/libpng16.so.16 (0x00007fe5ea758000)
	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fe5ea3ba000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fe5e9fc9000)
	libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007fe5e9dac000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fe5eab8d000)

```


## Compiling without system install of libpng.
If you chose to compile libpng yourself and installed it to a different location;
the build process is the same, except the cmake line will add the following
flag: `-DCMAKE_PREFIX_PATH=PATH_TO_PNG`


```bash
cd single_library_with_no_external_deps
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS:BOOL=TRUE -DCMAKE_INSTALL_PREFIX=$PWD/install -DCMAKE_PREFIX_PATH=/tmp/png_install
cmake --build .
cmake --build . --target install
```

You should see that CMAKE has found PNG in a different location
```bash
-- The CXX compiler identification is GNU 7.3.0
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found ZLIB: /usr/lib/x86_64-linux-gnu/libz.so (found version "1.2.11")
-- Found PNG: /tmp/png_install/lib/libpng.so (found version "1.6.37.git")
-- Configuring done
-- Generating done
```
