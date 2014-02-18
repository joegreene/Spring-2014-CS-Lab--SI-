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
	- Basic Arithmetic
	- When to Use Each Type
	- Attached Exercise (Geometric Shapes: Area and Volume)
	- Extra: Simple Control Flow (`if`, `else`)
- Continuing Challenges
- Notes

### Exercise & Setup

As usual, load up Visual Studio and create a project using the "Win32 Application" option.

Make sure to set the directory to your desktop, so you can easily refer to the files outside
of the IDE.

If you get done early, please help a friend nearby. If you don't have any, and can
bear making new ones, find and make one then help them out.

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

resulted in the console printing out `17`.

TBD asdfasdf

### Variables
Like in math, variables are items that can hold values. Unlike math though, in computer 
science a variable can be reassigned a different value later on.

Remember that variables are names for locations in memory and that computers do things 
step by step. 

Variables have three parts to them: Data type, identifier, and the value assigned to each 
variable.

#### Identifiers & Naming Scheme
When creating variables, you always need to an identifier assigned to each. For instance, in
the following C++ syntax:

```C++
  int number_of_apples = 70;
```

we see that our variable's identifier is `number_of_apples`. This helps us understand what
we're using the variable for (and in this case, it's to tell us the number of apples we have).

Going on more with this, think about how important the naming scheme is for a variable. If, 
for example, we set up two variables as the following:

```C++
   int 
   
```

#### Data Types
Although there are MANY different types of data types , you won't be using every single one 
in this course. There are five, however, that come up the most often. These are:
'int', 'double', 'char', 'string', and 'bool'.

It's good to know the other types, such as 'float', although you won't be seeing them 
as much.

We'll go over the main five in the following sections.

##### Integers
Known in syntax as `int`, integers are numbers such as `0, 1, -3, ...` and so on. These
are mainly used for 

##### Doubles
Known in syntax as `double`, doubles are similar to the `int` data type, except they are 
for decimal values.

##### Characters
The `char`

##### Strings
The string data type, or `string`, is unlike the other data types on this list.

##### Bool
The bool data type, or `bool`, is 

Remember that it requires us to use `#include <string>` above our code.
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>

