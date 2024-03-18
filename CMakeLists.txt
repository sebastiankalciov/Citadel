cmake_minimum_required(VERSION 3.27)
project(Citadel C)

set(CMAKE_C_STANDARD 11)

add_executable(Citadel
        source/authentification/login.c
        source/authentification/register.c
        source/loans/borrow.c
        source/loans/returnBook.c)
