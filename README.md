# Pairings in C

[![Build Status](https://travis-ci.org/IAIK/pairings_in_c.svg?branch=develop)](https://travis-ci.org/IAIK/pairings_in_c)
[![codecov](https://codecov.io/gh/IAIK/pairings_in_c/branch/develop/graph/badge.svg)](https://codecov.io/gh/IAIK/pairings_in_c)

This repository contains a C library for pairing-based cryptography which was part of results published at CHES 2014 [4]. It supports bilinear pairings based on 160-bit and 254-bit Barreto-Naehrig elliptic curves.

## Directory Structure

* `android_demo`: A demo application for pairing-based group signatures.
* `doc`: Documentation for the pairing library and the demo application.
* `framework`: The source files for the pairing library.
  * `benchmark`: Contains an application for benchmarking the library.
  * `cmake`: CMake configuration files.
  * `demo`: Applications showing the versatility of the pairing library.
  * `include`: Header files of the pairing library.
  * `linker`: Linker scripts.
  * `src`: Source files of the pairing library.
  * `test`: Applications containing test vectors for each arithmetic layer of the library.

## Build Requirements

* cmake
* a C compiler for the targeted platform

Optional:

* doxygen (for the code documentation)
* lcov & genhtml (for coverage testing)

## Building

The library in the subdirectory `framework` can be built like any other cmake project with the following commands:

~~~ 
$ mkdir <build-directory>
$ cd <build-directory>
$ cmake [cmake-options] <source-directory>
$ cmake --build . [--target <target-name>]
~~~

The `cmake-options` are of the form `-D<option>=<value>` and are optional.

Selection of cmake-options:

* `ARCHITECTURE`: The target architecture. (default: `ARCH_X86`)
* `BENCHMARK_SRC`: The time source for benchmarks. (`BM_CYCLE`, `BM_CLOCK`)
* `CMAKE_BUILD_TYPE`: The desired build type. (`Debug`, `Release`, `MinSizeRel`, ...; default: `MinSizeRel`)
* `CMAKE_TOOLCHAIN_FILE`: Path to the toolchain file for cross compilation. (examples can be found under `cmake/toolchain`)
* `CMAKE_INSTALL_PREFIX`: Path to the desired installation root.
* `TEST_COVERAGE`: Build library with profiling information to enable test coverage generation. (`ON`, `OFF`)
* `INSTALL_DOXYGEN`: Include the doxygen documentation when installing/packaging. (`ON`, `OFF`)

If no target name is specified for make, the default target, the library itself, is built.

Selection of target-names:

* `suite`: Build the test applications.
* `test_X`: Build test `X` to verify output.
* `coverage`: Run the all tests and generate a coverage report. (requires `TEST_COVERAGE=ON`)
* `doxygen`: Generate the doxygen documentation into the build directory.
* `package`: Build the library and package the result including headers for distribution.
* `package_source`: Package the source tree for distribution.

## Testing

The library comes with a comprehensive test set created in advance. Each arithmetic layer involved in the pairing computations, i.e., multi-precision integer, prime field, elliptic curves, and pairing arithmetic itself, is tested in a separate test program consisting of test vectors invoked on the library interface. The target `suite` can be used to built these test applications. The tests are then executed via the respective the test programs that print the test result on the console, e.g.:

~~~
$ <build-directory>/bin/test_fp 
~~~

## Demo Applications

The subdirectory `demo` of the library provides a set of simple console demo applications:

* `gss_hwang_demo`: Group signature scheme by Hwang et al. [3].
* `ibe_demo`: Key encapsulation variant of the identity-based encryption scheme by Boneh et al. [1].
* `pairing_demo`: Simple demonstration of the bilinearity property. 
* `sdh_zk_demo`: Group signature scheme by Boneh et al. [2].

These demo applications can be built and invoked as follows:

~~~
$ cd <build-directory>
$ make <demo-application>
$ out/bin/demo-application
~~~

## Android Demo

The Android demo implements the group signature scheme by Boneh et al [2]. It uses the android-ndk to delegate the group signature operations to native C code built upon our library and to transfer the data involved in the group signature operations via the Java Native Interface (JNI). The native code provides both the sign and verify operations and is supplied with the secret group credentials from the Java code. 

The application can be started in either signer or verifier mode. The signer obtains a signature for a specific message from our library using JNI and transmits the resulting signature to the verifier using Near Field Communication (NFC). The generated signatures are transferred via NFC to a device running the application as a verifier. The verifier receiving the anonymous group signature then checks its validity. However, for demonstration purposes it also implements the opening feature that usually is only available to the group manager, allowing to reveal the signer's identity.

## Usage

Using the library is straight forward given the header files and the static library (libpairings_in_c.a). It has however to be considered that the user code is compiled with the same `ARCHITECTURE` preprocessor definition as during compilation of the library.

The library supports both a 160-bit and a 254-bit elliptic curve and bilinear pairings suitable for these curves. Relevant configurations like the elliptic curve and optimizations to be used can be done in the file `framework/include/config.h`. 

## Benchmark

The subdirectory `benchmark` contains a simple application that allows to benchmark the operations at each arithmetic layer. Depending on the target platform, either the number of consumed clock cycles or the required amount of time is obtained. This already has to be considered during build configuration and thus the `BENCHMARK_SRC` has to be passed to cmake appropriately.

## Further Reading

* [Project Page](http://www.iaik.tugraz.at/content/research/opensource/pairings_in_c/)
* [Institute for Applied Information Processing and Communications (IAIK)](http://www.iaik.tugraz.at)

## Authors

* Thomas Unterluggauer (<thomas.unterluggauer@iaik.tugraz.at>)
* Erich Wenger (<erich.wenger@iaik.tugraz.at>)
* Raphael Spreitzer (<raphael.spreitzer@iaik.tugraz.at>)
* Mario Werner (<mario.werner@iaik.tugraz.at>)
* René Hölbling (<rene.hoelbling@student.tugraz.at>)

## License

Custom Commercial License or GPLv3 License. 

## References

[1] Boneh, Dan, and Xavier Boyen. "Secure identity based encryption without random oracles." Advances in Cryptology–Crypto 2004. Springer Berlin Heidelberg, 2004.
  
[2] Boneh, Dan, Xavier Boyen, and Hovav Shacham. "Short group signatures." Advances in Cryptology–CRYPTO 2004. Springer Berlin Heidelberg, 2004.
  
[3] Hwang, Jung Yeon, et al. "Short group signatures with controllable linkability." Lightweight Security & Privacy: Devices, Protocols and Applications (LightSec), 2011 Workshop on. IEEE, 2011.
  
[4] Unterluggauer, Thomas, and Erich Wenger. "Efficient pairings and ECC for embedded systems." Cryptographic Hardware and Embedded Systems–CHES 2014. Springer Berlin Heidelberg, 2014. 298-315.
  


