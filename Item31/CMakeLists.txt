cmake_minimum_required(VERSION 3.10)
project(effective_cpp_3rd)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_subdirectory(HandlePerson)
add_subdirectory(InterfacePerson)

add_executable(main main.cpp)

#target_link_libraries(main PUBLIC handlePerson)
target_link_libraries(main PUBLIC interfacePerson)

#target_include_directories(main PUBLIC
#                           "${PROJECT_SOURCE_DIR}/HandlePerson"
#                          )

target_include_directories(main PUBLIC
                           "${PROJECT_SOURCE_DIR}/InterfacePerson"
                          )