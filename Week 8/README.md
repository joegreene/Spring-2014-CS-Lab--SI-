# Week 8

## Contents
- [Solutions (From Last Week)](#solutions-from-last-week)
- [Intro](#intro)
- [Chapter 5: 5.1 - 5.6](#chapter-5-5.1-5.6)
  - [`while` loops](#while-loops)
    - [Multiple Conditionals in a `while` loop](#multiple-conditionals-in-a-while-loop)
    - [Pitfall: Infinite Looping](#pitfall-infinite-looping)
    - [Input Validation](#input-validation)
  - [Increment & Decrement Operators](#increment-decrement-operators)
  - [Counters](#counters)
  - [More Loops: do-while & for](#more-loops-do--while-for)
    - [`do-while` loops](#do-while-loops)
    - [`for` loops](#for-loops)
- [Class Practice](#class-practice)
  - [Worksheets](#worksheets)
  - [Separate Exercise](#separate-exercise)
- [Extra Challenges](#extra-challenges)

### Solutions (From Last Week)
In the usual spot (under files location).

### Intro
Before attempting this section, you'll want to have a steady knowledge about using booleans, flow control (if-else), logical operators, and relational operators. If you don't, go 
back to the notes, the book, the Week 6 and 7 work located in the main directory of this github, or review the worksheet we recently completed.

If you feel comfortable with the material after reading the notes, I've attached exercises to work on as well.

### Chapter 5: 5.1 - 5.6
The first several sections of Chapter 5. If you understand the following topic, the rest of this chapter should be fairly simple to you. As this covers loops primarily, either look at 
the following notes, the book, the powerpoint (if it is up on Titanium), or [here](http://www.tutorialspoint.com/cplusplus/cpp_loop_types.htm). I'd suggest either looking at my notes or 
the book first though (because the link assumes you know some material already).

NOTE: If you choose to look at the link, keep in mind that they talk about `goto` statements. You won't be dealing with those in this class, so ignore that section.

#### `while` loops
Remember how we told you that programs work "top-to-bottom"? Well, that was (partially) a lie. As the name suggests, a `while` loop lets you recur a block, as long as 
whatever condition set for the `while` loop is true.

The structure of a `while` loop:
```
  while ( some boolean expression or conditional is true )
  {
    do a set of operations
  }
```

Example (C++):
```c++
  //...code...
  int some_var = 12;
  
  while ( some_var <= 100 )
  {
    some_var += 10;
  }
  
  cout << some_var << endl;
  
  //...code...
```

Just by looking at the above code, what do you think the output is? If you're having trouble, take a look at the following psuedo-code and compare it to the above code.

Psuedo-code Example:

```
  Initialize integer variable "some_var" and set it to 12
  
  While "some_var" is less than or equal to 100
    add 10 plus some_var to some_var
   
  print out the value of some_var to console
```

Another thing to note is that, just like `if` statements, if there is only one line within the `while` loop block we may omit the curly braces `}, {`.

The previous C++ example remade:

```c++
  //...code...
  
  int some_var = 12;
  
  while ( some_var <= 100 )
    some_var+=10;
  
  cout << some_var << endl;
  //...code...
``` 

##### Multiple Conditionals in a `while` loop
Just like `if` and `else if` statements, we may have multiple conditionals set up inside a `while` loop.

Example (C++):

```c++
  //...code...
  int some_num = 20, some_num2 = 30;
  bool is_greater = false;
  
  while (!is_greater && some_num < some_num2) //checks to see if is_greater is false, and some_num is less than some_num2
  {
    //do some stuff in here
  }
  
  //...code...
```


##### Pitfall: Infinite Looping
Although the title of this topic spoils the surprise, try the following code out in a Visual Studio project:

```c++
  #include "stdafx.h"
  #include <iostream>
  
  int _tmain(int argc,_TCHAR* argv[])
  {
    bool is_valid = false;
    int num = 50;
    
    while(!is_valid) //remember that ! = NOT
    {
      std::cout << "Counting to 0 from " << num << "\n";
      
      std::cout << num << endl;
      
      num-=1;
    }
  }
```

As Uncle Ben from Spider-Man once said, "With great power comes great responsibility". This holds true for `while` loops too, so make sure you always make your loops somehow 
terminate or make its conditional false. Try fixing the above code so that we do not receive an infinite loop.

##### Input Validation
Mixing topics from Chapter 4, we can validate input in a more "user-friendly" way by using `while` loops. Instead of having the user only get one chance to enter input, we can 
ask them until some condition (i.e. in the `while` loop) is met.

Example (C++):

```C++
  //...code...
  bool valid_input = false;
  int some_num = 0;
  while(valid_input == false)
  {
    cout << "Enter in a nonnegative number: ";
    cin >> some_num;
    
    if(some_num < 0)
    {
      cout << "Invalid input.\n";
    }
    else
    {
      valid_input = true;
    }
  }
  //...code...
```

PRACTICE: Create your own code-snippet that asks for a user to enter a number between a range (e.g. 0 through 10). If it is out of bounds, tell them they have an invalid input and 
request them to input again.

The book has more information on this if you'd like to read more on this topic.

#### Increment & Decrement Operators
In looping (and outside of it), a couple of handy operators to use are the increment and decrement operators. These let you easily increase or decrease a number variable's value by one. To increment, we 
use `++` on the variable, and `--` to decrement the variable.

Example (C++):

```c++
  //...code...
  int var = 1;
  
  var++; //var is 2 now
  var--; //var is 1 now
  
  --var; //var is now 0
  var++; //var is now 1
  
  //...code...
```

Note that there is a difference between putting `++` and `--` either in the front or the back of the variable. When put in the front of the variable, it's called either a pre-increment or pre-decrement, and 
behind the numbered variable is called a post-increment or post-decrement.

Example (C++):

```c++
  //...code...
  double some_dbl = 11.0;
  
  some_dbl++; //some_dbl = 12.0
  
                              //OUTPUT        AFTER END OF STATEMENT
  cout << ++some_dbl << endl; //output: 13.0, some_dbl = 13.0
  cout << some_dbl-- << endl; //output: 13.0, some_dbl = 12.0
  cout << some_dbl++ << endl; //output: 12.0, some_dbl = 13.0
  cout << --some_dbl << endl; //output: 12.0, some_dbl = 12.0
  
  //...code...
```

Try guessing the values of x and y at each step (and the final output) in the following example:

```c++
  //...code...
  int x, y;
  x = y = 0;
  
  y = x++;
  x = --y;
  x = x++;
  y = y++;
  x = x + y++; //this is legal
  y = --x + --y; //this is legal
  
  cout << x << " " << y << endl;
  
  //...code...
```

More info [here](http://mathbits.com/MathBits/CompSci/looping/increment.htm).

#### Counters
When looping a piece of code, sometimes you'll want to do something some amount of times. Either that, or "count" the number of steps gone through the loop. You can achieve
this by using a counter (i.e. some incremented variable that "counts" the number of steps looped).

Example of a counter in use:

```c++
  //...code...
  int counter = 0;
  
  while ( counter <= 100 )
  {
    if (counter % 10 == 0) //if it has reached a step divisible by 10
      cout << "Reached Step " << counter << "!" << endl;
    else
      cout << "Step: " << counter << endl;
    
    ++counter; //increment counter
  }
  
  //...code...
```

These are normally helpful when debugging. If a loop ends up messing up at some step, one way to fix the error is by using a counter to check up to whatever step the error 
is occurring at.

Example of a (purposeful) error occurrence:

```c++
  int c = 0; //counter
  
  while (c < 1000)
  {
    if (c == 50)
      cout << 100/0 << endl;
    else
      cout << "Step " << c << endl;
      
    c++; //increment counter, and this pun was intended
  }
```

On which step in the above code does the error occur?

The book has more information on this if you'd like to read more content about counters.

#### More Loops: `do-while` & `for`
Below are the two other types of loops we'll be working with: `do-while` and `for` loops.

##### `do-while` loops
If you aren't clear about `while` loops then now's the time to go back and review it, or else this section might confuse you a bit.

`do-while` loops work exactly the way as `while` loops, except how they are structured allows them to run at least once before checking the while part. Also, 
they require a semi-colon (look below at the example).

Example (C++):

```c++
  //...code...
  int some_num = 6;
  
  do
  {
    cout << some_num << endl;
    some_num--;
  }while(some_num <= 0); //while check goes after code block (with a semi-colon)
  
  //...code...
```

Although they can be handy in some sort of code implementations, most of the time these can be easily replaced by a simple `while` loop. How do you suppose we can revise 
the above code to make it with under a `while` loop?

##### `for` loops 
`for` loops are like `while` loops, except they contain their own counter within them.

### Class Practice
All the below worksheet problems should be done by pencil/paper.

#### Worksheets
- Logical Operator Worksheet

#### Separate Exercise
Remake the calculator exercise from Week 6 ([here](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%206)) such that it allows the user to user the program as 
much as they'd like to.



Example outputs can be found in the folder "Example Outputs" under the files section at the top of this page.

### Extra Challenges

  
  ...
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Some notes grabbed from Dr. Tian's Chapter 4 Powerpoint (located on Titanium)

Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
