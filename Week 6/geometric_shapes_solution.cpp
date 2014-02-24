#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  double e, sarea, vol;
  e = sarea = vol = 0; //initialization
  int choice = 0;
  cout << "Enter in a choice:\n1 for surface area of a cube\n2 for volume of a cube\n3 for both\n"
       << "Choose here: ";
  cin>>choice;
  if(choice == 1) //if choice is 1
  {
    cout << "Enter in an edge of your cube: ";
    cin >> e;
    sarea = 6 * e * e;
    cout << "Surface Area: " << sarea << endl;
  }
  else if (choice == 2) //if choice is 2
  {
    cout << "Enter in an edge of your cube: ";
    cin >> e;
    vol = e * e * e;
    cout << "Volume: " << vol << endl;
  }
  else //assume 3 for now
  {
    cout << "Enter in an edge of your cube: ";
    cin >> e;
    sarea = 6 * e * e;
    cout << "Surface Area: " << sarea << endl;
    vol = e * e * e;
    cout << "Volume: " << vol << endl;
  }

  return 0;
}