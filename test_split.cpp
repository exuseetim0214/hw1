/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstddef>

int main(int argc, char* argv[])
{

 Node* in = new Node{3, NULL};
 in = new Node{2,in};
 in = new Node{1,in};

 Node* odds = NULL;
 Node* evens = NULL;

 split(in, odds, evens);

std::cout <<"Odds: ";
Node* temp;
 while(odds!= NULL){
  temp = odds;
  std::cout << temp-> value << " ";
  odds = odds -> next;
  delete temp;
 }
std::cout << std::endl;
std::cout <<"Evens: ";
 while(evens!= NULL){
  temp = evens;
  std::cout <<  temp-> value << " ";
  evens = evens -> next;
  delete temp;
 }
std::cout << std::endl;
return 0;
}
