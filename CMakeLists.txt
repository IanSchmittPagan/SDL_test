cmake_minimum_required(VERSION 3.16)

project(SDL_test)

find_package(SDL3 REQUIRED CONFIG)

find_package(SDL3_ttf REQUIRED CONFIG)

add_executable(SDL_test main.cpp)

target_link_libraries(SDL_test PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)
