/*
 * Program: CSCI 315 - Library Management System - Group Project
 * Purpose: This program will implement a system to manage book records with features like searching, adding, and deleting books.
 * Developer for this part: nathalie baladejo-reynosa
 * Creation Date: April 12, 2025
 */
#include <iostream> // Include necessary libraries
#include <iomanip>
using namespace std; // Use namespace std

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
bookType library;
int bookID;
string title, author;
bool result;

// While loop
while (true)
{
    // Prompt user for input

    cout << "\nWelcome to Library Management System\n"
        "Select a choice from the menu below\n"
        "1 : Add Book\n"
        "2 : Search Book\n"
        "3 : Delete Book\n"
        "4 : Display All Books\n"
        "0 : Exit\n";
    cout << "Enter a choice please: ";
    cin >> choice;

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
        library.addBook(bookID, title, author);
        cout << "Book added!\n";
        break;
    
    // Case 2 - Search Book
    case 2:
    cout << "Enter book ID: ";
    cin >> bookID;
    result = library.SearchBook(bookID);
    if (result == true)
        cout << "The book " << " is in the list."  << endl;
    else
        cout << "The book " << " is not in the list."  << endl;
    // Case 3 - Delete Book
    case 3:
        cout << "Enter book ID: ";
        cin >> bookID;
        library.deleteBook(bookID);
        cout << "Book deleted!\n";
        break;

    // Case 4 - Display All Books 
    case 4:
        cout << "Printing all books..." << endl;
        library.DisplayBooks();
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
