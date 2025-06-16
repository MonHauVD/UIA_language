cmake_minimum_required(VERSION 3.10)
project(UIACompiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Thêm đường dẫn tới thư mục nguồn
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Liệt kê các file nguồn
set(SOURCES
    ${SOURCE_DIR}/uia_main.cpp
    ${SOURCE_DIR}/uia_preprocessor.cpp
    ${SOURCE_DIR}/uia_compiler.cpp
)
add_executable(uia_compiler ${SOURCES})

target_include_directories(uia_compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Thêm cấu hình cho UIA
add_definitions(-DUIA_LANGUAGE)
target_compile_definitions(uia_compiler PRIVATE UIA_LANGUAGE)
target_compile_options(uia_compiler PRIVATE -include${CMAKE_CURRENT_SOURCE_DIR}/uia_library.h)
