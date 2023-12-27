add_library(interfacePerson ../common_func/address.cpp ../common_func/date.cpp AsiaPerson.cpp Person.cpp)

target_include_directories(interfacePerson PUBLIC
        "${PROJECT_SOURCE_DIR}/common_func"
        )