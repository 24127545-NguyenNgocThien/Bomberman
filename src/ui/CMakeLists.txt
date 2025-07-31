add_library(ui_lib STATIC
    ui.cpp
    ui.h
)

target_include_directories(ui_lib PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
)

target_link_libraries(ui_lib PRIVATE
    map_lib
    player_lib
    bomb_lib
    item_lib
    raylib
)

if (WIN32)
    target_link_libraries(ui_lib PRIVATE
        winmm
        gdi32
        opengl32
        # user32
        # shell3
    )
endif()
