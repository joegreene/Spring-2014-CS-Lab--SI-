// week7_rounding_program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  double val2;
  int val, decimal;
  char dot = '.';

  cout << "Welcome to the wondrous decimal-value rounding program!" << endl;
  cout << "Unfortunately though, due to the economy, you only get three chances to round." << endl;
  cout << "Enter in a decimal value to be rounded: ";
  cin >> val >> dot >> decimal; //scan for the integer, the dot in between, and the decimal

  if (dot == '.') //if the input was a decimal
  {
    val2 = (val >= 0) ? (val + (decimal * .1)) : (val - (decimal * .1)); //set val2 as the decimal value
                                                                         //where if val is positive, 
                                                                         //val2 = val + the decimal (in 
                                                                         //proper place); else, then 
                                                                         //val2 = val - the decimal (in
                                                                         //its proper place)
    val = static_cast<int>(val2 >= 0 ? val2 + 0.5 : val2 - 0.5); //rounding done here
    cout << "Your input rounded is: " << val << endl; //output new, rounded value
  }
  else 
  {
    cout << "Invalid input." << endl;
  }
  cout << "Two more tries..." << endl;

  cout << "Enter in a decimal value to be rounded: ";
  cin >> val >> dot >> decimal; //scan for the integer, the dot in between, and the decimal

  if (dot == '.') //if the input was a decimal
  {
    val2 = (val >= 0) ? (val + (decimal * .1)) : (val - (decimal * .1)); //set val2 as the decimal value
                                                                         //(same as first)
    val = static_cast<int>(val2 >= 0 ? val2 + 0.5 : val2 - 0.5); //rounding done here
    cout << "Your input rounded is: " << val << endl; //output new, rounded value
  }
  else
  {
    cout << "Invalid input." << endl;
  }
  cout << "One more try..." << endl;

  cout << "Enter in a decimal value to be rounded: ";
  cin >> val >> dot >> decimal; //scan for the integer, the dot in between, and the decimal

  if (dot == '.') //if the input was a decimal
  {
    val2 = (val >= 0) ? (val + (decimal * .1)) : (val - (decimal * .1)); //set val2 as the decimal value
                                                                         //(same as first)
    val = static_cast<int>(val2 >= 0 ? val2 + 0.5 : val2 - 0.5); //rounding done here
    cout << "Your input rounded is: " << val << endl; //output new, rounded value
  }
  else
  {
    cout << "Invalid input." << endl;
  }

  cout << "No more tries. Thanks for using this program!" << endl;

  //lazy way to do this
  
	return 0;
}