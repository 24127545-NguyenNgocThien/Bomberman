add_library(map_lib STATIC
    map.cpp
    map.h
)

target_compile_definitions(map_lib PUBLIC
    RESOURCES_PATH="${RESOURCES_PATH}"
)

target_include_directories(map_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
