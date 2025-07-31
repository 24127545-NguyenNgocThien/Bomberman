# Core components
add_subdirectory(core/map)
add_subdirectory(core/player)
add_subdirectory(core/bomb)
add_subdirectory(core/item)

add_subdirectory(ui)
add_subdirectory(controller)

# Main executable
add_executable(Bomberman main.cpp)
target_link_libraries(Bomberman PRIVATE
    controller_lib
    raylib
)

# Windows: link hệ thống cho raylib
if (WIN32)
    target_link_libraries(Bomberman PRIVATE
        winmm
        gdi32
        opengl32
        # user32
        # shell3
    )
endif()

target_compile_definitions(Bomberman PRIVATE
    RESOURCES_PATH="${RESOURCES_PATH}"
)
