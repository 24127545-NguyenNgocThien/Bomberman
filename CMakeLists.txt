cmake_minimum_required(VERSION 3.10)
project(Bomberman)

# Thiết lập chuẩn C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Thư viện Raylib
add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libraylib.a
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/lib
)

# Đặt đường dẫn tới thư mục resources (tương đối hoặc tuyệt đối)
set(RESOURCES_PATH "${CMAKE_SOURCE_DIR}/assets" CACHE INTERNAL "")

# Thêm thư mục source
add_subdirectory(src)
