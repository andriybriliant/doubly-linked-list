cmake_minimum_required(VERSION 3.28)
project(doubly_linked_list C)

set(CMAKE_C_STANDARD 11)

add_executable(doubly_linked_list main.c
        doubly_linked.h
        doubly_linked.c)
