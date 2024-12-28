cmake_minimum_required(VERSION 3.28)
project(cane LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # To debug linker errors.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GEN_FILE ${CMAKE_SOURCE_DIR}/src/lex.yy.cc)

list(APPEND SOURCE_FILES
    src/main.cc
    ${GEN_FILE}
)

set(FLEX_FILE ${CMAKE_SOURCE_DIR}/include/cane.lpp)

add_custom_command(
    OUTPUT ${GEN_FILE}
    COMMAND flex -o ${GEN_FILE} ${FLEX_FILE}
    COMMAND bash ${CMAKE_SOURCE_DIR}/lib/scripts/trim_gen.sh
    COMMAND mv ${CMAKE_SOURCE_DIR}/build/lex.hh ${CMAKE_SOURCE_DIR}/include/
    DEPENDS ${FLEX_FILE}
    COMMENT "Running flex. Removing the garbage redefined yyflex() definitions :{"
)

add_executable(cane ${SOURCE_FILES})
target_include_directories(cane PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(${PROJECT_NAME} PRIVATE fl)
