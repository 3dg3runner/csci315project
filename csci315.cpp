/*
 * Program: CSCI 315 - Library Management System - Group Project
 * Purpose: This program will implement a system to manage book records with features like searching, adding, and deleting books.
 * Developers for this part: nathalie baladejo-reynosa and Samuel Johnson
 * Creation Date: April 12, 2025
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std; // Use namespace std

// Start of Samuel's code
// Structure to represent a book
struct Book {
    int bookID;
    string title;
    string author;
    Book* next; // Pointer to the next book in the linked list
};


// Class for Library System
class librarySystem {
private:
    Book* head; // Head pointer for the linked list
public:
    librarySystem() : head(nullptr) {}


    // Function to display all books
    void displayBooks() {
        Book* current = head;
        if (current == nullptr) {
            cout << "No books in the library." << endl;
            return;
        }
        while (current != nullptr) {
            cout << "Book ID: " << current->bookID
                 << ", Title: " << current->title
                 << ", Author: " << current->author << endl;
            current = current->next;
        }
    }
}; // End of Samuel's code


// Program main
int main()
{
    // Declare variables
   /*
   MENU

REPEAT
    DISPLAY "1. Add Book"
    DISPLAY "2. Search Book"
    DISPLAY "3. Delete Book"
    DISPLAY "4. Display All Books"
    DISPLAY "5. Exit"
    READ choice

    SWITCH choice
        CASE 1:
            READ bookID, title, author
            Library.AddBook(bookID, title, author)
        CASE 2:
            READ bookID
            result = Library.SearchBook(bookID)
            PRINT result
        CASE 3:
            READ bookID
            Library.DeleteBook(bookID)
        CASE 4:
            Library.DisplayBooks()
        CASE 5:
            EXIT
    END SWITCH
UNTIL FALSE
*/

// Start of nathalie's code
// Declare variables
int choice;
librarySystem library;
int bookID;
string title, author;
bool result;
string filePath;
    

// While loop
while (true)
{
    // Prompt user for input

    cout << "\nWelcome to Library Management System\n"
        "Select a choice from the menu below\n"
        "1 : Add Book\n"
        "2 : Search Book and Where in Library?\n"
        "3 : Delete Book\n"
        "4 : Display All Books\n"
        "5 : Remaining Book Space\n"
        "6 : Create library from text file\n"
        "7 : Print library from text file\n"
        "0 : Exit\n";
    cout << "Enter a choice please: ";
    cin >> choice;

    // Start of Samuel's code
    // Error Check
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
            continue;
        } // End of Samuel's code


    // Begin switch statement
    switch (choice)
    {
    // Case 1 - Add Book 
    case 1:
        cout << "Enter book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        librarySystem.addBook(bookID, title, author);
        cout << "Book added!\n";
        break;
    
    // Case 2 - Search Book and Where in Library?
    case 2:
        cout << "Enter book ID: ";
        cin >> bookID;
        result = librarySystem.searchBook(bookID);
        if (result == true)
            cout << "The book " << " is in the library."  << endl;
        else
            cout << "The book " << " is not in the library."  << endl;
        cout << "Provide book title to find shelf and row in the library: ";
        cin.ignore();
        getline(cin, title);
        librarySystem.where(title);
    // Case 3 - Delete Book
    case 3:
        cout << "Enter book ID: ";
        cin >> bookID;
        librarySystem.deleteBook(bookID);
        cout << "Book deleted!\n";
        break;
    // Case 4 - Display All Books 
    case 4:
        cout << "Printing all books..." << endl;
        librarySystem.displayBooks();
        break;
    // Case 5 - Remaining Book Space
    case 5:
        librarySystem.freeShelfSpace();
        break;
    case 6:
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
        cout << "What file would you like to create this library from? ";
        getline(cin, filePath);
        cin.ignore();
        librarySystem.fileRead(filePath); // Evan's code
        break;
    case 7:
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
        cout << "What file would you like to print this library from? ";
        getline(cin, filePath);
        cin.ignore();
        librarySystem.filePrint(filePath); // Evan's code
        break;
    case 0:
        cout << "Bye-bye for now!" << endl
             << endl;
        return 0;
        break;
    // Let user know it's invalid input
    default:
        cout << "That is not a valid input, sorry!" << endl;
    }

}

    return 0; // Indicate successful program termination
}// End of nathalie's code
