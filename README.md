# Library Management System

## Description
This Library Management System is a simple console application built using C that allows users to register, login, add, search, delete, view, issue, and return books. The system uses singly linked lists to manage books and stores user information in a file for persistence.

## Features
- **User Management**: Register and login system.
- **Book Management**: Add, search, delete, view, issue, and return books.
- **File Persistence**: Users are saved to a file (`users.dat`) for persistent storage.
- **Data Structures**: Utilizes singly linked lists for book management.

## Code Overview
### File Structure
- **`users.dat`**: Stores the list of users.
- **`libraryMgntSystem.c`**: The main C file that implements the Library Management System functionality.

### Key Functions
- **`registerUser()`**: Allows a new user to register by providing a username and password.
- **`loginUser()`**: Authenticates users by matching username and password.
- **`saveUsersToFile()`**: Saves the list of users to a file.
- **`loadUsersFromFile()`**: Loads users from a file.
- **`libraryMenu()`**: Displays the menu for the library system operations.
- **`addBook()`**: Adds a new book to the library.
- **`searchBook()`**: Searches for a book by its ID.
- **`deleteBook()`**: Deletes a book at any position by its ID.
- **`viewBooks()`**: Displays all books in the library in a tabular format.
- **`issueBook()`**: Marks a book as issued.
- **`returnBook()`**: Marks a book as returned.

### Usage
1. Compile the code using `gcc -o libraryMgntSystem libraryMgntSystem.c`.
2. Run the executable: `./libraryMgntSystem`.
3. Follow the on-screen prompts to register, login, and interact with the library system.

## Code File Details
- **`libraryMgntSystem.c`**: The provided C code that implements the above functionality.
- **`users.dat`**: Data file for user storage.

## Contributions
Contributions are welcome! Feel free to fork the repository, make improvements, and submit pull requests. If you have suggestions or issues, please open an issue or contact me.

## Contact
For any issues or feedback, please reach out to [mayurahire863@gmail.com].


