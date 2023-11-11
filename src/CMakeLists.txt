cmake_minimum_required(VERSION 3.13)

project(parser-with-c VERSION 0.1.0 LANGUAGES C)
add_executable(main main.c node.c parser.c scanner.c token.c)
set_property(TARGET main PROPERTY C_STANDARD 11)
