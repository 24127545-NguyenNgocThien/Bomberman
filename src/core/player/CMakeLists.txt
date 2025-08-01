add_library(player_lib STATIC
    player.cpp
    player.h
)

target_include_directories(player_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../
)
