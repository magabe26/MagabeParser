include(config.cmake)

cmake_minimum_required(VERSION 3.17)
cmake_policy(VERSION 3.17)

project(magabe_parser CXX)

add_subdirectory(core)
add_subdirectory(parsers)

get_filename_component(PROJECT_CURRENT_DIR "./.." ABSOLUTE)
set(magabe_parser-parsers_DIR  "${PROJECT_CURRENT_DIR}/magabe_parser-parsers-${CMAKE_BUILD_TYPE}" )
list(APPEND CMAKE_PREFIX_PATH "${magabe_parser-parsers_DIR}/lib/cmake")

find_package(magabe_parser-parsers 1.0 REQUIRED)
find_package(magabe_parser-core 1.0 REQUIRED)

add_executable(parser)

target_sources(parser
    PRIVATE
    main.cpp
    )

target_link_libraries(parser
    PUBLIC
    magabe_parser-parsers::magabe_parser-parsers
    )
