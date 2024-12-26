# Library Management System

## Description
This Library Management System is a simple console application built using C that allows users to register, log in, add, search, delete, view, issue, and return books. The system uses linked lists to manage books and stores user information in a file for persistence.

## Features
- **User Management**: Register and login system.
- **Book Management**: Add, search, delete, view, issue, and return books.
- **File Persistence**: Users are saved to a file (`users.dat`) for persistent storage.
- **Data Structures**: Utilizes linked lists for book management.

## Code Overview
### File Structure
- **`users.dat`**: Stores the list of users.
- **`library.c`**: The main C file that implements the Library Management System functionality.

### Key Functions
- **`registerUser()`**: Allows a new user to register by providing a username and password.
- **`loginUser()`**: Authenticates users by matching username and password.
- **`saveUsersToFile()`**: Saves the list of users to a file.
- **`loadUsersFromFile()`**: Loads users from a file.
- **`libraryMenu()`**: Displays the menu for the library system operations.
- **`addBook()`**: Adds a new book to the library.
- **`searchBook()`**: Searches for a book by its ID.
- **`deleteBook()`**: Deletes a book by its ID.
- **`viewBooks()`**: Displays all books in the library in a tabular format.
- **`issueBook()`**: Marks a book as issued.
- **`returnBook()`**: Marks a book as returned.

### Usage
1. Compile the code using `gcc -o library library.c`.
2. Run the executable: `./library`.
3. Follow the on-screen prompts to register, login, and interact with the library system.

### Example Interaction

## Code File Details
- **`library.c`**: The provided C code that implements the above functionality.
- **`users.dat`**: Data file for user storage.

## Contact
For any issues or feedback, please reach out to [Your Email].

---

Replace `[Your Email]` with your actual email address if needed.

