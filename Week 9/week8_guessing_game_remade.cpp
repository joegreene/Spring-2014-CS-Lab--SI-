// week_8_guessing_game_remade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> //all the required headers/includes up here
#include <ctime>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  srand(time(NULL)); //generate new seed for random number generator

  bool finished = false; //to determine when to stop the loop
  const int MAX = 10; //must initialize when using constant variables
  const int LOWER_LIMIT = 1; //if you'd like to make your program more 
                             //customizable, make a lower limit variable
  const int RAND_NUM = rand() % MAX + LOWER_LIMIT; //static random number
                                                   //(static == doesn't change)
  const int QUIT_VALUE = 55; //value for quitting
  int guess = 0; //"  " guess
  int num_tries = 0; //number of guesses

  cout << "Welcome to the random number guessing game!" 
       << endl; //prompt
  cout << "If you would like to quit at any time, enter in " << QUIT_VALUE 
       << " when guessing." << endl; //more prompt

  do
  {
    cout << "Enter in a value between " << LOWER_LIMIT << " and " << MAX << endl;
    cin >> guess;

    if(guess == QUIT_VALUE) //if user decides to quit
      finished = true;
    else if (guess > MAX || guess < LOWER_LIMIT) // if guess is out of bounds
    {
      cout << "Your guess was out of bounds. Enter values between "
           << LOWER_LIMIT << " and " << MAX << endl;
      num_tries++;
    }
    else if (guess == RAND_NUM)
    {
      cout << "You guessed it right! Good job!" << endl;
      finished = true;
      num_tries++;
    }
    else
    {
      cout << "Sorry, but you guessed incorrectly. Try again." << endl;
      num_tries++;
    }
  }while(!finished); //while the user isn't finished

  cout << "Actual random number value: " << RAND_NUM << endl;
  cout << "Number of guesses made: " << num_tries << endl;

  cout << "Thanks for playing!" << endl;

	return 0;
}

