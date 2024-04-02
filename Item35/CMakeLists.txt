cmake_minimum_required(VERSION 3.10)
project(effective_cpp_3rd)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(GameCharacter)

add_executable(main classic_strategy_pattern_main.cpp)

target_link_libraries(main PUBLIC GameCharacter)

target_include_directories(main PUBLIC
                           "${PROJECT_SOURCE_DIR}/GameCharacter"
                          )