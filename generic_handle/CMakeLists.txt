cmake_minimum_required(VERSION 3.10)
project(effective_cpp_3rd)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(book)

add_executable(main sales.cpp)

target_link_libraries(main PUBLIC book)

target_include_directories(main PUBLIC
                           "${PROJECT_SOURCE_DIR}/book"
                          )