add_library(handlePerson ../common_func/address.cpp ../common_func/date.cpp Person.cpp PersonImpl.cpp)

target_include_directories(handlePerson PUBLIC
        "${PROJECT_SOURCE_DIR}/common_func"
        )