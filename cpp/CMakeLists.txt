cmake_minimum_required(VERSION 2.8)
project(Cpp-Test)

################################
# GTest
################################

include(ExternalProject)
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

ExternalProject_Add(
    googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    SVN_REVISION -r HEAD
    TIMEOUT 10
    # Skip update step
    UPDATE_COMMAND ""
    # Skip install step
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

ExternalProject_Get_Property(googletest source_dir)
include_directories(${source_dir}/include)

################################
# Unit Tests
################################

add_executable(MainTest ${PROJECT_SOURCE_DIR}/main.cpp)

################################
# Dependencies
################################

add_dependencies(MainTest googletest)
ExternalProject_Get_Property(googletest binary_dir)
target_link_libraries(MainTest
                      ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
                      ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX})
