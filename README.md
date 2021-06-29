# SBoost

SBoost is a SIMD based C++ library for quick scan and decode bit-packed and delta encoded integer.

See http://people.cs.uchicago.edu/~hajiang/paper/damon2018_sboost.pdf for more technical detail

## System Requirement

SBoost uses CMake for building. It requires C++14 and CMake > 3.15. We developed/tested the library with GCC-9 and CMake 3.16

SBoost requires AVX512 support and is tested on Skylake CPU platforms. For other CPU platforms, please make sure the following compilation flags are supported

`-msse4.1 -mavx -mavx2 -mavx512f -mavx512bw -mavx512dq -mavx512vl -mbmi2`
 

## Import SBoost as a Thirdparty Library

The following CMake snippet supports importing SBoost as a thirdparty library in a CMake project
```
macro(build_sboost)

    set(SBOOST_REPO_URL "https://github.com/UCHI-DB/sboost.git")

    if(CMAKE_BUILD_TYPE MATCHES DEBUG)
        set(CMAKE_SBOOST_DEBUG_EXTENSION "d")
    else()
        set(CMAKE_SBOOST_DEBUG_EXTENSION "")
    endif()

    set(SBOOST_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/sboost_ep-prefix/src/sboost_ep")
    set(_SBOOST_LIBRARY_SUFFIX "${CMAKE_SBOOST_DEBUG_EXTENSION}${CMAKE_STATIC_LIBRARY_SUFFIX}")


    set(SBOOST_STATIC_LIB ${SBOOST_PREFIX}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}sboost${_SBOOST_LIBRARY_SUFFIX})
    set(SBOOST_INCLUDE_DIR ${SBOOST_PREFIX}/include)


    set(SBOOST_CMAKE_ARGS
        ${EP_COMMON_TOOLCHAIN}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        "-DCMAKE_INSTALL_PREFIX=${SBOOST_PREFIX}"
        -DCMAKE_CXX_FLAGS=${EP_CXX_FLAGS}
        -DCMAKE_CXX_FLAGS_${UPPERCASE_BUILD_TYPE}=${EP_CXX_FLAGS})


    externalproject_add(sboost_ep
        GIT_REPOSITORY ${SBOOST_REPO_URL}
        GIT_TAG main
        BUILD_BYPRODUCTS ${SBOOST_STATIC_LIB}
        CMAKE_ARGS ${SBOOST_CMAKE_ARGS} ${EP_LOG_OPTIONS})

    add_library(sboost_static STATIC IMPORTED)
    set_target_properties(sboost_static
            PROPERTIES IMPORTED_LOCATION "${SBOOST_STATIC_LIB}"
            INTERFACE_INCLUDE_DIRECTORIES "${SBOOST_INCLUDE_DIR}")
    add_dependencies(sboost_static sboost_ep)
    file(MAKE_DIRECTORY ${SBOOST_INCLUDE_DIR})
    include_directories(${SBOOST_INCLUDE_DIR})
    set(SBOOST_SIMD_FLAGS -msse4.1 -mavx -mavx2 -mavx512f -mavx512bw -mavx512dq -mavx512vl -mbmi2)
endmacro()
```
