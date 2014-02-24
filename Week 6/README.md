# Week 6

## Contents
- [Review (Mini-quiz)](#review-mini-quiz)
- [Solutions (From Last Week)](#solutions-from-last-week)
- [Intro](#intro)
- [Psuedo-code](#psuedo-code)
- [Bits, Bytes, Bases & Range](#bits,-bytes,-bases-&-range)
- [Side note: Doubles vs. Floats](#side-note:-doubles-vs.-floats)
- Chapter 3
	- [cin](#cin)
	- [getline](#getline)
	- [iomanip](#iomanip)
	- [(More on Naming Schemes) (Constants)](#more-on-naming-schemes-constants)
	- [c-string vs string](#c-string-vs-string)
	- [cmath and Generating Random Numbers](#cmath-and-generating-random-numbers)
	- [Recap](#recap)
- Chapter 4
	- [Booleans (Review)](#booleans-review)
	- [if-else](#if-else)
	- [More with if-else](#more-with-if--else)
	- [switch statements](#switch-statements)
	- [Menu-driven programming] (?)
	- [Recap](#recap-1)
- Practice Assignments(#practice-assignments)
	- Design your own calculator!
	- Remake a previous program (dunno yet)
	- Conversion program (SI Units) (?) [best with arrays though...]

### Review (Mini-Quiz)
Alright guys. For the first five or so minutes of class I'd like you all to briefly review your notes from 
chapters 1 to 4. Use the lecture notes, book, and my online notes to help you all out. I'll have the questions 
on the projector.

Another note: I don't know exactly how Dr. Tian will make your exams, and this is only a guess on my part.

__TO-DO__

### Solutions (From Last Week)
Above this are the .cpp solutions from last week's exercises. For each week from now on, I'm going to place 
the solutions to the previous week's solutions there.

### Intro
Most of this page will serve as review, whereas the second half of it will cover topics you recently read over 
(specifically chapter 4). It will be handy to have open a Visual Studio C++ project when looking through each topic.

When looking at some of the examples on this page, I'll be typing something like:
```C++
  //...code...
```
This just means I'm too lazy to type out the entire program. The omitted syntax should be self-explanatory and 
therefore I deemed it unnecessary to include in the examples.

Last note: Remember that, by reading this page, you can't skip the reading and lecture notes. The purpose of
this page is to help review. Both the reading and lecture notes are more insightful.

### Psuedo-code
####What is psuedo-code and how do I use it?
Think of psuedo-code as a midway translation between C++ and a standard, spoken language (such as English). 
An example of translating from C++ to psuedo-code (and vice-versa if you read bottom-up):

__C++:__
```C++
  //...code...
  double lbs_of_bananas = 0, total_cost = 0;
  const double TAX_RATE = 0.75; //const explained under CH3, "More on Naming Schemes (Constants)"
  const double COST_PER_LB = 0.69;
  
  cout << "How many pounds of bananas will you buy? ";
  cin >> lbs_of_bananas;
  
  total_cost = lbs_of_bananas * COST_PER_LB * TAX_RATE;
  
  cout << "Total cost of purchase: " << total_cost << endl;
  //...code...
```

__Psuedo-code:__
```
  1. Create and initialize local variables for lbs of bananas, total cost, tax rate, and cost per lb
  2. Request user to input the pounds of bananas they want to buy
  3. Input lbs of bananas
  4. Calculate total cost
  5. Output the total cost of purchase
```

There is no specific way to write psuedo-code (sorry). Just make sure that it explains well enough what you're 
trying to do in your program, step-by-step. Apart from this, the teacher's notes on Titanium covering this can 
help if you're stuck on this.

####Why create psuedocode? 
Although there are many reasons, here are the two that come up to my mind right now:
  1. Organization & Cleanliness
    - Especially when creating big projects, it's good to have a set list of instructions you can refer to. 
      Without psuedocode or some sort of agenda to refer to, it's easy to lose track of what you're building 
      (and thus lose or halt progress).
  2. Outside help
    - It's easier for someone to help you out if you tell them what you're trying to do. Imagine looking at 
      someone's math homework, but they've written extremely messy all over the place. How are you going to 
      know what they're doing unless you keep asking them over and over what they're trying to do?
	  
Getting into a habit of creating psuedocode will help you in the longrun, especially with larger projects.

### Bits, Bytes, Bases & Range
If I get enough people asking about this topic, I'll try my best to explain up on the board on this topic with more detail.
Other than that, the following links should explain bits, bytes, bases and range pretty well:

[Bits and Bytes](http://computer.howstuffworks.com/bytes1.htm)
[Converting Bases](http://www.cplusplus.com/doc/hex/)
[Determining Size of a Datatype](http://www.tutorialspoint.com/cplusplus/cpp_sizeof_operator.htm)
[Range of Values (check posts in thread)](http://www.cplusplus.com/forum/beginner/44774/)

### Side note: Doubles vs. Floats
I didn't really go over floats in last week's review, but a nice reference is [this](http://www.learncpp.com/cpp-tutorial/25-floating-point-numbers/) 
if you would like know about the differences between the two.

### Chapter 3
#### cin
When using `cin`, remember these several things:
  1. You must using `#include <iostream>` in order to use this. Note that `iostream` is shorthand for "input/output stream"
  2. You must use the namespace `std`. Go about this by either using `using namespace std;` or `std::` before `cin`.
  3. `cin` works by grabbing input up until it reaches either a space or new line (`'\n'`). It must grab
  ··* Don't use `cin` if you plan to have spaces when grabbing input.
  ··* If you end up putting a space, whatever is leftover goes to the next variable to be inputted.

Example of using `cin`:
```C++
  //...code...
  int num1, num2;
  num1 = num2 = 0; //initialization
  cout << "Enter in two integers: ";
  cin >> num1 >> num2;
  
  cout << "Here they are added together: " << (num1 + num2) << endl;
  //...code...
```
**Console Output:**
```
  ...
  Enter in a value: 5 5
  Here they are added together: 10
  ...
```

#### getline
Like `cin`, `getline` requires iostream and the standard namespace. Unlike `cin` though, as told by its name, 
the `getline` function can grab and throw an entire line into a variable. It only works for the `string` 
datatype though.

Example of `getline` in use:
**C++:**
```C++
  //...code...
  std::string some_string = "";

  std::cout<<"Enter in two words (separated by a space): ";
  std::getline(std::cin, some_string);
  
  std::cout<<"Here are the two words you inputted: "<<some_string<<"\n";
  //...code...
```
__Console Output:__
```
  ...
  Enter in two words (separated by a space: two words
  Here are the two words you inputted: two words
  ...
```
Another neat thing about `getline` is that it can be edited so that you can read up to a certain character or 
value (instead of `\n`). Now, editing the previous example, we may have something such as:

__C++:__
```C++
  //...code...
  std::cout<<"Enter in two words (separated by a space and ends with |): ";
  std::getline(std::cin, some_string, '|'); //reads up to '|'
  
  std::cout<<"Here are the two words you inputted: "<<some_string<<"\n";
  //...code...
```
__Console Output:__
```
  ...
  Enter in two words (separated by a space: two words|
  Here are the two words you inputted: two words
  ...
```

When doing this, the character or value scanned for is called a [delimiter](http://www.thefreedictionary.com/delimiter).

#### iomanip
Mainly used for cleanliness in output, `iomanip` is a header file used for (if you guessed it) "input/output 
manipulation". In order to use this, we call `#include <iomanip>` after `iostream`.

The most commonly used manipulators are (where x is an integer):
  1. `setw(x)`: Lets you print in a field at least x spaces wide. Uses more spaces if specified field is not big enough.
  2. `fixed`: Use decimal notation (not E-notation) for floating point values.
  3. `setprecision(x)`: Two cases for this
  ··* When used with fixed, it prints floating-point values using x digits (after the decimal)
  ··* Without fixed, print floating-point value using x [significant digits](http://www.purplemath.com/modules/rounding2.htm)
  4. `showpoint`: Always prints decimal for floating-point values
  5. `left/right`: Left or right justification of value

NOTE: If you want to know more about floating-point values (e.g. what they mean, the difference between float and double, etc.)
click [here](http://www.learncpp.com/cpp-tutorial/25-floating-point-numbers/).
  
Example of iomanip in use:
__C++:__
```C++
  TBD
```
#### More on Naming Schemes (Constants)
To declare a constant (that is, a variable that won't change after creating it), do as such:
```C++
  const double TAX_RATE = 0.75;
  const string MY_NAME = "John Smoth";
  const float SOME_FLOAT = 5.6f;
```

Notice that the identifier is capitalized. It's just another way to read through code easier.

Also, taking note that the values do not change over time, try the following code out in Visual Studio: 
```C++
  #include "stdafx.h"
  #include <iostream>

  int _tmain(int argc, _TCHAR* argv[])
  {
    const float SOME_FLOAT = 5.6f;

    SOME_FLOAT+=55;

    std::cout << SOME_FLOAT;
  }
```
What happens when you try to compile it?

#### c-string vs string
#### cmath and Generating Random Numbers
##### cmath
The `cmath` header lets you use specific math functions, such as `tan` (tangent), `sqrt` (square root), and more. A 
more complete list can be found [here](http://www.cplusplus.com/reference/cmath/).

##### Random Numbers
Through the header file `cstdlib`, you can use both the `rand` function. `rand` outputs a random number (between 0 and 
some maximum integer set by the compiler). 

Note that, when calling `rand`
#### Recap

### Chapter 4
#### Booleans (Review)
Recall that booleans, or in syntax `bool`, can only hold two types of values. These values are either 
`0 (off or false)` or `1 (on or true)`. They are one byte (not one bit). Remember why?

Another important note: When setting a boolean to any integer value other than `0` sets the bool to `true`. If is zero, 
it is false. Else, it is true.

##### Operators that Work on Booleans
```C++
  //...code...
  bool some_bool = false; //initialization
  some_bool = (10 < 0); //less than operator
  some_bool = (14 > 2); //greater than operator
  some_bool = (55 >= 55); //greater than or equal to
  some_bool = (44 <= 43); //less than or equal to
  //...code...
```
Try guessing the value of `some_bool` after each line. Afterwards, check using the compiler. You can use `cout` to help 
check what the value is after each line.

Remember also that there are three other operators that work on these, `! (NOT)`, `|| (OR)`, and `&& (AND)`.
Reusing the variable in the above example:
```C++
  //...code...
  some_bool = !some_bool;
  some_bool = (true || false);
  some_bool = (false && true);
  some_bool = (7 || 0);
```
guess and then check what the outputs are using the compiler.

##### Combining Operators into one Assignment
Like using the assignment operator on other various data types, you can combine multiple operators when 
assigning a value to a bool. 
Example of this in use (reusing `some_bool`):
```C++
  //...code...
  some_bool = (55 || 66) && !(0 || 3);
  //...code...
```
Guess first, then check your answer by outputting the above in a Visual Studio project.

For more help with AND, NOT, and OR, look under the topic "Logical Operator" on [this page](http://www.cplusplus.com/doc/tutorial/operators/).

#### if-else
`if` and `else` statements help with directing flow of a program. 
#### switch
Similar to using if-else statements, `switch` statements help when testing a variable's value. For example, if 
we wanted to test whether or not 
#### Menu-driven programming
#### Recap
### Practice Assignments
#### Design your own calculator!
Described quite well by the above title, using the knowledge from the above review, the lecture notes, and 
the book, create your own calculator program that allows the following things:
	1. Simple algebra (addition, subtraction, multiplication, division)
	2. Square root of a number and raising a number to an exponent
	3. Modulus (you should know what this means by now)
	4. Iunno.

Remember that the best approach to making a program is by creating it through psuedocode first. For that 
reason, **BEFORE** you begin programming make sure to validate your psuedocode with another person __AND__
me.
	
#### Remake a previous program (dunno yet)
#### Conversion program (SI Units) (?) [best with arrays though...]

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Some notes grabbed from Dr. Tian's Powerpoint
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>

