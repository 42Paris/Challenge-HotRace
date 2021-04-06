cmake_minimum_required(VERSION 3.17)
project(Challenge_Hotrace)

set(CMAKE_CXX_STANDARD 11)
include_directories(ft_containers)
include_directories(getnextline/include)
include_directories(libft/include)

add_executable(hotrace
        srcs/main.cpp
        )
