/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
// check if empty
if(in == NULL){
   odds = NULL;
   evens = NULL;
   return;
}

// recursive call
Node* next = in -> next;
split(next, odds, evens);

//check if even and put it to the evens list
if(in -> value % 2 == 0){
  in -> next = evens;
  evens = in;
}
//check if odds and put it to the odds list
else{
  in -> next = odds;
  odds = in;
}

// setting in to null
in = NULL;
}

/* If you needed a helper function, write it here */
