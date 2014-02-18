/*
	Example solution for the Madlib program
*/

#include "stdafx.h"
#include <iostream> //include iostream header
#include <string> //include string header

//using namespace std; //omitted for bonus

int _tmain(int argc, _TCHAR* argv[]) 
{
  char initial1,initial2,initial3; //initials variables

  initial1=initial2=initial3=' '; //initialize variables

  std::string noun1, verb1, adj1, noun2, verb2; //word variables

  noun1=verb1=adj1=noun2=verb2=""; //initialize variables

  int num_words = 0; //for word count

  std::cout << "What are your initials? (First, middle, last separated by spaces): ";
  std::cin >> initial1 >> initial2 >> initial3; //request initials

  std::cout << "Enter a noun: ";
  std::cin >> noun1; //request first noun
  num_words = num_words + 1; //increase word count

  std::cout << "Enter a verb: ";
  std::cin >> verb1; //request first verb
  num_words += 1; //increase word count
  
  std::cout << "Enter an adjective: ";
  std::cin >> adj1; //request first adjective
  num_words += 1; //increase word count

  std::cout << "Enter another noun: ";
  std::cin  >>  noun2; //request second noun
  num_words += 1; //increase word count

  std::cout << "Enter another verb: ";
  std::cin  >>  verb2; //request second verb
  num_words += 1; //increase word count

  //Print story with variables included
  std::cout << "\nHere is your story, " << initial1 << "." << initial2 << "." << initial3 << ".:\n\n";

  std::cout << "Once upon a time, there lived a [" 
			 <<  noun1 << "] named George.\n";
  std::cout << "George, who had quite the unique taste to [" << verb1 << "], came across a [" 
			 << adj1 << "] [" << noun2 << "] while walking home.\n";
  std::cout << "Not caring for what he came across, George decided to ["  << verb2 << "] and walk  home. The end.\n\n";

  std:: cout <<  "Here are the number of words inputted: "
			 <<  num_words << std::endl << std::endl;

  return 0; //exit function
} //End of main