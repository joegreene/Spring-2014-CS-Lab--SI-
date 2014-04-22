# Week 13

## Contents
- [File IO](#file-io)
  - [Grabbing Information from Files](#grabbing-information-from-files)
    - [Special Note: Using eof()](#special-note-using-eof)
    - [Special Note: Delimiters in getline and Another Way to Scan](#special-note-delimiters-in-getline-and-another-way-to-scan)
  - [Writing to a File](#writing-to-a-file)
  - [Input and Output at Once](#input-and-output-at-once)
  - [iostream Versus fstream](#iostream-versus-fstream)
- [Practice Assignments](#practice-assignments)

### File IO
File IO is short for "File Input/Output". For what we're dealing with, in the following examples we will always require `#include <fstream>` above our code, and of course before `#include "stdafx.h"`. Also, whenever reading or writing from a file 
we always need to first `open` the file, then when we are done reading/writing to the file we must `close` it.

Because we won't have to deal with binary files right now (or so I believe), we'll only be working with text files. If things change later then I'll do my best to help explain how to work with them.

Although it might be more difficult to read due to the jargon on the page (and talk about binary files), you can also learn about file IO [here](http://www.cplusplus.com/doc/tutorial/files/). Just skip to the "text files" section.

#### Grabbing Information From Files
To grab information from a file, we first must make a `ifstream` (input file stream) object. This would look similar to the following: 
```C++
  ifstream file;
```

Next, open a file (not forgetting to include the extension):
```C++
  file.open("filename.txt");
```

Another way of doing this is by using a `string`, followed by `c_str()`:
```C++
  string filename;
  cout << "Enter a file to grab data from: ";
  getline(cin, filename);
  
  file.open(filename.c_str());
```

The reason we need `c_str()` is because the argument for calling the `open` function requires a character array. `c_str()` returns a character array equivalent to our string.

We can also read from specific directories on the disk drive:
```C++
  string filename = "some_folder\\phrase_list.txt"; //sets filename to phrase_list.txt in some_folder (some_folder is in the same directory as the running program)
  
  string filename2 = "C:\\text.txt" //sets filename to text.txt in the C: drive.
```

Going back to the task at hand: Thirdly, to grab the actual text from the file, we first need to check if we have correctly opened the file. Opening an input file may fail when the file does not exist in 
the directory, or the program does not have permission to read/write in the directory. Afterwards, we loop through the text file, grabbing each line (if necessary):
```C++
  const int MAX_COUNT = 50;
  int total_strings = 0;
  string string_list[MAX_COUNT]; //set to some arbitrary value
  
  if(file.is_open()) //check to see if the file is open. An alternative way to do this simply use `if(file)` as that returns true if it is open as well
  {
    while(!file.eof() && total_strings < MAX_COUNT) //while we are not at the end of file and we haven't reached maximum number of strings
    {
      getline(file, strings_list[total_strings]); //assign each position of strings_list to the current line we are on in the file
      
      ++total_strings; //increment count
    }
  }
  else
  {
    cout << "File could not be read. Make sure the name is typed correctly and in the same directory as this executable." << endl;
  }
  
```

In the above example, what happened was we grabbed each line of the text file and put it into each index position of our array, `string_list`. We also made sure to grab just enough to not exceed our 
maximum amount of strings. The line:
```C++
  getline(file, strings_list[total_strings]);
```

Tells the program to go to the file, grab everything on the current line it is on, and plug that into the index of `strings_list` we are currently on. The way it knows where to go is because, like using `getline` and `cin`, 
using `getline` with `file` starts at the beginning, and moves through each line.

We're missing a line in the code. As a guess, what do you suppose it is? If you need a hint, read back under the topic "File IO". It's something we're always supposed to do at the end of opening and reading/writing from a file.

SPOILER: The answer is `file.close();`, and it goes after the `while` loop as follows (assume the other code is there):
```C++
  if(file.is_open())
  {
    while(!file.eof() && total_strings < MAX_COUNT) //one way of doing this, but not necessarily the right way
    {
      getline(file, strings_list[total_strings]);
      ++total_strings;
    }
    
    file.close(); //<------ NEWLY ADDED LINE HERE
  }
```

__SIDE NOTE:__ Here are alternative ways to grab text, and replace 

##### Special Note: Using eof()
From what I've heard, it's generally bad to use the function `eof()`. Although `eof()` means "end of file", the reason it is bad is because what it actually means is "".

Alternatively, what we may do is set the conditional check in the `while` loop to be the `getline` expression. 

For more information, check out [this](http://stackoverflow.com/questions/5837639/eof-bad-practice) page. Also, check out [here](http://mathbits.com/MathBits/CompSci/Files/End.htm).

##### Special Note: Delimiters in getline and Another Way to Scan
If our text file has a specific way of grouping data to grab, e.g. by using ' ' or '|', we can change the arguments to `getline`.

For grabbing data until `|` is read, we set `|` as the third argument to the function call `getline`:
```C++
  getline(file, string_to_grab, '|'); //for adding to string_to_grab until '|' is read
```

If we want to use another character as a delimiter, just change the third argument to whatever character you need.

So, for instance, if we have a text file with the following:
```C++
  cow is fat|hello world|okay
```

Assuming we successfully opened the file and the rest of the code is present, we may do the following to grab the words:
```C++
  string list[5];
  int phrase_count = 0;
  
  if(file.is_open())
  {
    while(getline(file, list[phrase_count], '|')) //while we can grab phrases
    {
      ++phrase_count; //increase phrase_count
    }
  }
```

If we want to grab numbers or characters that do not require spaces, we may use the extraction operator (`>>`).:
```C++
  int ID_list[MAX_COUNT]; //MAX_COUNT is an arbitrary integer
  int ID_count = 0;
  
  if(file)
  {
    while(file >> ID_list[ID_count]) //while we can grab an ID; works like getline
    {
      ID_count++; //increase ID_count
    }
  }
  
```

Characters are similar in the sense you require `>>` to grab each individual character.

#### Writing to a File
Almost like reading from a file, we instead use `ofstream` (output file stream) to output to a file.

Like before, we first open a file:
```C++
  string filename = "text_file.txt";

  ofstream outfile;
  outfile.open(filename.c_str());
```

If the output file we try to open does not exist in the directory we're working with, the file is created in that directory. The only chances are that this 
will fail is when there isn't enough space on the disk drive, or when the program does not have permission to read/write to files in the focused directory.

Secondly, if we want to write "twenty one" to some file, we do the following:
```C++
  if(outfile.is_open())
  {
    outfile << "twenty one";
  }
```

We can write anything to a text file this way, just like how `cout` works.

Lastly, when finished writing to the file, make sure to close it (like with inputting data).
```C++
  outfile.close();
```

#### Input and Output at Once
If we use `fstream` to replace either `ifstream` or `ofstream`, we can have an object to do both reading and writing.

```C++
  fstream file;
  file.open(filename.c_str());
  
  string some_string;
  getline(file, some_string); //grab from file to put in some_string
  
  file << some_string; //write to 
```

#### iostream Versus fstream
It's really nice how similar the `iostream` and `fstream` libraries are. With some minor differences in initialization and implementation, each can almost be interchanged exactly, line-by-line.

For instance, recall back to how we grab from and wrote to a file:

__WARNING:__ At this point, some of you may go into complete shock. Do not feel alarmed however.

If we wanted to make our own `cin` and `cout` objects that do exactly what `cin` and `cout` do, we do the following:
```C++
  ostream console_out; //equivalent to cout; ostream means output stream
  istream console_in; //equivalent to cin; istream means input stream
  
  int some_var;
  
  console_out << "Enter in a number: ";
  console_in >> some_var;
  
```

These work exactly the same as `cout` and `cin` (in terms of using the insertion and extraction operators, or '<<' and '>>' respectively).

### Practice Assignments
1. Make a program that scans a file containing words and tells the user if each word is or is not a palindrome. If you do not know, a palindrome is a word that is 
spelt exactly the same backwards (e.g. "racecar" and "civic" are palindromes but "palindrome" and "alpha" are not palindromes). Have the maximum amount of entries be 50.

2. Make the game Hangman. [Here](http://en.wikipedia.org/wiki/Hangman_%28game%29) it is if in case you've never heard of it. It needs to have the following:
  - Must print the correct number of dashes and spaces for the guesses (e.g. --- --- for guess phrase "Old Dog")
  - Must print the list of wrong guesses each turn.
  - Have the maximum unique wrong guesses be six (for each body part).
  - Must grab a word list from a text file. The phrase count is arbitrary (if anything set it to 50). If the file does not exist, __do not__ execute the game.
  - Must tell the user the right word in the end (if they used up all their unique wrong guesses).
  - BONUS: Print out the hangman image each time. HINT: Best way to do this is to use a 2d-array.
  
  
Example outputs and resources for each assignment are added at top of page. Your outputs should be roughly similar (except for the exceptions in Hangman). If enough people ask, we'll go over them (or just one) together.

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>