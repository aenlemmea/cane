cmake_minimum_required(VERSION 3.28)
project(cane LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # To debug linker errors.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND SOURCE_FILES
    include/lex.Cane_.cc
    src/main.cc
)

add_executable(cane ${SOURCE_FILES})
target_include_directories(cane PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(${PROJECT_NAME} PRIVATE fl)
