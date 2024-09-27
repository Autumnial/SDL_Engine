add_library(Engine  src/Game.cpp src/Timer.cpp src/Scene.cpp src/Input.cpp )

add_subdirectory(Math)
target_link_libraries(Engine PUBLIC SDL2 SDL2_ttf)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src) 
