# Week 5

## Contents
- Exercise & Setup
- Intro
- Variables
	- Identifiers and Naming Scheme
	- Data Types
		- Integers
		- Doubles
		- Char
		- Strings
		- Bool
	- Assignment Operator & Type Coercion
	- Basic Arithmetic
	- Overflow/Underflow
	- When to Use Each Type
	- Attached Exercise (Geometric Shapes: Area and Volume)
	- Extra: Simple Control Flow (`if`, `else`)
- Continuing Challenges
- Notes

### Exercise & Setup

As usual, load up Visual Studio and create a project using the "Win32 Application" option.
Name it whatever you'd like (best to have the name pertain to what you're working on though). 
Most of this exercise will deal with reading though, with some examples and an attached
exercise at the end of it.

Make sure to set the directory to your desktop, so you can easily refer to the files outside
of the IDE.

If you get done early, please help a friend nearby. If you don't have any, and can
bear making new ones, find and make one then help them out.

Most of this work is review on the lecture and labs, so if you feel completely comfortable
with variables feel free to skip to the section labeled "Attached Exercise".

### Intro

In the lecture and lab, we saw a little bit of how variables work. For instance:

```C++
  int age;
  age = 17;
```

assigns the value `17` to the integer `age`. Also,

```C++
  cout << age << endl;
```

results in the console printing out `17`.

Going more in-depth, we'll look more into these in the following sections.

### Variables
Like in math, variables are items that can hold values. Unlike math though, in computer 
science a variable can be reassigned a different value later on.

Remember that variables are names for locations in memory and that computers do things 
step by step. Also, if a variable is reassigned a value later on, it "forgets" the previous 
value assigned to it for the remainder of the program.

Variables have three parts to them: Data type, identifier, and the value assigned to each 
variable.

#### Identifiers & Naming Scheme
When creating variables, you always need to an identifier assigned to each. For instance, in
the following C++ syntax:

```C++
  int depth = 70;
```

we see that our variable's identifier is `depth`. This helps us understand what we're using the 
variable for (and in this case, it's to tell us the depth of whatever we have).

Going on more with this, think about how important the naming scheme is for a variable. If, 
for example, we set up two variables as the following:

```C++
   int something = 324566;
   int numOfSeeds = 324566;
```

there is a BIG difference in knowing what the stored value does and is for. In the first line,
all we know is that it is an integer and it is set to some number. The second variable, however, 
lets a programmer reviewing your code know that the value tells the reader how many seeds there 
are.

There are two ways to represent spaces within an identifier. There is no specific rule
of thumb for this, but looking at the following example judge whichever one you prefer and stick
to it.

```C++
	int numberOfBananas = 0; //this is called camel case
	int number_of_bananas = 0; //underscores for spaces
```

lastly, when creating identifiers for your variables, it is up to you to determine whether or not to 
sacrifice legibility or the time it takes to type it out. Look at the following example and determine
for yourself which one would suit yourself and others reviewing your program:

```C++
  int numSales;
  int num_of_sales;
  int nms;
  int number_of_sales;
  //etc.
```

Overall, like the rest of your code, think about the future when looking back on your work. What typing
style do you think works best?

#### Data Types
Although there are MANY different types of data types , you won't be using every single one 
in this course. There are five, however, that come up the most often. These are:
`int`, `double`, `char`, `string`, and 'bool'.

It's good to know the other types, such as 'float', although you won't be seeing them 
as much (or at least I haven't).

For future reference, a byte is a list of 8 bits, whereas a bit is a `0 (off)` or `1 (on)` 
value.

Each data type has its own byte-size, that is, the amount of memory it takes up in RAM. Although
the following reference goes over the file sizes, we'll be going over them too in the following
sections.

[Variables and types in C++] (http://www.cplusplus.com/doc/tutorial/variables/)
[Range of Data Types in Visual Studio C++] (http://msdn.microsoft.com/en-us/library/s3f49ktz%28v=vs.80%29.aspx)

Note that the range and size of each data type depends on the compiler you're working
with. In our case, we're only working with Visual Studio.

##### Integers
Known in syntax as `int`, integers are numbers such as `0, 1, -57, ...` and so on. 

As an integer is 4 bytes long, we know then that it is `4 * 8 = 32` bits long. From there, we
then can figure out the following:

	`unsigned int: ranges from 0 to 2^32 - 1` (`-1` to account for the `0`)
	`signed int: ranges from -2^31 to 2^31 - 1 (`31` instead of `32` to account for `-`, and 
																							`-1` to account for `0`)

Like in the previous sections, here's an example of creating an integer in code:

```C++
  int some_integer = 42;
  cout << some_integer << endl;
```

which outputs `42` in console.

##### Doubles
Known in syntax as `double`, doubles are similar to the `int` data type, except they are 
for decimal values. Refer to the reference under "Data Types" for exact byte-size and range.

Here's an example of this in code:

```C++
  double some_double = 2.7;
  cout << some_double << endl;
```

which outputs `2.7`.

##### Characters
The character data type, or `char`, holds single characters. These include values such as 
`a, b, z, -, ...` and so on. 

##### Strings
The string data type, or `string`, is unlike the other data types on this list. For one thing, 
it requires its own special header to be able to use it. Another thing is it isn't a 
[primitive data type] (). If you think about it, what are strings composed of?



##### Bool
The bool data type, or `bool`, hodls either a `true` or `false` value. Not necessarily too
useful for us yet, in the next chapter we'll be using this data type frequently. For now, we 
can use this 

#### Assignment Operator & Type Coercion
As you've seen already in the previous examples, the assignment operator "assigns" a value 
to a variable. The value assigned to the variable depends solely on the data type of the
variable.



#### Overflow/Underflow
Try the following code in a project (don't read ahead though):

```C++
  #include "stdafx.h"
  #include <iostream>

  using namespace std;

  int _tmain(int argc, _TCHAR* argv[])
  {
    int max_signed_int = 2147483647; //2^31 - 1
    unsigned int max_unsigned_int = 4294967295;  // 2^32-1 = 4294967295
    
    cout << "Here is the maximum integer count: " << max_signed_int << endl;
    cout << "Here is the maximum integer count + 1: " << 1 + max_signed_int << endl;

    cout << "Here is the maximum unsigned integer count: " << max_unsigned_int << endl;
    cout << "Here is the maximum unsigned integer count + 1: " << 1 + max_unsigned_int << endl;

    return 0;
  }
```

Notice anything funky here? With overflow and underflow, after the maximum integer value surpasses
its maximum value, it "loops" around to the minimum value and continues from there. Depending on 
the data type and compiler you use, different effects may occur.

#### When to Use Each Data Type
Before, when memory wasn't bountiful and filesizes mattered, programmers had to focus heavily
on the data types and amount of code they produced.

You can also check the byte-size of a data type by using `sizeof()`, where inside
the parenthesis you place the variable. For example:
```C++
  cout << sizeof(52) << endl;
```

Since `52` is an integer constant, the output is `4` (the byte-size of an integer value).

Another thing: As with most things, there is a time and place for using each variable. Unfortunately, 
There isn't necessarily a bulletproof plan for knowing when to use each, so just think about what you're 
doing and what you'll need to accomplish the task.

#### Attached Exercise (Geometric Shapes: Area and Volume)
Above there is a .docx file. Download it to your computer, open it, and follow the instructions from there.

#### Extra: Simple Control Flow (`if`, `else`)
A preview of what you'll be learning in Chapter 4, `if` and `else` statements 

Random bold here. I'm not sure how to fix this at the moment.
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>

