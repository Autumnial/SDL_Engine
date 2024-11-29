set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
add_library(Gameobject src/Gameobject.cpp)
add_executable(Test-Gameobject src/Component.cpp src/test.cpp
                               src/Gameobject.cpp)
add_subdirectory(Components)

target_link_libraries(Gameobject PUBLIC Components)
target_link_libraries(Test-Gameobject PUBLIC Components)

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
