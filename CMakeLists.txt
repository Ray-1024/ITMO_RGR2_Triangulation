cmake_minimum_required(VERSION 3.22)
project(RGR2)

set(CMAKE_CXX_STANDARD 17)
#set(SFML_STATIC_LIBRARIES TRUE)
#set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system graphics REQUIRED)

add_executable(RGR2 main.cpp Application.cpp Application.h Polygon.cpp Polygon.h)
target_link_libraries(RGR2 sfml-graphics sfml-system)
