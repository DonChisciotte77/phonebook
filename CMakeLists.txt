cmake_minimum_required(VERSION 3.17)
project(phonebook C)

set(CMAKE_C_STANDARD 99)

add_library(ADT phonebook.c phonebook.h)
add_library(UI ui.c ui.h)

add_executable(phonebook main.c)

target_link_libraries(phonebook PRIVATE ADT UI)