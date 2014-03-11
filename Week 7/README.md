# Week 7

## Contents
- [Solutions (From Last Week)](#solutions-from-last-week)
- [Intro](#intro)
- [Chapter 4](#chapter-4)
  - [Validating User Input](#validating-user-input)
  - [Block & Scope](#block--scope)
  - [Using `break`](#using-break)
  - [Little More With switch](#little-more-with-switch)
  - [More with `string` and `char`](#more-with-string-and-char)
  - [The Conditional Operator](#the-conditional-operator)
  - [Enumerated Data Types](#enumerated-data-types)
- [Class Practice](#class-practice)
  - [Worksheets](#worksheets)
  - [Separate Exercise](#separate-exercise)
- [Extra Challenges](#extra-challenges)

### Solutions (From Last Week)
Located above all this (under files section). Remember that these are only EXAMPLES of the solutions (in programming, there's always alternative ways to do a task). 

### Intro
Not much else is new here from Week 6. We'll continue with the rest of Chapter 4.
Other than that, near the top of this page click "Spring-2014-CS-Lab--SI-" and then "Week 6" to go back to last week's work, or simply click [here](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%206)
if you wish to do so.

I've also added more exercises to the bottom of this sheet if in case you finish all the work and review early.

### Chapter 4
A continuation of last week's work. If you've brought it with you, it might be handy to have your book at hand. Else, either ask a friend or use Google to help you out.

#### Validating User Input
If we want, we can use if, else, else-if, and switch statements for validating user input. Because we have control 
over the input given to us, we can direct the flow in which the program uses said input.

With if-else statements, we can determine faulty input by a range of values and simple rationality.

Example (with if-else):

```C++
  //...code...
  int percent = 50;
  
  if (percent > 100 || percent < 0) //if the percent is either above 100 OR below 0
  {
    cout << "Invalid percent" << endl;
  }
  else
  {
    //do necessary procedures with percent
  }
  
  //...code...
```

For switch statements: Although other cases can be used, primarily the `default` case is used for validation. If all other cases are not met, `default` is reached and everything else in the switch statement is ignored.
An example is gone over in the section "Little More With switch".

#### Block & Scope
Blocks describe the area in which a variable or item exists, whereas scope describes the area in which a variable or item can act upon. 

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
                          lock and is outside of some_var2's scope (from the if statement) */
       
    return 0;
  }
```

In this case, `some_var` is located within a block outside of the if-statement and its scope is both outside and inside the if statement. `some_var2` is located and created inside the if-statement, therefore 
defining its scope within the if-statement only and exists only in that block. When the program exits the if-statement, `some_var2` is destroyed (which is the reason why calling `cout` on it later is illegal).

For more info, click [here](http://www.tutorialspoint.com/cplusplus/cpp_variable_scope.htm).

#### Using `break`
`break` allows you to stop execution in a block of code. You'll see these frequently used in switch cases.

Example:

```C++
  //...code...
  bool some_bool = false;
  
  if(!some_bool) //another way of saying "if some_bool is false"
  {
    cout << "Variable some_bool is false\n" << endl;
    break;
    cout << "How did you get here?" << endl;
  }
  
  //...code...
```

Output:
```
  ...
  Variable some_bool is false
  ...
```

More info (included with switch) [here](http://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm).

#### Little More With `switch`
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

Anything strange happen with any of the outputs? If so, list the errors and fix the code so that it works as intended.

More info on `switch` [here](http://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm).

#### More with `string` and `char`
Like booleans and other integer types, relational operators can be used on strings and characters. For example:

```C++
  //...code...
  char not_string = 'b';
  string not_single_char = "this is a string";
  
  if (not_string == 'b')
    //do something here
  if (not_single_char == "this is a string")    
    //do something here
  //...code...
```

When using relational operators in this case, we're really just comparing each character's integer value (a.k.a. the ASCII value). With `string`, the comparison per character is done for us.

Unfortunately, we cannot use relational operators on c-strings. For those, each individual character must manually be tested and can be quite troublesome to work with.

By including the `cctype` library into our program's code, we can also perform more various checks on individual characters. I won't go through all of them since there are a lot, but examples of using them are here:

```C++
  //...code...
  char some_char = 'Z';
  
  some_char = tolower(some_char); //sets some_char to 'z'
  
  cout << isupper(some_char); //false, as it is 'z'
  cout << isdigit(some_char); //false, it is the letter z
  cout << isalpha(some_Char); //true, 'z' is an alphabetical character
  
  //...code...
```

Just by looking at it, what do you think using `cout << isupper(toupper(some_char));` will be if we include that into the above program? Try it out in Visual Studio if you are unsure, 
and make sure to include `cctype`.

For a list of functions in the `cctype` library, check [here](http://www.cplusplus.com/reference/cctype/). For more help, try [here](http://cse.csusb.edu/dick/samples/c++.cctype.html).

#### The Conditional Operator
Something not seen too often, the conditional operator can be used to create short if/else statements. It is a ternary operator, meaning it acts upon three variables/values.

Example of a conditional operator in use (same one as the powerpoint):

```C++
  //...code...
  x < 0 ? y = 10 : z = 20;
  //...code...
```

The equivalent of this, by using an if-else statement, is as follows:

```C++
  //...code...
  if (x < 0)
    y = 10;
  else
    z = 20;
  //...code...
```

Because this is a ternary operator, it can only be used for two cases (a true and false case). Good way to remember this is by saying "__IF__ a __THEN__ b __ELSE__ c", where
`a ? b : c;`.

#### Enumerated Data Types
An extremely handy tool in programming, [enumeration](http://www.merriam-webster.com/dictionary/enumerate), or `enum`, allows us to create our own type of data type, containing a set of named 
constant integers.

When using `enum`, it is optional to give it a name. If we want to make a variable of the enumerated type though, we must give the enumeration a name. 

A C++ example of enumeration:
```C++
  //...code...
  
  #include "stdafx.h"
  #include <iostream>
  #include <cctype> //explained in "More with Strings and Characters"
  
  using namespace std;
  
  enum Months { JAN = 1, FEB, MAR, APR, MAY, JUN, 
              JUL, AUG, SEP, OCT, NOV, DEC }; //assigns values one through twelve to the constant integers
  
  int _tmain(int argc, _TCHAR* argv[])
  {
    Months first_month = JAN; //set a variable of type Months to JAN
    int month = MAY;
    
    cout << month << endl; //prints out 5
    
    month = MAY + 1; //makes month = 6 now.
    
    if(month == JUN) //if month's integer value is equal to the constant integer JUN in enum
      cout << "It is June. And it is not: " << first_month << endl;
    else
      cout << "Not June. It might be: " << first_month << endl;
    
    return 0;
  }
```

Output:
```
  5
  It is June. And it is not: 1
```

More information [here](http://www.cprogramming.com/tutorial/enum.html).

### Class Practice
All the below worksheet problems should be done by pencil/paper.

#### Worksheets
- Logical Operator Worksheet (handed out).

#### Separate Exercise
Make a program, complete with user input validation (for incorrect input), that rounds a decimal value up or down.

  Features:
  - Make sure not to use any `iomanip` features (especially for rounding).
  - __DO NOT__ use an if-else or switch statement for rounding. However, you may use either for validation.
  - Make sure that the program accounts for both positive and negative values when rounding.
  - Allow the user to input three decimal numbers to round. The user can either be prompted per number, or they can all be inputted at once.
  - If the user enters in a value that isn't a decimal value, let them know they are incorrect.

NOTE: For this exercise, refrain from using topics covered in later chapters (or outside class). Stick with Chapters 1 through 4 material.

Example outputs can be found in the folder "Example Outputs" under the files section at the top of this page.

### Extra Challenges
If you feel comfortable with all the work we've done so far, I would suggest reading ahead in our book (Chapter 5) because it's a rather hefty chapter. Plus, it's one less thing to 
worry about in the future.

Other than that, here's a list of resources/practice you may check out (that relate to Chapter 5):
  1. [Loops (look under iteration statements)](http://www.cplusplus.com/doc/tutorial/control/)
  2. [More Work on Loops](http://www.cprogramming.com/tutorial/lesson3.html)
  
  ...
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Some notes grabbed from Dr. Tian's Chapter 4 Powerpoint (located on Titanium)

Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
