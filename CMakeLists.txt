cmake_minimum_required(VERSION 3.22)
project(ayp2_templates)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wconversion)

set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)

add_executable(ayp2_templates
        main.cpp
        include/selection.hpp
        include/matriz.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")