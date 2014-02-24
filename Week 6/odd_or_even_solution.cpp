#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  int some_int = 0;
  bool is_odd = false;

  cout<<"Is your integer odd or even? Find out by entering an integer!: ";
  cin>>some_int;

  is_odd = some_int%2; //find if there is a remainder when dividing by 2

  if(is_odd) //mixing both concepts together
  {
    cout << "Your number is odd.\n";
  }
  else
  {
    cout << "Your number is even.\n";
  } 
  return 0;
}