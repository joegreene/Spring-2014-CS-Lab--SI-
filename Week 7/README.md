# Week 7

## Contents
- [Solutions (From Last Week)](#solutions-from-last-week)
- [Intro](#intro)
- [Chapter 4]()
  - [Validating User Input]()
  - [Block & Scope]()
  - [`break`]()
  - [Little More With `switch`]()
  - [More with `string` and `char`]()
  - [The Conditional Operator]()
  - [Enumerated Data Types]()
- [Worksheets & Extra Practice]()
  - [Solutions to Worksheets & Extra Practice]()
- [Extra Challenges]()

### Solutions (From Last Week)
Located above all this (under files section). Remember that these are only EXAMPLES of the solutions (in programming, there's always alternative ways to do a task). 

### Intro
Not much else is new here from Week 6. We'll continue with the rest of Chapter 4.
Other than that, near the top of this page click "Spring-2014-CS-Lab--SI-" and then "Week 6" to go back to last week's work, or simply click [here](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%206)
if you wish to do so.

I've also added more exercises to the bottom of this sheet if in case you finish all the work and review early.

### Chapter 4
#### `break`
`break` allows you to stop execution in a block of code. You'll see these frequently used in switch cases.

Example:

```C++
  //...code...
  bool some_bool = false;
  
  if(!some_bool) //another way of saying "if some_bool is false"
  {
    cout << "Variable some_bool is false\n" << endl;
    break;
    cout << "These bananas aren't for sale!" << endl;
  }
  
  //...code...
```

Output:
```
  ...
  Variable some_bool is false
  ...
```

#### Little more with `switch`
Remember that, with switch statements, the `break` statement is essential for all cases except `default`. I leave it there out of both habit and to remind myself that other cases require it.

Try out the following code with each letter input:

```C++
  #include "stdafx.h"
  #include <iostream>
  #include <cctype> //explained in "More with Strings and Characters"
  
  using namespace std;
  
  int _tmain(int argc, _TCHAR* argv[])
  {
    char grade = 'z'; //initialization
    
    cout << "Enter a grade to determine: ";
    cin >> grade;
    switch(tolower(grade)) //explained in "More with Strings and Characters"
    {
      case 'a':
        cout << "Good grade!" << endl;
        break;
      case 'b':
        cout << "Nice grade, although you should've gotten an A instead." << endl;
        break;
      case 'c':
        cout << "Passed, although you could've done better." << endl;
      case 'd':
        cout << "Unsure if you failed, but nonetheless this is a terrible grade." << endl;
      case 'f':
        cout << "You've failed. Sorry.";
      default:
        cout << "Unsure of inputted grade. Restart program." << endl;
        break;
    }
    
    return 0;
  }
```

Anything strange happen with any of the outputs? Fix the code so that it works as intended.

#### Validating User Input
If we want, we can use if, else, else-if, and switch statements for validating user input. Because we have control 
over the input given to us, we can direct the flow in which the program uses said input.

With if-else statements, we can determine faulty input by a range of values and simple rationality.

Example (with if-else):

```C++
  //...code...
```

If you've corrected the example under "Little More With `switch`", the default case is an example of user validation. In its case, 
we determined the case that isn't any of the others taken care of.

#### Block & Scope
Blocks describe the area in which a variable exists, whereas scope describes the area in which a variable can act upon. 

Example: 

```C++
  #include <iostream>
  using namespace std;
  
  int main() 
  {
    int some_var = 0; //initialization
       
    if (some_var == 0)
    {
      int some_var2 = some_var; //legal, some_var2 is within some_var's scope
      cout << some_var << endl; //legal, still in same block of some_var
    }
    
    cout << some_var2; /* illegal call, because some_var2 does not exist in this 
                          lock and this is outside of some_var2's scope (from the if statement) */
       
    return 0;
  }
```

In this case, `some_var` is located within a block outside of the if statement and its scope is both outside and inside the , one instance of `some_var2` is 

#### The Conditional Operator
Something not seen too often, the conditional operator can be used to create short if/else statements. It is a ternary operator, meaning it acts upon three variables/values.

Example of a conditional operator in use (same one as the powerpoint):

```C++
  //...code...
  
  x < 0 ? y = 10 : z = 20;
  
  //...code...
```

The equivalent of this using an if-else statement is as follows:

```C++
  //...code...
  if (x < 0)
    y = 10;
  else
    z = 20;
  //...code...
```

Because this is a ternary operator, it can only be used for two cases (a true and false case). Good way to remember this is by saying "IF a THEN b ELSE c", where
`a ? b : c;`.

#### More With Strings and Characters
Like booleans and other integer types, relational operators can be used on strings and characters. For example:

```C++
  //...code...
  
  //...code...
```

Unfortunately, we cannot use relational operators on c-strings. For those, each individual character must be tested and can be quite troublesome.

Using the `cctype` header, we can also 

#### Enumeration
An extremely handy tool in programming, [enumeration](http://www.merriam-webster.com/dictionary/enumerate) allows us to create a list of variables with incrementing values. 

A C++ example of enumeration:
```C++
  //...code...
  
  //...code...
```

More information [here](http://www.cprogramming.com/tutorial/enum.html).

### Worksheets & Extra Practice
All the below work problems should be done by pencil/paper.

#### Problems
- [Some list of boolean shiz]()
- [if/else outputs]()
- [syntax worksheet (what's wrong with the line and fix the code segment)]()
- [iomanip]()
- [cmath stuff]()
When you are done with these, check with other groups 

#### Separate Exercises
1. Make a program, complete with user input validation (for incorrect input), that rounds a decimal value up or down.

  Features:
  - Make sure not to use any `iomanip` features (especially for rounding).
  - Do not use if-else-else if or switch statements in this exercise.
  - Scan for an integer type, NOT a decimal value! 
  - Allow the user to input three numbers to round. This can be done by either three prompts or one line.
  - If the user enters in a value that isn't a floating-type, tell them their input is wrong.

2. TBD

NOTE: For both exercises, refrain from using topics covered in later chapters (or outside class). Stick with Chapters 1 through 4 material.

Example outputs can be found in the folder "Example Outputs" under the files section at the top of this page.
### Extra Challenges


If you feel comfortable with all the work we've done so far, I would suggest reading ahead in our book (Chapter 5) because it's a rather hefty chapter.

Other than that, here's a list of resources/practice you may check out (that relate to Chapter 5):
  1. [Loops (look under iteration statements)](http://www.cplusplus.com/doc/tutorial/control/)
  2. [More Work on Loops](http://www.cprogramming.com/tutorial/lesson3.html)
  
  ...
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Some notes grabbed from Dr. Tian's Chapter 3 Powerpoints

Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>