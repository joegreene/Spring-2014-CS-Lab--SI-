# Week 5

## Contents
- Exercise & Setup
- Intro
- Variables (& Constants)
	- Identifiers and Naming Scheme
	- Data Types
		- Integers
		- Doubles
		- Characters
		- Strings
		- Booleans
	- Assignment Operator
	- Basic Arithmetic & Type Casting/Conversion
	- Overflow/Underflow
	- When to Use Each Type
	- Attached Exercise
	- Extra: Simple Control Flow (`if`, `else`)
- Continuing Challenges
- Notes (and for More Help)

### Exercise & Setup

As usual, load up Visual Studio and create a project using the "Win32 Application" option.
Name it whatever you'd like (best to have the name pertain to what you're working on though,
e.g. "Week_5_Exercise"). 

Most of this exercise will deal with reading though, with some examples and an attached
exercise at the end of it. Also, make sure to set the directory to your desktop, so you can 
easily refer to the files outside of the IDE.

Most of this work is review on the lecture and labs, so if you feel completely comfortable
with variables and the lecture notes feel free to skip to the section labeled "Attached Exercise".
This exercise page is a bit hefty.

Below all of this, there is a section that includes the references used in this exercise. If I've 
missed anything you would like to cover, ask a friend or review the work.

Lastly, if you finish early please help a friend nearby. If you don't have any, and can
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

results in the console printing out `17`.

Going more in-depth, we'll look more into these in the following sections.

### Variables (& Constants)
Like in math, variables are items that can hold values. Unlike math though, in computer 
science a variable can be reassigned a different value later on.

Remember that variables are names for locations in memory and that computers do things 
step by step. Also, if a variable is reassigned a value later on, it "forgets" the previous 
value assigned to it for the remainder of the program.

Variables have three parts to them: Data type, identifier, and the value assigned to each 
variable.

The values assigned to each variable (as you'll see in the later sections of this excerise), are
called constants or literals. Examples of such are `12`, `'a'`, and `"hello\n"`.

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

Lastly, when creating identifiers for your variables, it is up to you to determine whether or not to 
sacrifice legibility or the time it takes to type it out. Look at the following example and determine
for yourself which one would suit yourself and others reviewing your program:

```C++
  int numSales;
  int num_of_sales;
  int nms;
  int number_of_sales;
  //etc.
```

Overall, like the rest of your code, think about the future when looking back on your work. Make it neat, 
legible, and easy for you and others to review for later use.

#### Data Types
Although there are MANY different types of data types , you won't be using every single one 
in this course. There are five, however, that come up the most often. These are:
`int`, `double`, `char`, `string`, and `bool`.

It's good to know the other types, such as `float`, although you won't be seeing them 
as much (or at least I haven't).

Each data type has its own byte-size, that is, the amount of memory it takes up in RAM. A byte is a list 
of 8 bits, whereas a bit is a `0 (off)` or `1 (on)` value. 

Although the following references goes over the file sizes, we'll be going over them too in the following 
sections. This topic also deals slightly on the range of each data type. If you'd like you can have the following
links open on separate tabs (because they will be referred to later on).

[Variables and types in C++] (http://www.cplusplus.com/doc/tutorial/variables/)

[Range of Data Types in Visual Studio C++] (http://msdn.microsoft.com/en-us/library/s3f49ktz%28v=vs.110%29.aspx)

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

which outputs `42` in console. `42` is an `integer constant`.

##### Doubles
Known in syntax as `double`, doubles are similar to the `int` data type, except they are 
for decimal values. Refer to the second reference under "Data Types" for exact byte-size 
and range.

Here's an example of this in code:

```C++
  double some_double = 2.7;
  cout << some_double << endl;
```

which outputs `2.7`. `2.7` is a `double constant`.

##### Characters
The character data type, or `char`, holds single characters. These include values such as 
`a, b, z, -, ...` and so on. These are 1 byte and therefore their range is `0 to 255` or 
`-128 to 127`.

Examples of assigning and printing characters:

```C++
	char some_char = 'c';
	cout << some_char << endl;
```

which outputs `c`. `c` is a `character constant`.

At the beginning, notice how the above talks about integers. The weird thing about characters 
are that they can be represented as integers. For instance:

```C++
	cout << 'a' << endl;
```

outputs `97`. Also, 

```C++
	cout << 'b' + 55 << endl;
```

outputs `153`. The reason for this is because of how characters are stored on computers. Check [here] (http://www.ascii-code.com/) for more information on how the output corresponds to the letter. 

Although ASCII isn't used much anymore, programming in general bases off of this because of how 
easy it is to correspond values (e.g. `97` is `a`). The new standard is UTF-8, and if you want 
to see more information on it check [here] (http://stackoverflow.com/questions/700187/unicode-utf-ascii-ansi-format-differences).

The main difference though is that it covers more character types than ASCII. UTF-8 supports
up to 4-bytes per character, whereas ASCII has only one byte per character (which works perfectly
for us right now).

Moving on: If we want to go from `char` to `int`, all we have to do is the following:

```C++
  cout << static_cast<char>('a' + 5) << endl;
```

outputs `f`.

NOTE: `static_cast` is a form of type conversion. We'll talk more about it in a later section.

##### Strings
The string data type, or `string`, is unlike the other data types on this list. For one thing, 
it requires its own special header to be able to use it. Another thing is it isn't a 
[primitive data type] (http://www.tutorialspoint.com/cplusplus/cpp_data_types.htm), or a data type in its simplest form.
If you think about it, what are strings composed of?

Example syntax of a string in use:

```C++
  string some_string = "I am a string. Rawr.";
  cout << some_string <<endl;
```
  
outputs `I am a string. Rawr.`. `I am a string. Rawr.` is a string literal.
  
##### Booleans
The boolean data type, or `bool`, holds either a `true` or `false` value. Not necessarily too
useful for us yet, in the next chapter we will be using this data type frequently. For now, know 
the following few specifics of this data type.

First off: As a boolean can only hold a `true` or `false` value, what size do you think it is in 
memory?

If you guessed a bit or anything else other than a byte, then I am afraid you are wrong. Although 
it makes perfect sense for a bool to be of size 1 bit (as it can only be a `true` or `false` 
value, because the smallest piece of memory a CPU can handle is one byte then a bool is one byte.

Example syntax of using the `bool` data type:

```C++
	bool some_bool = 0; //false
	some_bool = true; //true
	some_bool = false; //false
	some_bool = 1; //true
	cout << some_bool << endl; //1 (or true)
```

As a boolean can be assigned `0` or `1` to it, what do you think will happen if you assigned a value, 
say, `42` to it? Try it out.

More operations with booleans (that you may have or not seen before):
```C++
	bool some_bool = (10 < 2); //false, as 10 is less than 2
	some_bool = (7 > 3); //true, as 7 is greater than 3
	some_bool = (15 >= 15); //true, as 15 is greater than or equal to 15
	some_bool = (16 <= 17); //true, as 16 is less than or equal to 17
	cout << !some_bool << endl; //false, as '!' is the negation operator for booleans
```

Trivia: The `bool` data type is named after the mathematician, [George Boole] (http://en.wikipedia.org/wiki/George_Boole)

#### Assignment Operator
As you have seen already in the previous examples, the assignment operator "assigns" a value 
to a variable. Signified by `=`, the value assigned to the variable depends solely on the data type of the
variable.

The assignment operator works right to left, that is, the right value gets assigned to the 
whatever is on the left (namely a variable). For instance: 

```C++
	int some_value = 0; //0 gets assigned to the integer variable some_value
```

#### Basic Arithmetic & Type Casting/Conversion
Just like in math, arithmetic with variables works the same way in computer science. Using PEMDAS, try to 
guess the outputs of the following C++ syntax:

```C++
	int var1 = 7;
	int var2 = -var1; // (Look below for more explanation)
	cout << var1 + var2 << endl;
	cout << var2 - var1 << endl;
	cout << 2 * var1 << endl;
	cout << var1 / (var2 * 3) << endl; // (Look below for more explanation)
	cout << var1 % -var2 << endl; // (Look below for more explanation)
```

In order of cout statements (top to bottom): `7 + (-7) = 0`, `7 - (-7) = 14`, `2 * 7 = 14`, 
`7/(-7*3) = 0`, and `7 % -7 = 0`.

As seen above, `+` is for addition, `-` is for subtraction, `/` for division, `*` for multiplication, 
and `%` for modulus. The first four might seem obvious (when looking at a math point of view), although
you might have not heard of modulus before. 

When dividing two integers, the number (minus the decimal) is returned. Also `%` returns the remainder of 
two integers.

Another neat thing about operators: If you are only dealing with one `binary` operation, you may do the following:

```C++
	int var1 = 0;
	var1+=1; //same as var1 = var1 + 1;
	var1/=2; //same as var1 = var1 / 2;
```

and so on with the other operators `*` and `%`.

When referring to operators as `binary` or `unary`, this means that the operator requires a
certain amount of items acting upon it. For instance: In order to add you need two values, and in order
to set a value negative you need only one value.

With type casting/conversion, we use the C++ standard's `static_cast` function. For example:

```C++
	cout << static_cast<int>(99.8);
```

displays `99`. Remember that, when converting to integer from double, the decimal is truncated.

Other examples:

```C++
	char some_char = 'q';
	cout << static_cast<int>(q); //outputs 113
	int circumference = static_cast<int>(2 * 3.141592); //assigns 6 to circumference
```


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
on the data types and amount of code they produced. As each variable adds up to how much memory a program
is using in RAM, and each typed word adds up the amount of space the source file `(.cpp)` is using on 
the hard drive, programmers had to be wary with code. Lucky for us, we don't have to worry about that 
(or for now at least).

You can also check the byte-size of a data type by using `sizeof()`, where inside
the parenthesis you place the variable. For example:
```C++
  cout << sizeof(52) << endl;
  cout << sizeof(char) << endl;
```

Since `52` is an integer constant, the output is `4` (the byte-size of an integer value). With the second
line, the output is `1`.

Another thing: As with most things, there is a time and place for using each variable. Unfortunately, 
there isn't necessarily a bulletproof plan for knowing when to use each data type, so just think about what 
you're doing and what you'll need to accomplish the task.

#### Attached Exercises
Download the following file [here] (https://www.mediafire.com/?5g0b3cdna9dk05j)

NOTE: The second page is a challenge section.

#### Extra: Simple Control Flow (`if`, `else`)
A preview of what you'll be learning in Chapter 4, `if` and `else` statements. Here's an example 
of using these concepts:

```C++
  #include <stdafx.h>
  #include <iostream>
  
  int _tmain(int argc, _TCHAR* argv[])
  {
  	int some_value = 1;
  	
  	std::cout<<"Enter in an integer: ";
  	std::cin>>some_value;
  	
  	if(some_value >= 50)
  	{
  		std::cout << "Your value is: " << some_value << std::endl;
  	}
  	else
  	{
  	  std::cout<< "Your value multiplied by two is: " << 2 * some_value << std::endl;
  	}
  	
  	return 0;
  }
```

By inspection, see if you understand what's going on with the code. What would the output be? Refer to the flow
control link under "Continuing Challenges" below.

### Continuing Challenges
Second portion of the .docx file.

[Learn more about variables, IO (Input/Output), and strings] (http://www.cplusplus.com/doc/tutorial/basic_io/)

[Flow control in C++] (http://www.cplusplus.com/doc/tutorial/control/)

## Notes
Sources used in this exercise:

[Variables and types in C++] (http://www.cplusplus.com/doc/tutorial/variables/)


[Range of Data Types in Visual Studio C++] (http://msdn.microsoft.com/en-us/library/s3f49ktz%28v=vs.110%29.aspx)


[Learn more about variables, IO (Input/Output), and strings] (http://www.cplusplus.com/doc/tutorial/basic_io/)

[Flow control in C++] (http://www.cplusplus.com/doc/tutorial/control/)

[More on Data Types] (http://www.tutorialspoint.com/cplusplus/cpp_data_types.htm)

[Bool Data Type: Where'd it Get its Name?] (http://en.wikipedia.org/wiki/George_Boole)

Refer to your lecture notes and book for more help if I've missed anything you would like to review.

Random bold here. I'm not sure how to fix this at the moment.
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>

