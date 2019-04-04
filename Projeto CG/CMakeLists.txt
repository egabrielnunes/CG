cmake_minimum_required(VERSION 3.13)
project(Projeto_CG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

link_directories(/Users/gabrielnunes/Downloads/SFML-2.5.1-macos-clang/lib)

add_executable(Projeto_CG
        CMakeLists.txt
        includes.h
        main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(Projeto_CG ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "/usr/local/Cellar/sfml/2.5.1/lib/cmake/sfml")

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)
target_link_libraries(Projeto_CG sfml-graphics)