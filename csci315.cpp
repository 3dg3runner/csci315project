/*
 * Program: CSCI 315 - Library Management System - Group Project
 * Purpose: This program will implement a system to manage book records with features like searching, adding, and deleting books.
 * Developers for this part:  Evan Palermo, nathalie baladejo-reynosa and Samuel Johnson
 * Creation Date: April 12, 2025
 * Updated date: April 24, 2025
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
// Modified by Evan Palermo - Start of Samuel's code
// Structure to represent a book
struct book
{
    string title;
    string author;
    string bookID:
};


// Class for Library System
class librarySystem
{
private:
    Book *head; // Head pointer for the linked list
public:
    librarySystem() : head(nullptr) {}

    // Function to display all books
    void displayBooks()
    {
        Book *current = head;
        if (current == nullptr)
        {
            cout << "No books in the library." << endl;
            return;
        }
        while (current != nullptr)
        {
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

    // Start of Evan's code
    const string PASSWORD = "CSCI-315";
    const int BOOKLIMIT = 3;

    // Start of nathalie's code
    // Declare variables
    int choice;
    librarySystem library;
    int bookID;
    string title, author;
    bool result;
    string filePath;
    string receiptFilePath;
    bool exit1 = false, exit2 = false; // Evan's code
    string passwd;                     // Evan's code

    // Start of Evan's code
    // Have a constant file paths
    filePath = "library.txt";
    receiptFilePath = "receipt.txt";
    // End of Evan's code

    // Do while loop
    do
    {
        // Prompt user for input

        cout << "\nWelcome to Library Management System\n" // Start of Evan's code
                "Select a choice from the menu below\n"
                "1 : Check out Book\n"
                "2 : Return Book\n"
                "3 : Search Book\n"
                "4 : Display All Books\n"
                "5 : Managerial Settings\n";
        "0 : Exit\n";
        cout << "Enter a choice please: ";
        cin >> choice; // End of Evan's code

        // Start of Samuel's code
        // Error Check
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
            continue;
        } // End of Samuel's code

        // Begin switch statement
        switch (choice)
        {
        // Case 1 - Check out Book
        case 1:
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            library.deleteBook(title);
            receiptPrint(book a[BOOKLIMIT]); // Evan's code
            break;
        // Case 2 - Return a Book
        case 2:
            cout << "Enter book ID: ";
            cin >> bookID;
            cin.ignore();
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            library.addBook(bookID, title, author);
        // Case 3 - Search a Book
        case 3:
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            result = library.searchBook(title);
            if (result == true)
                cout << "The book " << " is in the library." << endl;
            else
                cout << "The book " << " is not in the library." << endl;
            library.where(title);
            break;
        // Case 4 - Display All Books
        case 4:
            cout << "Printing all books..." << endl;
            library.displayBooks();
            break;
        // Case 5 - Managerial Settings // Start of Evan's code
        case 5:
            exit2 = false;
            cout << "Password: ";
            cin >> passwd;
            if (passwd != PASSWORD)
            {
                cout << "Entry denied. Wrong password!";
                return 0;
            } // End of Evan's code
            do
            {
                // Prompt user for input

                cout << "\nManagerial Settings\n"
                        "Select a choice from the menu below\n"
                        "1 : Add Book\n"
                        "2 : Delete Book\n"
                        "3 : Remaining Shelf Space\n"
                        "0 : Exit\n";
                cout << "Enter a choice please: ";
                cin >> choice;

                switch (choice)
                {
                // Case 1 - Read/Create library from text file
                case 1:
                    library.fileRead(filePath); // Evan's code
                    break;
                // Case 2 - Print library from text file
                case 2:
                    library.filePrint(filePath); // Evan's code
                    break;
                 // Case 3 - Remaining Book Space
                case 3:
                    library.freeShelfSpace();
                    break;

                case 0:
                    cout << "Bye-bye for now!" << endl
                         << endl;
                    exit2 = true;
                    break;
                // Let user know it's invalid input
                default:
                    cout << "That is not a valid input, sorry!" << endl;
                    break;
                }
            } while (!exit2);
        case 0:
            cout << "Bye-bye for now!" << endl
                 << endl;
            exit2 = true;
            break;
        // Let user know it's invalid input
        default:
            cout << "That is not a valid input, sorry!" << endl;
            break;
        }
        while (!exit1); //

        return 0; // Indicate successful program termination
    } // End of nathalie's code
