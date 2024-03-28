cmake_minimum_required(VERSION 2.8)

project(rpsg)

set(EVAL_STACK_MAX_SIZE 1024)

add_compile_definitions(MAX_STACK_DEPTH=${EVAL_STACK_MAX_SIZE})
set(SRC_EXEC main.cpp lexer.cpp eval.cpp wsave.cpp)

add_executable(main ${SRC_EXEC})