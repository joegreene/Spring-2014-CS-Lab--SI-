// hangman_lame_version.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  //Strings
  string correct_phrase = "BANANA JAMS"; //arbitrary guess phrase; make this all uppercase for easier syntax
  string masked_phrase = correct_phrase; //do this so we can set up the positions easily
  string wrong_list = ""; //initialization

  //Integers
  int num_guesses = 6; //number of guesses allowed

  //Characters
  char input = ' ';

  //Booleans
  bool is_playing = true; //assume true at start; for total play
  bool is_guessing = true; //assume true at startl; for guessing aspect
  bool in_phrase = false; //assume false at start; for checking if a value is in the correct phrase
  bool guessed_right = false; //assume false at start; 
  bool in_wrong = false; //assume false at start

  //Initialize masked_phrase
  for(int i = 0; i < masked_phrase.length(); ++i)
  {
    if(masked_phrase[i] != ' ') //if current position is not a space
      masked_phrase[i] = '-'; //set it to a dash
  }

  //Play game
  do
  {
    cout << masked_phrase << endl;
    cout << "Wrong letters: " << wrong_list << endl;
    cout << "Number of tries left: " << num_guesses << endl;

    if(is_guessing) //if the user is still guessing
    {
      cout << "Enter an alphabetical letter: ";
      cin >> input;
      input = toupper(input); //set as uppercase to make check in-phrase easier

      if(isalpha(input)) //if the user correctly inputted an alphabetical character and is still playing
      {
        //Scan to see if input is in the phrase
        for(int i = 0; i < correct_phrase.length(); ++i)
        {
          if(correct_phrase[i] == input) //if the current position of the guess phrase equals input
          {
            masked_phrase[i] = input; //set to corresponding position
            in_phrase = true; //set in_phrase bool to true
          }
        }

        if(in_phrase == true) //if we found the input in the phrase
        {
          in_phrase = false; //reset check

          if(correct_phrase == masked_phrase) //if the user has guessed the phrase fully right
          {
            is_guessing = false; //redirect to win
            guessed_right = true; //redirect to win
          }
        }
        else //if it is not in the phrase
        {
          //Check to see if the input is in the wrong_list
          for(int i = 0; i < wrong_list.length(); ++i)
          {
            if(wrong_list[i] == input)
            {
              in_wrong = true;
            }
          }

          if(in_wrong == true) //if the input is in the wrong list
          {
            in_wrong = false;
          }
          else //if the input is not in the wrong list
          {
            wrong_list+=input; //add to wrong list
            wrong_list+=' '; //add a space for neatness
            --num_guesses; //decrease the amount of guesses left

            if (num_guesses <= 0)
            {
              is_guessing = false; //redirect to else if with loss
            }
          }
        }
      }
      else //if the user did not input a character
      {
        cout << "Invalid input." << endl;
      }
    }
    else if(guessed_right) //if stopped playing and won
    {
      cout << endl << "You won! Congratulations." << endl;
      is_playing = false;
    }
    else //if stopped playing and lost
    {
      cout << endl << "You lost, sorry. The answer was: " << correct_phrase << endl;
      is_playing = false;
    }

    cout << endl << endl; //for cleanliness

  }while(is_playing);

	return 0;
}

