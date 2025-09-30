#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;

  // push back
  dat.push_back(0);
  cout << "Front:" << dat.front()<< endl;
  cout << "Back:" << dat.back() <<endl;

  dat. push_front(1);
  cout << "Front:" << dat.front()<< endl;
  cout << "Back:" << dat.back() <<endl;

  dat.push_back(2);
  cout << "Front:" << dat.front()<< endl;
  cout << "Back:" << dat.back() <<endl;

  dat. push_front(3);
  cout << "Front:" << dat.front()<< endl;
  cout << "Back:" << dat.back() <<endl;

  dat.pop_front();
  cout << "Front:" << dat.front()<< endl;
  cout << "Back:" << dat.back() <<endl;

  dat.pop_back();
  cout << "Front:" << dat.front()<< endl;
  cout << "Back:" << dat.back() <<endl;

  for(size_t i= 0; i < list.size(); i++){
    cout << list.get(i)<< " ";
  }

  return 0;


}
