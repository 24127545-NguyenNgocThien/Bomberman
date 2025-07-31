add_library(controller_lib STATIC
    game.cpp
    game.h
)

target_include_directories(controller_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../ui
    # ${CMAKE_CURRENT_SOURCE_DIR}/../core/bomb
    # ${CMAKE_CURRENT_SOURCE_DIR}/../core/player
    # ${CMAKE_CURRENT_SOURCE_DIR}/../core/item
    # ${CMAKE_CURRENT_SOURCE_DIR}/../core/map
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
)

target_link_libraries(controller_lib PRIVATE
    ui_lib
    map_lib
    player_lib
    bomb_lib
    item_lib
)
