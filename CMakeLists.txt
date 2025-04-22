cmake_minimum_required(VERSION 3.16)
project(MyFolks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Nájdi SDL2 a SDL2_image
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})

# Zdroje
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Build
add_executable(MyFolks ${SOURCES})

# Link knižníc
target_link_libraries(MyFolks ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
