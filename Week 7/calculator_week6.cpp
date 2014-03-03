// calculator_week6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //default header we use for 
#include <iostream> //for cout, cin, and endl
#include <iomanip> //for 
#include <string> //string class
#include <cmath> //for advanced options

using namespace std;
    
int _tmain(int argc, _TCHAR* argv[])
{
  string option = " "; //variable for choosing between simple or advanced algebra
  string str_op = " "; //for advanced algebra options
  char op = 'b'; //the operator used for simple algebra
  int prec = 0; //for precision setting
  double num1, num2; //numbers used overall
  num1 = num2 = 0;
  
  cout << "Calculator Program. Woot!" << endl << endl;
  cout << "Simple Options: Addition (+)" << endl;
  cout << "Subtraction (-)" << endl;
  cout << "Multiplication (*)" << endl;
  cout << "Division (/)" << endl;
  cout << "Modulus (%)." << endl << endl;

  cout << "Advanced Functions:" << endl;
  cout << "Square root" << endl;
  cout << "Power" << endl;
  cout << "Logarithm (base-10)" << endl << endl;
  cout << "NOTE: With Modulus, if you enter in decimal values the decimals will be automatically truncated (no rounding).\n" << endl;

  cout << setfill('-') << setw(50) << "\n"; //for the fancy line, where setfill and setw require a string to work on in the end

  cout << "Choose either simple or advanced (lower case): ";
  getline(cin, option);

  cout << "How many significant digits would you like your answers to be at? ";
  cin >> prec;

  if(option == "advanced") //if the advanced option was chosen
  {
    cout << "To use square root, type \"sqrt\", space, then your number.\n";
    cout << "To use the power function, type \"pow\", space, your number, space, then the exponent.\n";
    cout << "To use logarithm (base-10) function, type \"log\", space, then your number.\n";

    cout << "Enter in a function and number: ";
    cin >> str_op >> num1;

    if(str_op == "sqrt")
    {
      cout << "sqrt(" << num1 << ") = " << setprecision(prec) << sqrt(num1) << endl; //gives a neat output
    }
    else if (str_op == "pow")
    {
      cin >> num2; //this is the only function that requires two inputs, so the scan for num2 can be put here
      cout << "pow(" << num1 << ", " << num2 << ") = " << setprecision(prec) << pow(num1,num2) << endl; //gives a neat output
    }
    else if (str_op == "log")
    {
      cout << "log(" << num1 << ") = " << setprecision(prec) << log10(num1) << endl; //another neat output
    }
    else
      cout << "Unknown input.\n"; //to catch errors made
  }
  else if(option == "simple") //if the simple algebra option was chosen
  {
    cout << "Enter in two numbers, separated by an operator (e.g. 3 + 4): ";
    cin >> num1 >> op >> num2;
    
    switch(op) //determine value of character operator, each having a neat output
    {
      case '+':
        cout << num1 << " + " << num2 << " = " << setprecision(prec) << (num1 + num2) << endl;
        break;
      case '-':
        cout << num1 << " - " << num2 << " = " << setprecision(prec) << (num1 - num2) << endl;
        break;
      case '/':
        cout << num1 << " / " << num2 << " = "<< setprecision(prec) << (num1 / num2)<<endl;
        break;
      case '*':
        cout << num1 << " * " << num2 << " = "<< setprecision(prec) << (num1 * num2) << endl;
        break;
      case '%':
        cout << num1 << " % " << num2 << " = " << setprecision(prec) << (static_cast<int>(num1) % static_cast<int>(num2)) << endl;
                //IMPORTANT! To use the modulus operator, both operands must be type int
        break;
      default: //error-checking, unrequired but nice to have
        cout << "Unknown operator requested.\n";
        break;
    }
  }
  else //for unknown
    cout << "Unknown choice given (not simple or advanced).\n";
  
  cout << "Thanks for using this program!" << endl;

  return 0;
}

