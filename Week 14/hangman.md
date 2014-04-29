# Week 14

## Contents
- [Intro](#intro)
- [Steps](#steps)
  - [Psuedo-code](#psuedo--code)
  - [Translation to C++](#translation-to-c++)
  - [Debugging](#debugging)
- [Practice Assignment](#practice-assignment)
- [Extra Challenges](#extra-challenges)

### Intro
This page will go through all of the proper steps in order to make the game Hangman.

### Steps
Normally, making a program can be split up into several steps: Psuedo-code, C++ translation, and overall debugging.

#### Psuedo-code
The most important part to making this game (or really any program) is to lay out everything you will need, in a step-wise fashion.

For instance, let's say we need to make a program that grabs a list of students from a file, allow the user to add, delete, print, and close, saving the records to the file 
when the program quits. A psuedo-code example would be:

```
  Grab and store the data for the student list
  
  While the user hasn't quit yet
    If user decides to add a record
      If the cap hasn't been reached, let the user add a record
      Else, tell the user no more records can be added
      
    If the user decides to delete a record
      If there are any records, delete the record requested
      Else, tell the user there are no more records on the list
      
    If the user decides to print the list
      If there are any records, print each record
      Else, tell the user there are no records
      
    If the user decides to quit the program, close the program and overwrite previous records in file with new records.
    
    If there was invalid input, request the user to input 
    
  End the program (when outside request)
```

Do something similar to the above 

The best way (in my opinion) to go about this is to make it as general as possible at first. Think about the problem, split it up into smaller pieces, and go from there. 
This technique is called taking a top-down approach. More info [here](#http://en.wikipedia.org/wiki/Top-down_and_bottom-up_design).

You'll want to debug your psuedo-code, making sure there aren't any sort of logical errors or missing steps. This way, you won't have to work so hard on the next and 
third step.

#### Translation to C++
This step shouldn't be too rough to get through, given you have sufficient psuedo-code and syntax knowledge. It's definitely the lengthiest though. The two biggest problems with translation is 

__1)__ Making sure you have all the correct variables needed and 
__2)__ Dealing with the compiler's pickiness.

To be nice however, I'll give you the code to initialize the dashes prompt. It might be a bit tricky, but it's doable:
```C++
  string output_prompt = guess_phrase;

  for(int i = 0; i < output_phrase.length() ++i)
    {
      if(output_phrase[i] != ' ')
        output_prompt[i] = '-';
    }
```

If the above is confusing, this is what's going on:
```
  Initially set both the output_prompt (for dashes) to the guess_phrase
  
  For each position in output_prompt
    if the current character is not a space, set it to a dash
```

It's simple in psuedo-code, but not necessarily in the C++ syntax example. Remember that each position in a string can be treated as an array index. That's because a 
string is an array of characters (don't call it a char array though, because that's another, older version of the string).

Note also how the psuedo-code translated pretty well over to the C++ version. That's what you want to happen with your own psuedo-code translation.

This is another time to debug both your psuedo-code and C++ code. If either conflict, or doesn't work in some way, something is wrong in one or both of them.

#### Debugging
At this point, if your code works completely as you need it to be then good job. Else, you'll want to write down a list of what's wrong, think about how to fix that, then 
revise either your psuedo-code, your C++ work, or both. You'll want to check for robustness (e.g. invalid input) as well, although that isn't a requirement for this 
project.

### Practice Assignment
1. Complete the Hangman game. Hopefully we'll have enough time to do this. It needs to have the following:
  - Must print the correct number of dashes and spaces for the guesses (e.g. --- --- for guess phrase "Old Dog")
  - Must print the list of wrong guesses each turn.
  - Allow the user to have six unique guesses (for each body part).
  - Must tell the user the right word in the end (if they used up all their unique wrong guesses).
 
__NOTE:__ Remember that going from your psuedo-code to your C++ translation should be pretty seamless. 
 
Example outputs are located under "hangman_minimum" in the "Solutions" folder.
  
### Extra Challenges
Add the following to your game:
- Must grab a word list from a text file. The phrase count is arbitrary (if anything set it to 50). If the file does not exist, __do not__ execute the game.
  - Let the user know the file is unreadable or does not exist.
- Print out the hangman image each time. HINT: Best way to do this is to use a 2d-array.

Example outputs are located under "hangman_complete" in the "Solutions" folder.
-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>