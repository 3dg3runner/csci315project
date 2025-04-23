//Author: Evan Palermo
//I was able to compile and run the program successfully. 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int BOOKLIMIT = 3;        //limit of books allowed to be checked out at once

//NOTE: the array idea requires that book be a struct rather than a class
//  because a class would require it to be a linked list not an array (at least that is what
//  it seems like)
struct book {           //Modified version of Sameul's Book struct
    string title;
    string author;
    string bookID;
};

void receiptPrint(book a[BOOKLIMIT]);

int main() {    //a test main - should not be implemented in project.

  book checkedOut[BOOKLIMIT];

  for(int i = 0; i < BOOKLIMIT; i++) { //to fill array with something
    if(i % 2)
      checkedOut[i].title = "Apple";
    else
      checkedOut[i].title = "Orange";

    if(i % 2)
      checkedOut[i].author = "Berry";
    else
      checkedOut[i].author = "Sarah";

    if(i % 2)
      checkedOut[i].bookID = "12345";
    else
      checkedOut[i].bookID = "98765";
  }

  //...

  receiptPrint(checkedOut);

  return 0;
}
void receiptPrint(book a[BOOKLIMIT]) {

  ofstream file("receipt.txt");

  for(int i = 0; i < BOOKLIMIT; i++) {
    file << a[i].title << " " << a[i].author << " "
         << a[i].bookID << endl;
  }
  file.close();
}

