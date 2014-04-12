# Week 12

## Contents
- [Intro](#intro)
- [Loops Review & Shape-Printing](#loops-review-shape--printing)
  - [while](#while)
  - [do-while](#do-while)
  - [for](#for)
  - [Summary (of Loops)](#summary-of-loops)
- [Shape-Printing](#shape--printing)
  - [Square](#square)
  - [Right-Triangle](#right--triangle)
  - [Equilateral Triangle](#equilateral-triangle)
  - [Diamond](#diamond)
- [Practice Assignments](#practice-assignments)
- [Extra Challenges](#extra-challenges)

### Intro
This part of the notes will go more over loops and shape-printing. 

As a side note: To iterate means to perform repeatedly. Each loop (that is iterating) is called an iteration. The counter in 
a loop is called an iterator (as long as the counter is determining how many times the loop loops). ALSDKMfix ASLKDM

### Loops Review & Shape-Printing
Recall that there are three types of loops: `while`, `do-while`, and `for` loops. Each will be split below, providing example code 
to solve something like the summation of a math function from `i` to `n`.

In our case, we will work with something like this [SOURCE](#http://en.wikipedia.org/wiki/Summation#Notation):

![alt text](http://upload.wikimedia.org/math/d/f/2/df26e1cf51b67fbedd01ce9c68cbbef5.png "Summation of a_i from i to n")

However, we will replace `a_i` with `i^2` (for sake of easier explanation).

#### while
`while` loops work exactly as their name entails: They do something __while__ something is __true__.

It is a __pretest__ loop (i.e. it checks the condition __BEFORE__ running the code within it).

The syntax structure of a `while` loop is as follows:
```C++
  while(conditions is true)
  {
    //do some code
  }
``` 

__NOTE:__ In the above part, "condition is true" refers back to boolean expressions. 

ASDASDZXV Keep below for the for loop exercise instead? asFASDFXCVxzcv

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
    ++i;
  }
  
  cout << "The summation of i^2 from i=0 to n where n=4 is " << sum << endl;
```

Where `i` and `n` are the same as the equation, and the `i^2` part was changed (to agree with C++ syntax). 

Output:
```
  The summation of f(x) = x^2 from i=0 to n where n=4 is 
```

The table (of iteration) is as follows:

| i (beginning) | `sum` (during update) | `sum` (after) | i (end of iteration) |
| --- | --- | --- |
| 0 | `sum = 0 + 0^2` | 0 | 1 |
| 1 | `sum = 0 + 1^2` | 1 | 2 |
| 2 | `sum = 1 + 2^2` | 5 | | 3 |
| 3 | `sum = 5 + 3^2` | 14 | 4 |
| 4 | `sum = 14 + 4^2` | 30 | | 5 |
| 5 | `OUT OF LOOP (no change)` | 30 | | 5 |

__NOTE:__ Notice that in the last line, the loop is not ran. Therefore, `i` and `summation` do not update.

#### do-while
Almost the same as `while`, `do-while` runs the code inside the loop __at least once__ before checking the conditional. Because of this, 
`do-while` is a __post-test__ loop. 

asdasdafasdgczx
For this reason, the following is true:

Any `while` loop can replace any `do-while` loop, but not true vice-versa.

#### for
Differing from the previous two types, a `for` loop's purpose is to 

#### Summary (of Loops)
- Three types of loops: `while`, `do-while`, `for`.
- `while` and `for` loops are pretest loops, whereas `do-while` is a post-test loop.
- `while` can always replace `do-while` with the right initialization/implementations
- General rule of thumb for when to use each type of loop:
  - `while`: when the conditional expression is not known when to end (such as requesting values that determine the conditional)
  - `do-while`: menus (can be done under `while` of course)
  - `for`: iterative processes (such as summation or factorials)
### Practice Assignments
1. Just like the other shapes we've printed out, try to print out a diamond-shape. There are two ways: Either use two equilateral triangles or use absolute value.

### Extra Challenges
TBD

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
