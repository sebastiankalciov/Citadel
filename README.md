# Citadel - Library Management System

## Current functionalities

### Header
![img.png](meta/img.png)

### Menu
![img.png](meta/img2.png)

### Borrow System
![img.png](meta/img3.png)

### Loans
![img.png](meta/img4.png)

- [x] Authentification System
    - Login (first name, last name) from the menu
    - Register (create a new account) from the menu

- [x] Borrow System
    - Borrow a book from the menu as follows:
        - Books are printed on the screen
        - User selects a book
        - User selects the amount of copies
        - New loan created
        - User happy

- [ ] Donation System
    - Donate a book to the library from the menu as follows:
        - Requests details about the book from the user
        - Checks the details
        - Add the book in the library
        - User happy
        - Library happy
      
- [x] Display all books from the library
- [x] Display all the loans of the user
- [ ] Search for a book

## Requirements (class)
Each person can borrow multiple books from a library. \
Each person is uniquely identified by their NAME and SURNAME. \
Every book contains information regarding its:
- Title
- Author
- Copies available
- For each loan, a document containing relevant information will be generated:
    - Which person borrowed the books
    - The books borrowed:
        - Title + Author
        - Copies borrowed

Any person can see all the loans that they made. \
Furthermore, ANY person can search the library for a
specific book (by its title or author). \
Any person can return the books that they borrowed, or they can
donate new books to the library.

## Functionalities:
- LOGIN (from the command line)
    - By using the arguments login [NAME] [SURNAME]
    - 1.5pt are granted, as follows:
        - 0.75pct for parsing the command line arguments
        - 0.75pct for gathering the loans made by the person

- BORROW BOOKS
    - From the menu, can be done as long as the library has all the books requested
    - 1.5pt are granted

- RETURN / DONATE BOOKS
    - From the menu
    - 1.5pt are granted, as follows:
        - 0.75pct return borrowed books
        -  0.75pct donate new books

- VIEW LOANS
    - From the menu
    - 1.5pt are granted

- SEARCH FOR BOOKS
    - From the menu
    - 1.5pt are granted, as follows:
        - 0.75pct search by title or author
        - 0.75pct search by any combination (TITLE / AUTHOR / TITLE +
          AUTHOR)