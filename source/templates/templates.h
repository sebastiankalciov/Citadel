#pragma once

typedef struct User{
    int userId;
    char* firstName;
    char* lastName;

}User;

typedef struct Book{
    int bookId, copies;
    char* title;
    char* author;
}Book;
