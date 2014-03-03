// guessing_game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //seemingly-pointless header for _tmain
#include <iostream> //input/output stream
#include <cstdlib> //to use srand and rand
#include <ctime> //to use time function

#define UPPER_BOUND 10 //constant macro; can be done differently

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  srand ( time(NULL) ); //generates new seed for program (so the number is randomized)

  int guess = 0; //initialization
  int random_num;
  

  random_num = rand() % UPPER_BOUND + 1; //proper way to get a random integer between 1 and 10
  //random_num = 2; //for test purposes

  cout << "Welcome to the number guessing game!\n\n";
  cout << "Guess an integer value between 1 and 10: ";
  cin >> guess; //grab guess
  
  if (guess == random_num) //if they guessed the value right
  {
    cout << "You're correct! Good job!\n";
  }
  else //if they did not guess right
  {
    if (guess > random_num && guess < UPPER_BOUND) //if they guess higher than the actual value
      cout << "Sorry, your guess is above the random number.\n";
    else if (guess < random_num && guess > 0) //if they guess less than the actual value
      cout << "Sorry, your guess is below the random number.\n";
    else //out of bounds
      cout << "Number guessed is out of bounds. There's no way you would've guessed it right.\n";

    cout << "Actual value: " << random_num << "\n\n";
  }
  cout << "Thanks for playing!\n"; //neat little message at the end
}
