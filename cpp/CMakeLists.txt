cmake_minimum_required(VERSION 2.8)

file(GLOB sources *.h *.c *.cxx *.cpp *.cc *.hxx)
add_executable(exercise-cpp ${sources})
