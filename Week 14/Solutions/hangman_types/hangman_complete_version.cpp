// hangman_complete_version.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //below order includes don't matter, just make sure this is above the rest
#include <iostream>
#include <fstream> //for file io
#include <string>
#include <cstdlib> //for random
#include <ctime> //for srand

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  //Word list variables
  const int MAX = 50; //arbitrary value
  string phrase_list[MAX];
  bool made_list = false; //assume false for easier syntax
  int phrase_count = 0; //phrase counter

  //File variables
  string filename = "";

  //Request and grab filename
  cout << "What is the name of the file you want to grab words from (add .txt to end)? " << endl;
  getline(cin, filename);

  ifstream input_file;
  input_file.open(filename.c_str());

  if(input_file.is_open()) //if the file opened correctly
  {
    //While the phrase count is less than maximum and there are grabbable lines left
    while(phrase_count < MAX && getline(input_file, phrase_list[phrase_count]))
    {
      ++phrase_count;
    }

    made_list = true; //set toggle to true since we made the list
    input_file.close(); //always do this, or else data might be lost/corrupted when the program terminates
  }
  else //if the file did not open correctly
  {
    cout << "File not found. \nMake sure the inputted filename is correct and in the same directory as this program." << endl;
  }


  if(made_list == true) //if the phrase list was initialized
  {
    //Set up grid
    char hangman_grid[7][6] = {' ', ' ', '_', '_', '_', '_',
				    			            ' ', ' ', ' ', ' ', ' ', '|',
				    			            ' ', ' ', ' ', ' ', ' ', '|',
						    	            ' ', ' ', ' ', ' ', ' ', '|',
						    	            ' ', ' ', ' ', ' ', ' ', '|',
						    	            ' ', ' ', ' ', ' ', ' ', '|',
                              ' ', ' ', ' ', ' ', ' ', '|'};

    //Random index for random correct_phrase
    srand(time(NULL)); //reset random number generator
    int rand_index = rand() % phrase_count; //set random integer (for index) within range of 0 to phrase_count - 1

    //Strings
    string correct_phrase = phrase_list[rand_index]; //set correct_phrase to a random string in phrase_list

    //Initialize correct_phrase using all char in it as uppercase
    for(int i = 0; i < correct_phrase.length(); ++i)
    {
      correct_phrase[i] = toupper(correct_phrase[i]); //uppercase each position
    }

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

    cout << "\nHANGMAN GAME" << endl;
    do
    {
      //Print grid; 7 = number of rows, 6 = number of columns
      for(int r = 0; r < 7; ++r)
      {
        for(int c = 0; c < 6; ++c)
        {
          cout << hangman_grid[r][c];
        }
        cout << endl;
      }

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

              //Add body part to grid
              switch(num_guesses)
              {
                case 0: //lost all tries (lost game); full body
                  hangman_grid[4][2] = '\\';
                  break;
                case 1: //lost five times; full body minus right leg
                  hangman_grid[4][0] = '/';
                  break;
                case 2: //lost four times; full body minus legs
                  hangman_grid[2][2] = '-';
                  break;
                case 3: //lost thrice; head + body + left arm
                  hangman_grid[2][0] = '-';
                  break;
                case 4: //lost twice; head + body
                  hangman_grid[2][1] = '|';
                  hangman_grid[3][1] = '|';
                  break;
                case 5: //lost one; head
                  hangman_grid[1][1] = 'O';
                  break;
                default:
                  break;
              }

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
  }

	return 0;
}

