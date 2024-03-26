cmake_minimum_required(VERSION 2.8)

project(rpsg)

set(SRC_EXEC main.cpp lexer.cpp eval.cpp wsave.cpp)

add_executable(main ${SRC_EXEC})