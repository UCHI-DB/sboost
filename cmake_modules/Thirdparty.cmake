macro(build_gtest)
    message(STATUS "Building gtest from source")
    set(GTEST_BUILD_VERSION 1.10.0)
    set(GTEST_SOURCE_URL
            "https://github.com/google/googletest/archive/release-${GTEST_BUILD_VERSION}.tar.gz")

    set(GTEST_VENDORED TRUE)
    set(GTEST_CMAKE_CXX_FLAGS ${EP_CXX_FLAGS})

    if (UPPERCASE_BUILD_TYPE MATCHES DEBUG)
        set(CMAKE_GTEST_DEBUG_EXTENSION "d")
    else ()
        set(CMAKE_GTEST_DEBUG_EXTENSION "")
    endif ()

    set(GTEST_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/googletest_ep-prefix/src/googletest_ep")

    set(GTEST_INCLUDE_DIR "${GTEST_PREFIX}/include")
    set(GMOCK_INCLUDE_DIR "${GTEST_PREFIX}/include")
    set(GTEST_LIBRARY_DIR ${GTEST_PREFIX}/lib)

    set(_GTEST_RUNTIME_DIR ${BUILD_OUTPUT_ROOT_DIRECTORY})

    set(_GTEST_LIBRARY_SUFFIX "${CMAKE_GTEST_DEBUG_EXTENSION}${CMAKE_STATIC_LIBRARY_SUFFIX}")


    set(GTEST_STATIC_LIB
            "${GTEST_LIBRARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${_GTEST_LIBRARY_SUFFIX}")
    set(GMOCK_STATIC_LIB
            "${GTEST_LIBRARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}gmock${_GTEST_LIBRARY_SUFFIX}")
    set(GTEST_MAIN_STATIC_LIB
            "${GTEST_LIBRARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}gtest_main${_GTEST_LIBRARY_SUFFIX}")
    set(GTEST_CMAKE_ARGS
            ${EP_COMMON_TOOLCHAIN}
            -DCMAKE_BUILD_TYPE=${UPPERCASE_BUILD_TYPE}
            "-DCMAKE_INSTALL_PREFIX=${GTEST_PREFIX}"
            -DBUILD_SHARED_LIBS=OFF
            -DCMAKE_CXX_FLAGS=${GTEST_CMAKE_CXX_FLAGS}
            -DCMAKE_CXX_FLAGS_${UPPERCASE_BUILD_TYPE}=${GTEST_CMAKE_CXX_FLAGS})


    #list(APPEND GTEST_CMAKE_ARGS "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=${_GTEST_RUNTIME_DIR}"
    #            "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY_${UPPERCASE_BUILD_TYPE}=${_GTEST_RUNTIME_DIR}")

    #    add_definitions(-DGTEST_LINKED_AS_SHARED_LIBRARY=1)

    externalproject_add(googletest_ep
            URL ${GTEST_SOURCE_URL}
            BUILD_BYPRODUCTS ${GTEST_STATIC_LIB} ${GTEST_MAIN_STATIC_LIB}
            ${GMOCK_STATIC_LIB}
            CMAKE_ARGS ${GTEST_CMAKE_ARGS} ${EP_LOG_OPTIONS})

    # The include directory must exist before it is referenced by a target.
    file(MAKE_DIRECTORY "${GTEST_INCLUDE_DIR}")

    add_library(GTest::GTest STATIC IMPORTED)

    set_target_properties(GTest::GTest
            PROPERTIES IMPORTED_LOCATION "${GTEST_STATIC_LIB}"
            INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIR}")

    add_library(GTest::Main STATIC IMPORTED)
    set_target_properties(GTest::Main
            PROPERTIES IMPORTED_LOCATION "${GTEST_MAIN_STATIC_LIB}"
            INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIR}")

    add_library(GTest::GMock STATIC IMPORTED)
    set_target_properties(GTest::GMock
            PROPERTIES IMPORTED_LOCATION "${GMOCK_STATIC_LIB}"
            INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIR}")
    add_dependencies(GTest::GTest googletest_ep)
    add_dependencies(GTest::Main googletest_ep)
    add_dependencies(GTest::GMock googletest_ep)
endmacro()

macro(build_gbenchmark)
    message(STATUS "Building benchmark from source")
    set(GBENCHMARK_BUILD_VERSION 1.5.2)
    set(GBENCHMARK_SOURCE_URL "https://github.com/google/benchmark/archive/v${GBENCHMARK_BUILD_VERSION}.tar.gz")

    set(GBENCHMARK_CMAKE_CXX_FLAGS "${EP_CXX_FLAGS} -std=c++11")

    set(GBENCHMARK_PREFIX
            "${CMAKE_CURRENT_BINARY_DIR}/gbenchmark_ep/src/gbenchmark_ep-install")
    set(GBENCHMARK_INCLUDE_DIR "${GBENCHMARK_PREFIX}/include")
    set(
            GBENCHMARK_STATIC_LIB
            "${GBENCHMARK_PREFIX}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}benchmark${CMAKE_STATIC_LIBRARY_SUFFIX}"
    )
    set(
            GBENCHMARK_MAIN_STATIC_LIB
            "${GBENCHMARK_PREFIX}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}benchmark_main${CMAKE_STATIC_LIBRARY_SUFFIX}"
    )
    set(GBENCHMARK_CMAKE_ARGS
            ${EP_COMMON_CMAKE_ARGS}
            "-DCMAKE_INSTALL_PREFIX=${GBENCHMARK_PREFIX}"
            -DCMAKE_INSTALL_LIBDIR=lib
            -DBENCHMARK_ENABLE_TESTING=OFF
            -DCMAKE_CXX_FLAGS=${GBENCHMARK_CMAKE_CXX_FLAGS})

    externalproject_add(gbenchmark_ep
            URL ${GBENCHMARK_SOURCE_URL}
            BUILD_BYPRODUCTS "${GBENCHMARK_STATIC_LIB}"
            "${GBENCHMARK_MAIN_STATIC_LIB}"
            CMAKE_ARGS ${GBENCHMARK_CMAKE_ARGS} ${EP_LOG_OPTIONS})

    # The include directory must exist before it is referenced by a target.
    file(MAKE_DIRECTORY "${GBENCHMARK_INCLUDE_DIR}")

    add_library(benchmark::benchmark STATIC IMPORTED)
    set_target_properties(benchmark::benchmark
            PROPERTIES IMPORTED_LOCATION "${GBENCHMARK_STATIC_LIB}"
            INTERFACE_INCLUDE_DIRECTORIES
            "${GBENCHMARK_INCLUDE_DIR}")

    add_library(benchmark::benchmark_main STATIC IMPORTED)
    set_target_properties(benchmark::benchmark_main
            PROPERTIES IMPORTED_LOCATION "${GBENCHMARK_MAIN_STATIC_LIB}"
            INTERFACE_INCLUDE_DIRECTORIES
            "${GBENCHMARK_INCLUDE_DIR}")

    add_dependencies(benchmark::benchmark gbenchmark_ep)
    add_dependencies(benchmark::benchmark_main gbenchmark_ep)
    include_directories(${GBENCHMARK_INCLUDE_DIR})
endmacro()

set(EP_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_${UPPERCASE_BUILD_TYPE}}")
set(EP_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_${UPPERCASE_BUILD_TYPE}}")
set(EP_CXX_FLAGS "${EP_CXX_FLAGS} -fPIC")
set(EP_C_FLAGS "${EP_C_FLAGS} -fPIC")

set(EP_COMMON_TOOLCHAIN -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER})

if (CMAKE_AR)
    set(EP_COMMON_TOOLCHAIN ${EP_COMMON_TOOLCHAIN} -DCMAKE_AR=${CMAKE_AR})
endif ()

if (CMAKE_RANLIB)
    set(EP_COMMON_TOOLCHAIN ${EP_COMMON_TOOLCHAIN} -DCMAKE_RANLIB=${CMAKE_RANLIB})
endif ()

# External projects are still able to override the following declarations.
# cmake command line will favor the last defined variable when a duplicate is
# encountered. This requires that `EP_COMMON_CMAKE_ARGS` is always the first
# argument.
set(EP_COMMON_CMAKE_ARGS
        ${EP_COMMON_TOOLCHAIN}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_C_FLAGS=${EP_C_FLAGS}
        -DCMAKE_C_FLAGS_${UPPERCASE_BUILD_TYPE}=${EP_C_FLAGS}
        -DCMAKE_CXX_FLAGS=${EP_CXX_FLAGS}
        -DCMAKE_CXX_FLAGS_${UPPERCASE_BUILD_TYPE}=${EP_CXX_FLAGS})

set(EP_LOG_OPTIONS
        LOG_CONFIGURE
        1
        LOG_BUILD
        1
        LOG_INSTALL
        1
        LOG_DOWNLOAD
        1)


include(ExternalProject)