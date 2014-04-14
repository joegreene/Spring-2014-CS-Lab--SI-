# Week 12

## Contents
- [Intro](#intro)
- [Loops Review](#loops-review)
  - [while](#while)
  - [do-while](#do-while)
  - [do-while versus while](#do-while-versus-while)
  - [for](#for)
  - [Summary (of Loops)](#summary-of-loops)
- [Practice Assignments](#practice-assignments)
- [Extra Challenges](#extra-challenges)

### Intro
This part of the notes will go more over loops and shape-printing. 

As a side note: To `iterate` means to perform repeatedly. Each time the loop iterates is called an `iteration`. The counter in 
a loop is called an `iterator` (as long as the counter is determining how many times the loop iterates).

The (best) approach to working with loops, especially nested loops, is by writing out on paper what happens per iteration. Nested loops 
are talked about on another page under this week's work.

### Loops Review
Recall that there are three types of loops: `while`, `do-while`, and `for` loops. Each will be split below, providing example code 
to solve something like the summation of a math function from `i` to `n`.

In our case, we will work with something like this:

![alt text](http://upload.wikimedia.org/math/d/f/2/df26e1cf51b67fbedd01ce9c68cbbef5.png "Summation of a_i from i to n (From Wikipedia)")

However, we will replace `a_i` with `i^2` (for sake of easier explanation).

#### while
`while` loops work exactly as their name entails: They do something __while__ something is __true__.

It is a __pretest__ loop (i.e. it checks the condition __BEFORE__ running the code within it).

The syntax structure of a `while` loop is as follows:
```C++
  while(conditional expression is true)
  {
    //body (where looped code is put)
  }
``` 

__NOTE:__ In the above part, "conditional expression is true" refers back to boolean expressions.

Just like if/else statements, the curly braces under the while loop are optional if you have only __one__ line of code within the body

__EXAMPLE:__ If we were to solve the summation problem from the beginning of this section, we would have something along the lines of:
```C++
  int i = 0;
  int n = 4; //for test purposes, set upper limit to 4
  int sum = 0;
  while(i <= n) 
  {
    sum = sum + pow(static_cast<double>(i), 2.0); //same as sum+=pow((double)i, 2.0);
                                                  //NOTE: Remember that we need to change i 
                                                  //to a double for pow to work
    ++i; //update i
  }
  
  cout << "The summation of i^2 from i=0 to " << n << " is " << sum << endl;
```

Where `i` and `n` are the same as the equation, and the `i^2` part was changed (to agree with C++ syntax). 

Output:
```
  The summation of i^2 from i=0 to 4 is 30
```

The table (of iterations) in the code above is as follows, where each row represents an iteration:

| `i` (beginning) | `sum` (during update) | `sum` (after) | `i` (end of iteration) |
| --- | --- | --- | --- |
| 0 | `sum = 0 + 0^2` | 0 | 1 |
| 1 | `sum = 0 + 1^2` | 1 | 2 |
| 2 | `sum = 1 + 2^2` | 5 | 3 |
| 3 | `sum = 5 + 3^2` | 14 | 4 |
| 4 | `sum = 14 + 4^2` | 30 | 5 |
| 5 | `OUT OF LOOP (no change)` | 30 | 5 |

__NOTE:__ Notice that in the last line the loop is not ran. Therefore, `i` and `summation` do not update.

#### do-while
Almost the same as `while`, `do-while` runs the code inside the loop __at least once__ before checking the conditional. Because of this, 
`do-while` is a __post-test__ loop. 

An example implementation of a `do-while` loop:
```C++
  do
  {
    //body (where looped code is put)
  }while(conditional expression is true);
```

Keep in mind that the semi-colon at the end is __required__ for this type of loop. One reason for this is to distinct itself from the previous while loop. More information 
[here](#http://stackoverflow.com/questions/942251/in-c-c-why-does-the-do-whileexpression-need-a-semi-colon)

Also, just like the `while` loop, if there is only one line of code being changed then the curly braces may be omitted.

Here's an example code of solving the summation problem from the start: 
```C++
  int i = 0;
  int n = 4;
  int sum = 0;
  do
  {
    sum = sum + pow(static_cast<double>(i), 2.0);
    ++i;
  }while(i <= n);
  
  cout << "The summation of i^2 from i=0 to " << n << " is " << sum << endl;
```

This will print out the exact same thing as the previous `while` loop example.

#### do-while versus while
There are specific times when you would like to use a `while` loop over  a `do-while` loop, and vice-versa.

For instance, say we wanted to make a menu-driven program for either adding sales, printing out the total sale count, or quitting.

A `while` loop example of printing this type of menu can be made by doing the following:
```C++
  bool continue;
  int choice;
  cout << "1. Add sales\n";
  cout << "2. Print sales\n";
  cout << "3. Quit\n";
  cout << "Enter a choice: ";
  cin >> choice;
  
  if(choice == 1)
  {
    //do code for adding sales
    continue = true;
  } 
  else if(choice == 2)
  {
    //do code for printing
    continue = true;
  } 
  else if(choice == 3)
    continue = false; //quit
  else
  {
    cout << "Incorrect input. Restarting prompt...\n"; 
    continue = true;
  } 
  while(continue)
  {
    cout << "1. Add sales\n";
    cout << "2. Print sales\n";
    cout << "3. Quit\n";
    cout << "Enter a choice: ";
    cin >> choice;
    
    if(choice == 1)
    {
      //do code for adding sales
      continue = true;
    } 
    else if(choice == 2)
    {
      //do code for printing
      continue = true;
    } 
    else if(choice == 3)
      continue = false; //quit
    else
    {
      cout << "Incorrect input. Restarting prompt...\n"; 
      continue = true;
    } 
  }
```

Notice how messy the code is for this? Well, with `do-while` we can just throw that entire chunk of code above the `while` loop inside. 

The `do-while` representation is as follows:
```C++
  bool continue;
  int choice;
  do {
    cout << "1. Add sales\n";
    cout << "2. Print sales\n";
    cout << "3. Quit\n";
    cout << "Enter a choice: ";
    cin >> choice;
    
    if(choice == 1)
    {
      //do code for adding sales
      continue = true;
    } 
    else if(choice == 2)
    {
      //do code for printing
      continue = true;
    } 
    else if(choice == 3)
      continue = false; //quit
    else
    {
      cout << "Incorrect input. Restarting prompt...\n"; 
      continue = true;
    } 
  }while(continue);
```

Just by looking at it we can see that the `do-while` representation is much more compact, however there is a catch with the `while` 
representation where we can make it just as neat as the `do-while` version.

If we simply initialize `bool continue` at the start, we can have nearly the same exact code. For instance:
```C++
  bool continue = true; //changed line
  int choice;

  while(continue)
  {
    cout << "1. Add sales\n";
    cout << "2. Print sales\n";
    cout << "3. Quit\n";
    cout << "Enter a choice: ";
    cin >> choice;
    
    if(choice == 1)
    {
      //do code for adding sales
    } 
    else if(choice == 2)
    {
      //do code for printing
    } 
    else if(choice == 3)
      continue = false; //quit
    else
      cout << "Incorrect input. Restarting prompt...\n";
  }
```

Note that we may also remove `continue = true;` in three of the checks (as it is now redundant). If we do the same process on the `do-while` example, we 
may remove these lines as well.

For this reason, the following is true:

> Any `while` loop can replace any `do-while` loop, but not true vice-versa. 

Although saying the above statement (nearly) renders `do-while` loops as obsolete, there might be times in which 
implementing `do-while` is cleaner. It's mainly up to personal preference.

#### for
Differing from the previous two types, a `for` loop's purpose is to loop a piece of code a set amount of times. This differs from `while` and `do-while` because 
with this loop we (should) know how many times it will run.

An example implementation of a for loop:
```C++
  for(initialization; conditional check; update)
  {
    //body (where looped code is put)
  }
```

Where "initialization" refers to , "conditional check" is just like the previous loops, and "update" refers to whatever you plan on having in the end. 
The only part that is necessary is the "conditional check", and we'll talk about why that is in a moment.

If we were to type out the summation problem again, the following is a `for` loop example of solving it:
```C++
  int sum = 0;
  int n = 4;
  
  for (int i = 0; i <= n; ++i) //i is the initialized value, comparison is same as before, and 
  {
    sum+=pow(static_cast<double>(i), 2.0);
  }
  
  cout << "The summation of i^2 from i=0 to " << n << " is " << sum << endl;
```

This prints out the same exact output as the other loops, and has the same table as before. Note that, if we wanted to, we could have initialized `i` outside of the `for` loop and update inside of the loop. 

For instance, this is another way to implement a solution for the summation problem: 
```C++
  int sum = 0;
  int i = 0;
  int n = 4;
  
  for (; i <= n;) //omitted initialization and update
  {
    sum+=pow(static_cast<double>(i), 2.0);
    ++i;
  }
  
  cout << "The summation of i^2 from i=0 to " << n << " is " << sum << endl;
```

If we have the update inside the curly braces of the for loop however, it defeats the niceties of a `for` loop.

If we do not have the conditional check inside the for loop, the code will infinitively loop. This is because the blank space is evaluated as true. For instance: 
```C++
  for(int x = 0; ; x++)
    cout << "The loop is at: " << x << endl;
```

Will print out:
```
  The loop is at: 0
  The loop is at: 1
  The loop is at: 2
  ...
```

And so on, infinitively.

#### Summary (of Loops)
- Three types of loops: `while`, `do-while`, `for`.
- `while` and `for` loops are pretest loops, whereas `do-while` is a post-test loop.
- `while` can always replace `do-while` with the right initialization/implementation.
- `while` and `for` have the chance to never run, whereas `do-while` always runs at least one time.
- General rule of thumb for when to use each type of loop:
  - `while`: when the conditional expression is not known when to end (such as requesting values that determine the conditional expression)
  - `do-while`: menus (can be done under `while` of course)
  - `for`: iterative processes (such as summation or factorials, where we know how many times to loop the program)
  
### Practice Assignments
Code for the following assignments will be provided via the top of this page. Try to do them yourselves first, however.

1. Using loops, try to print out the factorial of a number (allowing the user to enter the value). Have error-checking (i.e. make sure that, if `f(n) = n!`, that 
 `n >= 0`). If you want to calculate big factorials (e.g. where `n! >= 2^64`), refer to [this](#http://msdn.microsoft.com/en-us/library/s3f49ktz.aspx) to fiddle with datatype ranges.
 
2. Using loops, print out the 8th term of the Fibonacci sequence. Some of you may have been exposed to this in a math class, but if not then look [here](#http://en.wikipedia.org/wiki/Fibonacci_number).

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
