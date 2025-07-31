add_library(item_lib STATIC
    item.cpp
    item.h
)

target_include_directories(item_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
