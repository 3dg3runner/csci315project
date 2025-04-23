/*
Class version designed by: Evan Palermo; struct versions made by Gaby (pseudocode), and Samuel
Created on 4/18/2025

NOTE: I think we might want to have book be a class of librarySystem, so I made it one.
      I might be wrong, but it helped me to know to write better for librarySystem.

Also, I was able to compile this one and it worked fine.

*/


#ifndef H_Book
#define H_Book

#include <string>

using namespace std;

class book
{
public:
        string getTitle();
        string getAuthor();
        string getBookID();
        book();
        book(string t, string a, string id);

private:
        string title;
        string author;
        string bookID;
};

string book::getTitle()
{
  return title;
}

string book::getAuthor()
{
  return author;
}

string book::getBookID()
{
  return bookID;
}

book::book()
{
  title = "";
  author = "";
  bookID = "";
}

#endif

