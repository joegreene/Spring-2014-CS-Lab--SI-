# Week 6

## Contents
- [Solutions (From Last Week)](#solutions-from-last-week)
- [Intro](#intro)
- [Psuedo-code](#psuedo-code)
- [Bits, Bytes, Bases & Range](#bits-bytes-bases--range)
- [Side note: Doubles vs. Floats](#side-note-doubles-vs-floats)
- Chapter 3
	- [cin](#cin)
	- [getline](#getline)
	- [iomanip](#iomanip)
	- [More on Naming Schemes (Constants & Macro Definitions)](#more-on-naming-schemes-constants--macro-definitions)
	- [c-string vs string](#c-string-vs-string)
	- [cmath and Generating (Psuedo-)Random Numbers](#cmath-and-generating-psuedo-random-numbers)
- Chapter 4
	- [Booleans (Review)](#booleans-review)
	- [if-else](#if-else)
	- [More with if-else](#more-with-if--else)
	- [switch statements](#switch-statements)
	- [Menu-driven programming](#menu--driven-programming)
- [Practice Assignments](#practice-assignments)
	- Design your own calculator
	- Guessing Game
	- Conversion program (SI Units) (?) [best with arrays though...]

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

Also, although I thank you guys for reading this work I made for you guys, you can't use this as a substitute for 
the book and the lecture notes. This page only serves as both review of the notes and further practice.

### Psuedo-code
####What is psuedo-code and how do I use it?
Think of psuedo-code as a midway translation between C++ and a spoken language (such as English). 
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
Two main reasons I can think of right now (there are probably more):
  1. Organization & Cleanliness
    - Especially when creating big projects, it's good to have a set list of instructions you can refer to. 
      Without psuedocode or some sort of agenda to refer to, it's easy to lose track of what you're building 
      (and thus lose or halt progress).
  2. To Help Others Help You
    - It's easier for someone to help you out if they can refer to a list of what you're trying to accomplish. Imagine 
      looking at someone's math homework, but they've written extremely messy all over the place. How are you going to 
      know what they're doing unless you keep asking them over and over what steps they took?
	  
Getting into a habit of creating psuedocode will help you in the longrun, especially with larger projects. If you'd like 
more information on psuedo-code, check [this wikipedia article](http://en.wikipedia.org/wiki/Pseudocode).

### Bits, Bytes, Bases & Range
If I get enough people asking about this topic, I'll try my best to explain up on the board on this topic with more detail.
Other than that, the following links should explain bits, bytes, bases and range pretty well:

[Bits and Bytes](http://computer.howstuffworks.com/bytes1.htm)

[Converting Bases](http://www.cplusplus.com/doc/hex/)

[Determining Size of a Datatype](http://www.tutorialspoint.com/cplusplus/cpp_sizeof_operator.htm)

[Range of Values (check posts in thread)](http://www.cplusplus.com/forum/beginner/44774/)

### Side note: Doubles vs. Floats
I didn't really go over floats in last week's review, but a nice reference is [this](http://www.learncpp.com/cpp-tutorial/25-floating-point-numbers/) 
if you would like know about the differences between the two. I'm pretty sure the book has some information as well.

### Chapter 3
#### cin
When using `cin`, remember these few things:

  1. You must using `#include <iostream>` in order to use this. Note that `iostream` is shorthand for "input/output stream"
  2. You must use the namespace `std`. Go about this by either using `using namespace std;` or `std::` before `cin`.
  3. `cin` works by grabbing input up until it reaches either a space or new line (`'\n'`).
    - Don't use `cin` if you plan to have spaces when grabbing input. Instead, use `getline`.
    - If you end up putting a space, whatever is leftover goes to the next variable to be inputted (or it gets left in the stream 
      until the program closes).

Example of using `cin`:
```C++
  //...code...
  int num1, num2;
  num1 = num2 = 0; //good practice to initialize, even before using cin
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
  Enter in two words (separated by a space): two words
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
  Enter in two words (separated by a space and ends with |): two words|
  Here are the two words you inputted: two words
  ...
```

When doing this, the character or value scanned for is called a [delimiter](http://www.thefreedictionary.com/delimiter).

__TIP:__ If you would like to, you can convert strings to other datatypes. For more information, look [here](http://www.cplusplus.com/reference/string/).

#### iomanip
Mainly used for cleanliness in output, `iomanip` is a header file used for (if you guessed it) "input/output 
manipulation". In order to use this, we call `#include <iomanip>` after `iostream`.

##### Various Manipulators
The most commonly used manipulators are (where x is an integer):
  1. `setw(x)`: Lets you print in a field at least x spaces wide. Uses more spaces if specified field is not big enough.
  2. `fixed`: Use decimal notation (not E-notation) for floating point values.
  3. `setprecision(x)`: Two cases for this
    - When used with fixed, it prints floating-point values using x digits (after the decimal)
    - Without fixed, print floating-point value using x [significant digits](http://www.purplemath.com/modules/rounding2.htm)
  4. `showpoint`: Always prints decimal for floating-point values
  5. `left/right`: Left or right justification of value

NOTE: If you want to know more about floating-point values (e.g. what they mean, the difference between float and double, etc.)
click [here](http://www.learncpp.com/cpp-tutorial/25-floating-point-numbers/).

Example of iomanip in use (copied directly from the lecture notes):

__C++:__
```C++
  //...code...
  const float e = 2.718;
  float price = 18.0;
  cout << setw(8) << e << endl;
  cout << left << setw(8) << e
       << endl;
  cout << setprecision(2);
  cout << e << endl;
  cout << fixed << e << endl;
  cout << setw(6) << price;
  //...code...
```
__Output:__
```C++
     2.718 (three spaces in front)
  2.718    (three spaces in end, left justification)
  2.7      (setprecision using x digits)
  2.72     (setprecision using x amount of sig figs)
   18.00   (one space at start to fill 6 spots)
```

More info on iomanip [here](http://www.cprogramming.com/tutorial/iomanip.html).

#### More on Naming Schemes (Constants & Macro Definitions)
##### Declaration
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

##### Macro Definitions
Although less used now because it's the C-standard, when looking at code you might see something called `#DEFINE`. They 
are just another way to declare constants.

Example of a macro definition in use:
```C++
  #include "stdafx.h"
  #include <iostream>
  #define TAXES .75
  
  int _tmain(int argc, _TCHAR* argv[])
  {
    cout << "Tax rate is currently: " << TAXES << endl; //prints ".75"
    
    return 0;
  }
```

For more information on these, click [here](http://www.cprogramming.com/tutorial/cpreprocessor.html) (under "Macros").

#### c-string vs string
I think [this page](http://www.prismnet.com/~mcmahon/Notes/strings.html) explains their differences quite well. If there is any confusion 
about what is on this page, don't hesitate to ask. 

One confusing part however is understanding the term "array". We'll talk more about them later in the course, but for now 
think of them as "a list of something". Therefore, when we see "character array" we're talking about "a list of characters".

##### c-strings
The C-standard way of making C++ strings, these are normally avoided because they're finicky to work with and initialize. 

For a list of c-string functions, go [here](http://www.cplusplus.com/reference/cstring/). Other than that, check the powerpoint notes for 
more information as well (slides 34 through 42).

##### Strings
The C++-standard way of making c-strings. These are normally used because they are easier to initialize and work with overall.

For a list of string functions, go [here](http://www.cplusplus.com/reference/string/). Other than that, check the powerpoint notes for 
more information as well (slides 34 through 42).

#### cmath and Generating (Psuedo-)Random Numbers
##### cmath
The `cmath` header lets you use specific math functions, such as `tan` (tangent), `sqrt` (square root), and more. A 
more complete list can be found [here](http://www.cplusplus.com/reference/cmath/). Click on the ones you're curious about 
and they will explain each function within `cmath` pretty well.

NOTE: Keep in mind that, with each function, they require a specific type of input to be used. Remember in the last lab how we 
were getting errors when inputting an integer for `sqrt`? That's because it required `double` for its input. Take a look at the output log 
(located below your code) if you get errors when using a cmath function (or any really).

For more information as well, check the powerpoint (page 43).

##### (Psuedo-)Random Numbers
Through the header file `cstdlib`, you can use the `rand` function. `rand` outputs a "random" number (between 0 and some maximum integer set by the compiler).

When using and creating values through `rand`, there are two key things to think about:

  1. Range of a value
    - To set the range of a value, use % for range
  2. Lower limit (starting position)
    - To set the lower limit, use + or - for starting value

Example usage of `rand`:
```C++
  //...code 
  int some_num = rand() % 10 + 1; //range of the random value is from 1 to 10
  some_num = rand() % 100 - 20; //random value from -20 to 80
  some_num = rand() % 30 + 1900; //random value from 1900 to 1930
  //...code...
```

Try compiling and running the following a few times in Visual Studio:
```C++
  #include "stdafx.h"
  #include <iostream>
  #include <cstdlib>
  #define MAX 30 //c-standard macro
  using namespace std;
    
  int _tmain(int argc, _TCHAR* argv[])
  {
    int some_num = rand() % MAX + 1; //range of the random value is from 1 to MAX
    cout << some_num << endl;
    return 0;
  }
```
Notice anything weird with the output? Look at the next section for more details if so.

More information on using `rand` [here](http://www.cplusplus.com/reference/cstdlib/rand/).

##### Seed Number (for Randomization)
Note that in the title before this topic I used the prefix "psuedo-" (meaning "fake"). That's because there's a specific formula used to create the `rand` value.
By calling `srand`, we can (re-)initialize the number generator each time we run a program.

To call `srand` we use the `cstdlib` library/header, and to use the `time` function (something typically required with `srand` to re-initialize the psuedo-random number generator well) we include the library/header `ctime`.

Go back to the `rand` example, plug in the following (either one) before the initialization of `some_num` and still inside `main`, and notice the difference after compiling and running a few times.
```C++
  unsigned seed = time(0);
  srand(seed);
  
  OR (as a quicker way to type it)
  
  srand(time(0));
```
Remember as well to include the `ctime` header too, as required. It should be generating properly now. 

More info on using `srand` [here](http://stackoverflow.com/questions/7748071/same-random-numbers-every-time-i-run-the-program) and [here](http://www.cplusplus.com/reference/cstdlib/srand/). 
Also, check pgs 43 and 44 of the powerpoint.

### Chapter 4
#### Booleans (Review)
Recall that booleans, or in syntax `bool`, can only hold two types of values. These values are either 
`0 (off or false)` or `1 (on or true)`. They are one byte (not one bit). Remember why?

Another important note: When setting a boolean to any integer value other than `0` sets the bool to `true`. If is zero, 
it is false. Else, it is true.

##### Boolean Operators
Example of the `> (greater than)`, `< (less than)`, `== (equal to)`, `>= (greater than or equal to)` and `<= (less than or equal to)` operators.
```C++
  //...code...
  bool some_bool = false; //initialization
  some_bool = (10 < 0);
  some_bool = (14 > 2);
  some_bool = (some_bool == false);
  some_bool = (55 >= 55);
  some_bool = (44 <= 43);
  //...code...
```
Try guessing the value of `some_bool` after each line. Afterwards, check using the compiler. You can use `cout` to help 
check what the value is after each line.

##### More Boolean Operators
Remember also that there are three other operators that work on booleans: `! (NOT)`, `|| (OR)`, and `&& (AND)`.
Reusing the variable in the above example:
```C++
  //...code...
  some_bool = !some_bool;
  some_bool = (true || false);
  some_bool = (false && true);
  some_bool = (7 || 0);
  //...code...
```
Guess and then check what the outputs are using the compiler.

##### Combining Operators into one Assignment
Like using the assignment operator on other various data types, you can combine multiple operators when 
assigning a value to a bool. 
Example of this in use (reusing `some_bool`):
```C++
  //...code...
  some_bool = (55 || 66) && !(0 || 3);
  //...code...
```
Guess first, then check vai the compiler.

For more help with AND, NOT, and OR, look under the topic "Logical Operator" on [this page](http://www.cplusplus.com/doc/tutorial/operators/).

#### if-else
`if` and `else` statements help with directing flow of a program. They're namely for boolean operations.

Example of if/else statements in use:
```C++
  //...code...
  bool some_bool
  if(some_bool) //another way of checking if a boolean is true
  {
    cout << "some_bool is true!";
  }
  else
    cout << "some_bool is false!";
```

Note in the above example that one case used curly braces, and the other does not. If you only have one line after the if/else statement, 
then you may omit the curly braces.

##### Joining Multiple if-else statements
In order to use multiple
#### switch
Similar to using if-else statements, `switch` statements help when testing a variable's value. `switch` statements can 
only be used to test a single, integer-type value though.

Example usage:
```C++
  //...code...
  char c = 'n'; //initialization
  cin>>c;
  switch(c)
  {
    case 'a': //if user inputted 'a'
      cout<<"You inputted \'a\'. Cool.\n";
      break;
    case 'b': //if user inputted 'b'
      cout<<"You inputted \'b\'. Okay...\n";
      break;
    default:
      cout<<"Unchecked/Unknown input. That means your input wasn't \'a\' or \'b\'. Commencing self-destruct sequence...\n";
      break;
  }
  //...code...
```
It's always a good idea to include a `default` case. It makes your program more [robust](http://www.linfo.org/robust.html) 
and helps if a user mistypes input. It's always better safe than sorry!

Switch cases can be combined as well. For example: 
```C++
  //...code...
  switch(grade)
  {
    case 'A':
    case 'a':
    case 'B':
    case 'b':
      cout << "You passed! Nice grade!\n";
      break;
    case 'C':
    case 'c':
      cout << "You passed! Should've done better though...\n";
      break;
    case 'D':
    case 'd':
      cout << "Can't tell if you passed or not. Consult the professor.\n";
      break;
    case 'F':
    case 'f':
      cout << "You didn't pass. Sorry about that.\n";
      break;
    default:
      cout << "I have no idea what your grade is. Consult a psychiatrist or re-input your grade.\n";
  }
  //...code...
```
Lets you mix characters `a, A, b, B` together, `c, C`, together, and so on.
#### Menu-driven programming
When someone says that their program is "menu-driven", it just means that a menu is printed to console, listing options 
for a user to choose. Afterwards, input is tested using if-else or switch statements. They're typically used at the start 
of a program.

An example of a menu-driven program:
```C++
  //...code...
    cout << "Choose below your desired choice.\n"
    cout << "Choice 1: Buy products\n";
    cout << "Choice 2: Sell products\n";
    cout << "Choice 3: View more options\n";
    cout << "Choice 4: Exit program\n";
    cout << "Enter in your number choice: ";
  //...code...
```

They might seem annoying to type out, but they surely make your program look neater to users in console.

### Practice Assignments
Try to do these without your notes. That way, you can test yourself and see if you actually know the material. If you're absolutely stuck, ask a friend, then 
begin referring to other sources.

#### Design your own calculator
Using the knowledge from the above review, the lecture notes, and the book, create your own calculator program that contains 
these following things:

	1. Simple algebra (addition, subtraction, multiplication, division) 
	2. Modulus (of two integers)
  3. A menu (so the user knows how to input numbers and operations)

__NOTE:__ Remember that the best approach to making a program is by creating it through psuedocode first. For that 
reason, **BEFORE** you begin programming make sure to validate your psuedocode with another person.

__BONUS:__ Allow the user to set the amount of significant digits to be outputted.

__BONUS-2:__ Allow the user to use the square root, power, and logarithm (base-10) functions. 

[Example Outputs](http://imgur.com/a/BYgY6)

#### Guessing Game
Create a program that asks a user to guess a value within a range, and see if the value is right.
Here are the specifications:
  1. Must generate and allow the user to guess a randomly-generated number. 
    - For the user's sake, have the range between 0 and some small max. Set the max by using a constant integer.
  2. Must tell the user whether or not their value is above or below the randomly-generated number
  3. Tell the user the random number (if they guess wrong).
  
Like the previous assignment, make sure to create psuedo-code and validate it with another group before programming.

[Example outputs](http://imgur.com/a/4HJlR)

__TIP:__ For test purposes, you might want to set your "randomly generated" integer to a fixed value. For mine, I used `2`.

__TIP-2:__ If your program keeps generating the same randomly-generated number (when using the correct function), refer to the topic about random numbers on this page.

...
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Some notes grabbed from Dr. Tian's Chapter 3 Powerpoints
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>