# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required ( VERSION 3.15 )

project(Wolf3d C)
set(CMAKE_C_STANDARD 99)
set(SDL_LIBRARY includes/SDL2-2.0.12/lib/x64)
set(SDL_INCLUDE_DIR includes/SDL2-2.0.12/include)
find_package(SDL REQUIRED)

include_directories(includes)
add_executable(Wolf3d sources/main.c sources/LoadData.c sources/UnloadData.c sources/vline.c sources/MovePlayer.c sources/DrawScreen.c)
