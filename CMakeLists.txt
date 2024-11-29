cmake_minimum_required(VERSION 3.28)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
project(SDL_test)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-fPIC")
add_compile_options(-ggdb -O0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
# add_library(${PROJECT_NAME} src/lib.cpp)


add_executable(${PROJECT_NAME} src/main.cpp src/TestScene2.cpp src/TestScene1.cpp Engine/Gameobject/src/Component.cpp)
add_subdirectory(Engine)

target_link_libraries(${PROJECT_NAME} PRIVATE Engine )
 
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

