set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
add_library(Components src/Transform.cpp src/Sprite.cpp src/Text.cpp
                       src/Collider.cpp)
target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_include_directories(Gameobject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(Test-Gameobject
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(Components PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(Components PUBLIC ${CMAKE_SOURCE_DIR}/Engine/src)
target_include_directories(Components PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_include_directories(Components
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../Math/src)

target_link_libraries(Components SDL2_image)
