cmake_minimum_required( VERSION 3.13)
include(pico_sdk_import.cmake)
project(Holamundo_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(Holamundo Holamundo.c ../ssd1306.c)

target_include_directories(Holamundo
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/../
)
pico_enable_stdio_usb(Holamundo 1)
pico_enable_stdio_uart(Holamundo 0)
pico_add_extra_outputs(Holamundo)
target_link_libraries(Holamundo pico_cyw43_arch_none pico_stdlib hardware_i2c )
