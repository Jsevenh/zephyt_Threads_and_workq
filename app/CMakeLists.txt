cmake_minimum_required(VERSION 3.24.2)

set(project_name multi_thread)
project(${project_name}  VERSION 1.0)

set(BOARD rpi_pico)
 find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

target_sources(app PRIVATE  src/main.c  src/threads.c)

