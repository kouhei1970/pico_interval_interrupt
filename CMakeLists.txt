cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico_interval_interrupt C CXX ASM)
set(CMAKE_C_STNDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

pico_sdk_init()

add_executable(pico_interval_interrupt
  pico_interval_interrupt.c
)
target_link_libraries(pico_interval_interrupt hardware_spi pico_stdlib)

pico_enable_stdio_usb(pico_interval_interrupt 1)
pico_enable_stdio_uart(pico_interval_interrupt 0)

pico_add_extra_outputs(pico_interval_interrupt)

