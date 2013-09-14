cmake_minimum_required(VERSION 2.8)
project(cpp-test CXX)

################################################################################
# GTest
################################################################################

include(ExternalProject)
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/vendor)

ExternalProject_Add(
    googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    SVN_REVISION -r HEAD
    TIMEOUT 10
    # Skip update step
    UPDATE_COMMAND ""
    # Skip install step
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
)

ExternalProject_Get_Property(googletest binary_dir)
ExternalProject_Get_Property(googletest source_dir)
include_directories(${source_dir}/include)

################################################################################
# Unit Tests
################################################################################

file(GLOB sources *.h *.cc *.cxx *.cpp *.hxx)
add_executable(main ${sources})
add_dependencies(main googletest)
add_custom_target(test COMMAND main)
set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(
    main
    ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
    ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
)
