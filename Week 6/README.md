# Week 6

## Contents
- [Review (Mini-quiz)](#review-mini-quiz)
- [Solutions (From Last Week)](#solutions-from-last-week)
- [Intro](#intro)
- [Psuedo-code](#psuedo-code)
- [Side note: Doubles vs. Floats](#side-note:-doubles-vs.-floats)
- Chapter 3
	- [cin](#cin)
	- [getline](#getline)
	- [iomanip](#iomanip)
	- [(More on Naming Schemes) (Constants)](#more-on-naming-schemes-constants)
	- [c-string](#c-string)
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
Above all this are the .cpp solutions from last week's exercises. For each week from now on, I'm going to place 
the solutions to the previous week's solutions there.

### Intro
Welcome guys to another week of CS 120 Lab (Yay!). Most of this page will serve as review, whereas the second 
half of it will cover topics you recently read over (specifically chapter 4).

I'd like to remind you guys that learning your first programming language is no easy task. What you guys are 
doing is learning a new language on top of learning how it works within itself. This is comparable to learning 
a language (e.g. Russian) __AND__ its culture (e.g. the compiler, IDE, etc.). Fortunately for you guys though, you won't have to speak C++.

Another thing: Like taking an intro class for Spanish, learning the beginnings of programming won't let you do 
too much. As we progress through the course, you'll begin to see more of its application to the real world. 

When looking at some of the examples on this page, I'll be typing something like:
```C++
  //...code...
```
This just means I'm too lazy to type out the entire program. The omitted syntax should be self-explanatory and 
therefore I deemed it unnecessary to include in the examples.

__OMIT?__
Also, to help understand the certain functions we'll be using, I'll describe what their parameters are. For 
instance:

```C++
  getline(istream cin, std::string input_string);
```
Lets you know that the input allowed for the `getline` function is cin (of type istream, which will be gone 
over later in the class), a string. 

__END__

Last note: Remember that, by reading this page, you can't skip the reading and lecture notes. The purpose of
this page is to help review. Both the reading and lecture notes are more insightful.

### Psuedo-code
This might be one of the weirder sections of computer science. Hopefully here it gets more clarified.

####What is psuedo-code and how do I use it?
Think of psuedo-code as a midway translation between C++ and a standard, spoken language (such as English). 
An example of translating from C++ to psuedo-code (and vice-versa if you read bottom-up):

__C++:__
```C++
  //...code...
  double lbs_of_bananas = 0, total_cost = 0;
  const double TAX_RATE = 0.75; //const explained [here](#more-on-naming-schemes-constants)
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
trying to do in your program, step-by-step. Good references for this is by looking at the teacher's example, 
located on the Titanium page, the book (if it has any), or online posts.

####Why create psuedocode? 
Although there are many reasons, here are the two that come up to my mind right now:
  1. Organization & Cleanliness
  --* Especially when creating big projects, it's good to have a set list of instructions you can refer to. 
      Without psuedocode or some sort of agenda to refer to, it's easy to lose track of what you're building 
      (and thus lose or halt progress).
  2. Outside help
  --* It's easier for someone to help you out if you tell them what you're trying to do. Imagine looking at 
      someone's math homework, but they've written extremely messy all over the place. How are you going to 
      know what they're doing unless you keep asking them over and over what they're trying to do? Some of you 
      might say "What if we type neat code?". If you end up having hundreds of lines of code, despite having neat 
      code everything starts to get messy. It's like revising an essay!
	  
Getting into a habit of creating psuedocode will help you in the longrun, especially with larger projects.

### Side note: Doubles vs. Floats
I didn't really go over floats in last week's review, so I figured I might as well cover them a bit here.

A nice reference is [this](http://www.learncpp.com/cpp-tutorial/25-floating-point-numbers/).

### Chapter 3
Below are the topics from chapter three, with brief descriptions per topic.

#### cin
When using `cin`, remember these few things:
  1. You must using `#include <iostream>` in order to use this. Note that iostream is "input/output stream"
  2. You must use the namespace `std`. Go about this by either using `using namespace std;` or `std::`.
  3. `cin` works by grabbing input up until it reaches either a space or new line (`'\n'`). 
  --* In other words, don't use `cin` if you plan to have spaces when grabbing input.
  --* If you end up putting a space, whatever is leftover goes to the next variable to be inputted.
  4. __TBD__

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
value. Now, editing the previous example, we may have something such as:

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

When doing this, the character or value read up to is called a [delimiter](http://www.thefreedictionary.com/delimiter).
This comes in handy when reading input such as social security numbers (numbers separated by '-') and when 
trying to skip parts of a line typed (namely errors in input).

#### iomanip
Mainly used for cleanliness in output, `iomanip` is a header file used for (if you guessed it) "input/output 
manipulation". In order to use this, we call `#include <iomanip>` after `iostream`.

The most commonly used manipulators are (where x is an integer):
  1. setw(x): Lets you print in a field at least x spaces wide. Uses more spaces if specified field is not big enough.
  2. fixed: Use decimal notation (not E-notation) for floating point values.
  3. setprecision(x): Two cases for this
  --* When used with fixed, it prints floating-point values using x digits (after the decimal)
  --* Without fixed, print floating-point value using x [significant digits](http://www.purplemath.com/modules/rounding2.htm)
  4. showpoint: Always prints decimal for floating-point values
  5. left/right: Left or right justification of value

NOTE: If you want to know more about floating-point values (e.g. what they mean, the difference between float and double, etc.)
click [here](http://www.learncpp.com/cpp-tutorial/25-floating-point-numbers/).
  
Example of iomanip in use:
__C++:__
```C++
  
```
#### More on Naming Schemes (Constants)
#### c-string
#### cmath and Generating Random Numbers
#### Recap

### Chapter 4
Below are the topics from chapter four, with brief descriptions per topic.

#### Booleans (Review)
Recall that booleans, or in syntax `bool`, can only hold two types of values. These values are either 
`0 (off or false)` or `1 (on or true)`. They are one byte (not one bit). Remember why?

Operators that work on booleans:
```C++
  bool some_bool = false; //set to false (or 0)
  some_bool = (10 < 0); //less than operator (some_bool = false)
  some_bool = (14 > 2); //greater than operator (some_bool = true)
  some_bool = (55 >= 55); //greater than or equal to (some_bool = true)
  some_bool = (44 <= 43); //less than or equal to (some_bool = false);
```
Remember also that there are three other operators that work on these, `! (not)`, `|| (or)`, and 

Like using the assignment operator on other various data types, you can combine multiple operators when 
assigning a value to a bool. 
Example of this in use:

```C++
  
```


#### if-else
#### switch
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
me. I know this might seem both tedious and annoying to do, but keep in mind that this (like the rest of the 
work in this course) is to help you build a knack on programming (fix this line asdlfksd). Practice makes
(near) perfection!
	
#### Remake a previous program (dunno yet)
#### Conversion program (SI Units) (?) [best with arrays though...]

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Some notes grabbed from Dr. Tian's Powerpoint
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>

