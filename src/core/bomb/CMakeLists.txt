add_library(bomb_lib STATIC
    bomb.cpp
    bomb.h
)
target_include_directories(bomb_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../
)
