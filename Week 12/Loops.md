# Week 12

## Contents
- [Intro](#intro)
- [Loops Review & Shape-Printing](#loops-review-shape--printing)
  - [while](#while)
  - [do-while](#do-while)
  - [for](#for)
  - [Summary of while, do-while, for](#summary-of-while,-do-while,-for)
- [Practice Assignments](#practice-assignments)
- [Extra Challenges](#extra-challenges)

### Intro


### Loops Review & Shape-Printing
Recall that there are three types of loops: `while`, `do-while`, and `for` loops. Each will be split below, providing example code 
to solve something like the summation of a math function from i to n.

In our case, we will work with something like this:

![alt text](http://upload.wikimedia.org/math/d/f/2/df26e1cf51b67fbedd01ce9c68cbbef5.png "Summation a_i from i to m")

However, we will replace `a_i` with `i^2` (for sake of easier explanation).

#### while
`while` loops work exactly as their name entails: They do something __while__ something is __true__.

It is a pretest loop (i.e. it checks the condition __BEFORE__ running the code within it).

The syntax structure of a `while` loop is as follows:
```C++
  while(conditions is true)
  {
    //do some code
  }
``` 

NOTE: In the above part, "condition is true" refers back to boolean expressions. 

ASDASDZXV Keep below for the for loop exercise instead? asFASDFXCVxzcv

__EXAMPLE:__ If we were to solve the summation problem from the beginning of this section, we would have something along the lines of:
```C++
  int i = 0;
  int n = 4; //for test purposes, set upper limit to 4
  int summation = 0;
  while(i <= n)
  {
    summation = summation + pow(static_cast<double>(i), 2.0); //same as summation+=pow((double)i, 2.0);
                                                              //NOTE: Remember that we need to change i 
                                                              //to a double for pow to work
    ++i;
  }
  
  cout << "The summation of i^2 from i=0 to n where n=4 is " << summation << endl;
```

Where `i` and `n` are the same as the equation, and the `i^2` part was changed (to agree with C++ syntax). 

Output:
```
  The summation of f(x) = x^2 from i=0 to n where n=4 is 
```

The table (of iteration) is as follows:

| i (beginning) | `summation` | i (end of iteration) |
| --- | --- | --- |
| 0 | `summation = 0 + 0^2` | 1 |
| 1 | `summation = 0 + 1^2` | 2 |
| 2 | `summation = 1 + 2^2` | 3 |
| 3 | `summation = 5 + 3^2` | 4 |
| 4 | `summation = 14 + 4^2` | 5 |
| 5 | `DONE (no more changes)` | 5 |

__NOTE:__ Notice that in the last line, the loop is not ran. Therefore, `i` and `summation` do not update and .

#### do-while

#### for
Differing from the previous two types, 

### Practice Assignments
1. Just like the other shapes we've printed out, try to print out a diamond-shape. There are two ways: Either use two equilateral triangles or use absolute value.

### Extra Challenges
TBD

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
