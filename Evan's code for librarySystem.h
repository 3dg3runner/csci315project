/*
Author: Evan Palermo
Created on: 4/18/2025
Modified on: 4/21/2025

NOTE: I cannot compile this until the operator overloading is done,
        so there will most likely be a whole lot of bugs, but
        this is to be a more concrete idea of what we have to use
*/


#ifndef H_LibrarySystem //Start - Made by Evan Palermo
#define H_LibrarySystem

#include <iostream>
#include <string>
#include <fstream>
#include "book.h"
#include "orderedLinkedList.h"
#include "linkedListIterator.h"

const int SHELVES = 5;          //5 book shelves
const int ROWS = 3;             //3 rows tall
const int LENGTH = 10;          //10 books long

using namespace std;

class librarySystem: public orderedLinkedList<book>
{
public:
        //extPersonType had operators ==. >, >=, and << overloaded, will probably need something like this
        void fileRead(string fileName);
        //inspired by my addressBookType.loadDisk() function

        void filePrint(string filename);
        //inspired by my addressBookType.writeDisk() function

        //displayBooks - there is already a print() function in linkedListType which this
        //inherits through orderedLinkedList so we need to overload the << instead of a
        //new member function.

        void addBook(string title, string author, string bookID);
        //acts as a book return

        void deleteBook(string title);
        //acts as a book check out

        void where(string title);
        //finds what book shelf and what row a book is stored on.
        //does not find the book's data unlike the inherited search does.
        //This program needs search to be used first to know the book exists.

        void freeShelfSpace();
        //calculates how much shelf space is left.
        //NOTE: the linked list can extend pass this space limit, but this limit
        //      is to show the librains that more book shelves should be bought

        librarySystem();
        //default constructor


        //already inherits search, insert and deleteNode from orderedLinkedList

private:
        //REMOVE: Book *head - orderedLinkedList has that
        int amount;
};

void librarySystem::fileRead(string fileName)
{
  int shelf = 0; row = 0;
  string title, author, bookID;

  ifstream testRun(fileName);

  while(testRun) {      //while loop to prevent an empty line read for linked list creation.
    testRun >> title >> author >> bookID;
    count++;
  }

  testRun.close();
  ifstream file(fileName);

  for(int i = 0; i < count - 1; i++) {
    file >> title >> author >> bookID;
    book a(title, author, bookID);
    amount++;
    this->insert(a);
  }
  file.close();
}

void librarySystem::filePrint(string fileName)
{
  linkedListIterator<book> travel;
  travel = this->begin();
  ofstream file(fileName);

  while(travel != nullptr) {
    file << (*travel).getTitle() << " " << (*travel).getAuthor()
         << " " << (*travel).getBookID() << endl;
    ++travel;
  }
}

void librarySystem::addBook(string title, string author, string bookID)
{
  book a(title, author, bookID);
  this->insert(a);
  amount++;
}

void librarySystem::deleteBook(string title)
{
  this->deleteNode(title);
  if(amount > 0)
    amount--;
}

void librarySystem::where(string title)
{
  int position = 0, shelf = 0, row = 0;
  linkedListIterator<book> travel;
  travel = this->begin();

  while((*travel).geTitle() != title) {  //finds linear total book-cell position value of book
    ++travel;
    position++;
  }

  //finds linear total row value of book's position while finding the exact book-cell position of book
  while(position > LENGTH) {
    position -= LENGTH;
    row++;
  }

  //finds the exact shelf value of book's position while finding the exact row book is on
  while(row > ROWS) {
    row -= ROWS;
    shelf++;
  }
  cout << " the book " << title << " is on Shelf" << shelf << " Row" << row << " Position" << position << endl;  //the results
}

void librarySystem::freeShelfSpace()
{
  int freeSpace;

  freeSpace = (SHELVES * ROWS * LENGTH) - amount;
  cout << "There is " << freeSpace << " book-cells of free space avaliable." << endl;
}

librarySystem::librarySystem()
{
  amount = 0;
}

#endif //end - made by Evan Palermo
