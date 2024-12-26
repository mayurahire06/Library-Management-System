#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char username[MAX];
    char password[MAX];
} User;

typedef struct Book {
    int id;
    char title[MAX];
    char author[MAX];
    int isIssued; // 0 = available, 1 = issued
    struct Book* next;
} Book;

User users[MAX];
int userCount = 0;

Book* books = NULL;

// Function prototypes
void registerUser();
int loginUser();
void saveUsersToFile();
void loadUsersFromFile();
void libraryMenu();
Book* addBook(Book* head, int id, char* title, char* author);
Book* searchBook(Book* head, int id);
Book* deleteBook(Book* head, int id);
void viewBooks(Book* head);
void issueBook(Book* head, int id);
void returnBook(Book* head, int id);

int main() {
    int choice, id;
    char title[MAX], author[MAX];

    loadUsersFromFile();

    printf("===== Library Management System =====\n");
    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                if (loginUser()) {
                    printf("\nLogin successful! Accessing Library System...\n");
                    libraryMenu();
                } else {
                    printf("\nInvalid username or password. Please try again.\n");
                }
                break;

            case 3:
                saveUsersToFile();
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

// Register a new user
void registerUser() {
    
    User newUser;

    printf("\nEnter username: ");
    scanf("%s", newUser.username);
    
    printf("Enter password: ");
    scanf("%s", newUser.password);

    // Check if username already exists
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Try a different one.\n");
            return;
        }
    }

    // Add new user to the database
    users[userCount++] = newUser;
    printf("Registration successful!\n");
}

// Login a user
int loginUser() {
    char username[MAX];
    char password[MAX];

    printf("\nEnter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Login successful
        }
    }
    return 0; // Login failed
}

// Save users to a file
void saveUsersToFile() {
    FILE *file = fopen("users.dat", "wb");
    if (!file) {
        perror("Error opening file for saving users");
        return;
    }
    fwrite(&userCount, sizeof(int), 1, file);
    fwrite(users, sizeof(User), userCount, file); 
    fclose(file);
}

// Load users from a file
void loadUsersFromFile() {
    FILE *file = fopen("users.dat", "rb");
    if (!file) {
        return; // File doesn't exist yet, no users to load
    }
    fread(&userCount, sizeof(int), 1, file); 
    fread(users, sizeof(User), userCount, file); 
    fclose(file);
}

// Library menu
void libraryMenu() {
    int choice, id;
    char title[MAX], author[MAX];

    while (1) {
        printf("\n=== Library Management Menu ===\n");
        printf("1. Add Book\n2. Search Book\n3. Delete Book\n");
        printf("4. View All Books\n5. Issue Book\n6. Return Book\n7. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                getchar(); // Clear newline from buffer
                printf("Enter Book Title: ");
                fgets(title, MAX, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove trailing newline
                
                printf("Enter Book Author: ");
                fgets(author, MAX, stdin);
                author[strcspn(author, "\n")] = '\0';
                books = addBook(books, id, title, author);
                break;

            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                Book* book = searchBook(books, id);
                if (book) {
                    printf("\n=====================================================================\n");
                    printf("| %-5s | %-20s | %-20s | %-10s |\n", "ID", "Title", "Author", "Status");
                    printf("=====================================================================\n");
                    printf("| %-5d | %-20s | %-20s | %-10s |\n", book->id, book->title, book->author, book->isIssued ? "Issued" : "Available");      
                    printf("=====================================================================\n");
                } else {
                    printf("Book not found.\n");
                }
                break;

            case 3:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                books = deleteBook(books, id);
                break;

            case 4:
                viewBooks(books);
                break;

            case 5:
                printf("Enter Book ID to issue: ");
                scanf("%d", &id);
                issueBook(books, id);
                break;

            case 6:
                printf("Enter Book ID to return: ");
                scanf("%d", &id);
                returnBook(books, id);
                break;
                
            case 7:
                printf("Logging out...\n");
                return; // Go back to main menu

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a book to the library
Book* addBook(Book* head, int id, char* title, char* author) {

    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        printf("Memory allocation failed. Could not add book.\n");
        return head;
    }

    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->isIssued = 0; // Default: not issued
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } 
    else {
        Book* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }

    printf("Book added successfully!\n");
    return head;
}

// Function to search for a book by ID
Book* searchBook(Book* head, int id) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Not found
}

// Function to delete a book by ID
Book* deleteBook(Book* head, int id) {
    if (head == NULL) {
        printf("Book list is empty.\n");
        return head;
    }
    if (head->id == id) {
        Book* temp = head;
        head = head->next;
        free(temp);
        printf("Book deleted successfully.\n");
        return head;
    }
    Book* current = head;
    while (current->next != NULL && current->next->id != id) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Book not found.\n");
    } else {
        Book* temp = current->next;
        current->next = current->next->next;
        free(temp);
        printf("Book deleted successfully.\n");
    }
    return head;
}

// Function to view all books in the library in tabular format
void viewBooks(Book* head) {
    if (head == NULL) {
        printf("No books available.\n");
        return;
    }
    printf("\n=====================================================================\n");
    printf("| %-5s | %-20s | %-20s | %-10s |\n", "ID", "Title", "Author", "Status");
    printf("=====================================================================\n");
    Book* current = head;
    while (current != NULL) {
        printf("| %-5d | %-20s | %-20s | %-10s |\n", current->id, current->title, current->author, current->isIssued ? "Issued" : "Available");
        current = current->next;
    }
    printf("=====================================================================\n");
}

// Function to issue a book
void issueBook(Book* head, int id) {
    Book* book = searchBook(head, id);
    if (book == NULL) {
        printf("Book not found.\n");
        return;
    }
    if (book->isIssued) {
        printf("Book is already issued.\n");
    } else {
        book->isIssued = 1;
        printf("Book issued successfully.\n");
    }
}

// Function to return a book
void returnBook(Book* head, int id) {
    Book* book = searchBook(head, id);
    if (book == NULL) {
        printf("Book not found.\n");
        return;
    }
    if (!book->isIssued) {
        printf("Book is already returned.\n");
    } else {
        book->isIssued = 0;
        printf("Book returned successfully.\n");
    }
}
