cmake_minimum_required(VERSION 3.15)
project(sboost)

set(CMAKE_CXX_STANDARD 14)

set(SBOOST_VERSION 0.1)
set(SBOOST_SIMD_FLAGS -msse4.1 -mavx -mavx2 -mavx512f -mavx512bw -mavx512dq -mavx512vl -mbmi2)
set(RUNTIME_INSTALL_DIR bin)
set(CMAKE_INSTALL_LIBDIR lib)
set(CMAKE_INSTALL_HEADERDIR include)
set(CMAKE_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
string(TOUPPER ${CMAKE_BUILD_TYPE} UPPERCASE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE ${UPPERCASE_BUILD_TYPE})
string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_SUBDIR_NAME)
set(BUILD_OUTPUT_ROOT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${BUILD_SUBDIR_NAME}/")


set(C_FLAGS_DEBUG "-ggdb -O0")
set(C_FLAGS_FASTDEBUG "-ggdb -O1")
set(CXX_FLAGS_DEBUG "-ggdb -O0")
set(CXX_FLAGS_FASTDEBUG "-ggdb -O1")
set(C_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CXX_FLAGS_RELEASE "-O3 -DNDEBUG")


# Set compile flags based on the build type.
message(
        "Configured for ${CMAKE_BUILD_TYPE} build (set with cmake -DCMAKE_BUILD_TYPE={release,debug,...})"
)
if("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS_DEBUG}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS_DEBUG}")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "RELWITHDEBINFO")

elseif("${CMAKE_BUILD_TYPE}" STREQUAL "FASTDEBUG")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS_FASTDEBUG}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS_FASTDEBUG}")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "RELEASE")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS_RELEASE}")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "PROFILE_GEN")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS_PROFILE_GEN}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS_PROFILE_GEN}")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "PROFILE_BUILD")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS_PROFILE_BUILD}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS_PROFILE_BUILD}")
else()
    message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
endif()

if("${CMAKE_CXX_FLAGS}" MATCHES "-DNDEBUG")
    set(ARROW_DEFINITION_FLAGS "-DNDEBUG")
else()
    set(ARROW_DEFINITION_FLAGS "")
endif()

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules")
include(CMakePackageConfigHelpers)

set(SBOOST_SRC
        bitmap_writer.cc
        byteutils.cc
        sboost.cc
        unpacker.cc
        encoding/deltabp.cc
        encoding/encoding_utils.cc
        encoding/rlehybrid.cc
        simd.cc)

set(SBOOST_HEADER
        sboost.h
        )

add_library(sboost_objlib OBJECT ${SBOOST_SRC})
set_property(TARGET sboost_objlib PROPERTY POSITION_INDEPENDENT_CODE 1)
target_compile_options(sboost_objlib PUBLIC -pthread -fvisibility=hidden ${SBOOST_SIMD_FLAGS})

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    set(CMAKE_SBOOST_DEBUG_EXTENSION "d")
else()
    set(CMAKE_SBOOST_DEBUG_EXTENSION "")
endif()

add_library(sboost_static STATIC $<TARGET_OBJECTS:sboost_objlib>)
set_target_properties(sboost_static
        PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${BUILD_OUTPUT_ROOT_DIRECTORY}"
        OUTPUT_NAME sboost${CMAKE_SBOOST_DEBUG_EXTENSION}
        PUBLIC_HEADER ${SBOOST_HEADER})
install(TARGETS sboost_static
        EXPORT sboost_targets
        RUNTIME DESTINATION ${RUNTIME_INSTALL_DIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_HEADERDIR})

add_library(sboost_shared SHARED $<TARGET_OBJECTS:sboost_objlib>)
set_target_properties(sboost_shared
        PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${BUILD_OUTPUT_ROOT_DIRECTORY}"
        OUTPUT_NAME sboost${CMAKE_SBOOST_DEBUG_EXTENSION}
        PUBLIC_HEADER ${SBOOST_HEADER})
set_target_properties(sboost_shared
        PROPERTIES LIBRARY_OUTPUT_DIRECTORY
        "${BUILD_OUTPUT_ROOT_DIRECTORY}"
        RUNTIME_OUTPUT_DIRECTORY
        "${BUILD_OUTPUT_ROOT_DIRECTORY}"
        OUTPUT_NAME
        sboost
        VERSION
        1.0.0
        SOVERSION
        1.0.0
        )

install(TARGETS sboost_shared
        EXPORT sboost_targets
        RUNTIME DESTINATION ${RUNTIME_INSTALL_DIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(TARGETS_CMAKE "SboostTargets.cmake")
install(EXPORT sboost_targets
        FILE "${TARGETS_CMAKE}"
        DESTINATION "${CMAKE_INSTALL_DIR}")

set(CONFIG_CMAKE "SboostConfig.cmake")
set(BUILT_CONFIG_CMAKE "${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_CMAKE}")
configure_package_config_file("${CONFIG_CMAKE}.in" "${BUILT_CONFIG_CMAKE}"
        INSTALL_DESTINATION "${CMAKE_INSTALL_DIR}")
install(FILES "${BUILT_CONFIG_CMAKE}" DESTINATION "${CMAKE_INSTALL_DIR}")

set(CONFIG_VERSION_CMAKE "SboostConfigVersion.cmake")
set(BUILT_CONFIG_VERSION_CMAKE "${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_VERSION_CMAKE}")
write_basic_package_version_file("${BUILT_CONFIG_VERSION_CMAKE}"
        VERSION SBOOST_VERSION}
        COMPATIBILITY AnyNewerVersion)
install(FILES "${BUILT_CONFIG_VERSION_CMAKE}"
        DESTINATION "${CMAKE_INSTALL_DIR}")

# TEST
if(SBOOST_TEST)
    file(COPY "resources/testres" DESTINATION ${BUILD_OUTPUT_ROOT_DIRECTORY})
    include(Thirdparty)
    build_gtest()
    # Setup googletest
    # set(GTEST_PATH "third_party/googletest")
    # set(GTEST_SHARED_LIB ${GTEST_PATH}/lib/libgtest.a)
    # set(GTEST_MAIN_SHARED_LIB ${GTEST_PATH}/lib/libgtest_main.a)
    # set(GTEST_INCLUDE_DIR ${GTEST_PATH}/googletest/include)

    # message(${GTEST_SHARED_LIB})
    # message(${GTEST_MAIN_SHARED_LIB})

    # add_library(GTest::GTest STATIC IMPORTED)
    # set_target_properties(GTest::GTest
    #        PROPERTIES IMPORTED_LOCATION "${GTEST_SHARED_LIB}"
    #        INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIR}")

    # add_library(GTest::Main STATIC IMPORTED)
    # set_target_properties(GTest::Main
    #        PROPERTIES IMPORTED_LOCATION "${GTEST_MAIN_SHARED_LIB}"
    #        INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIR}")

    set(SBOOST_TEST_SRC
        bitmap_writer_test.cc
        byteutils_test.cc
        sboost_test.cc
        unpacker_test.cc
        encoding/rlehybrid_test.cc
        encoding/deltabp_test.cc)

    add_executable(sboost_all_test ${SBOOST_TEST_SRC})
    target_link_libraries(sboost_all_test PRIVATE sboost_static GTest::GTest GTest::Main pthread)
    target_compile_options(sboost_all_test PUBLIC ${SBOOST_SIMD_FLAGS})
endif()

# Benchmark

if(SBOOST_BENCHMARK)
    set(SBOOST_BENCHMARK_LINK_OPTION benchmark::benchmark benchmark::benchmark_main Threads::Threads
        sboost_static)

    add_executable(sboost_unpacker_benchmark unpacker_benchmark.cc)
    target_link_libraries(sboost_unpacker_benchmark PRIVATE ${SBOOST_BENCHMARK_LINK_OPTION})
    target_compile_options(sboost_unpacker_benchmark PUBLIC ${SBOOST_SIMD_FLAGS})
endif()
