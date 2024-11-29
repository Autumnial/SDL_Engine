set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
add_executable(Test-Math src/test.cpp)
add_library(Math INTERFACE)

target_include_directories(Math INTERFACE .)

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
