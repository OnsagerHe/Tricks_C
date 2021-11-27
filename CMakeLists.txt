cmake_minimum_required(VERSION 3.20)
project(Tricks_C C)

include_directories(include)

set(CMAKE_C_STANDARD 11)

add_compile_options(-fexceptions -Wall -Wextra -Werror -g  )

add_executable(tricks main.c
        source/link_list.c
        source/bitshift.c)