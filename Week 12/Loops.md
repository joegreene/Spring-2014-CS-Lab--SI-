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

NOTE: Keep below for the for loop exercise instead.

EXAMPLE: If we were to solve the summation problem from the beginning of this section, we would have something along the lines of:
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
```

Where `i` and `n` are the same as the equation, and the `x^2` part was changed (to agree with C++ syntax). 

__NOTE:__ If we really wanted to, we could have replaced `summation` with `i` and saved ourselves from using an extra variable. For the 
sake of easier explanation, however, there is an extra variable.

The table (of iteration) is as follows:
i (beginning) | `summation` | i (end of iteration)
--- | --- | ---
0 | `summation = 0 + 0^2` | 1
1 | `summation = 0 + 1^2` | 2
2 | `summation = 0 + 1^2` | 3
3 | `summation = 0 + 1^2` | 4
4 | `summation = 0 + 1^2` | 5
5 | `summation = summation` | 5


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
