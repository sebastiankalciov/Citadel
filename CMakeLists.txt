cmake_minimum_required(VERSION 3.27)
project(Citadel C)

set(CMAKE_C_STANDARD 11)

add_executable(Citadel
        source/authentification/login/login.c
        source/authentification/register/register.c
        source/loans/borrow/borrow.c
        source/loans/return/return.c
        source/main.c
        source/authentification/login/login.h
        source/templates/templates.h
        source/loans/return/return.h
        source/loans/donate/donate.h
        source/loans/borrow/borrow.h
        source/authentification/register/register.h
        source/menu/menu.h
        source/menu/menu.c
        source/utils/files/utils.h
        source/utils/files/utils.c
        source/authentification/auth.h
        source/authentification/auth.c
        source/utils/utils.h
        source/utils/utils.c
        source/utils/authentification/utils.c
        source/utils/authentification/utils.h
        source/loans/donate/donate.c)
