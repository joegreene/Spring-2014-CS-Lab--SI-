# Week 12

## Contents
- [Intro](#intro)
- [Nested Loops](#nested-loops)
- [Shape-Printing](#shape--printing)
  - [Square](#square)
  - [Right-Triangle](#right--triangle)
  - [Equilateral Triangle](#equilateral-triangle)
  - [Diamond](#diamond)
- [Practice Assignments](#practice-assignments)
- [Extra Challenges](#extra-challenges)

### Intro
A bit of an extension to the [loops page](#), this will go furthermore into looping by introducting nested loops, and how we can 
utilize nested loops for processes such as printing shapes in the console window.

### Nested Loops
Recall how, in a `for` loop, if we were to print out each step all we need to do is the following: 
```C++
  for (int z = 0; z < 5; ++z)
  {
    cout << z << " ";
  }
```

Which prints the following:
```
  0 1 2 3 4
```

Note that it does not print 5 because, by then, z is equal to 5 and the conditional is false.

A little bit crazy-sounding, but if we wanted to loop a loop multiple times, we may do the following: 
```C++
  for(int i = 0; i < 2; ++i) //run this twice
  {
    for(int j = 0; j < 3; ++j) //run this three times two times 
    {
      cout << j << " ";
    }
    cout << endl;
  }
```

Which prints out the following: 
```
  0 1 2 
  0 1 2 
```

Here is a table (of iteration):
| `i` (start of outer loop) | Output (after inner loop ends) | Output (end of outer loop) | `i` (end of outer loop) |
| 0 | "0 1 2" |  "\n"   | 1 |
| 1 | "0 1 2" |  "\n"   | 2 |
| 2 | Not run | Not run | 2 |

Here is a list of the steps, if it makes more sense than the above:
1. Run outer loop
2. Run inside loop
3. Print `j` three times
4. Done with inner loop, end line, iterate outer loop
5. Run inside loop a second time
6. Print `j` three times
7. Done with inner loop, end line, iterate outer loop
8. Done with outer loop, end of nested loop


Note how the integer `j` determines how much we print per line (3 integers), and how the integer `i` determines how many lines we print (two lines).

If you know what [matrices](#http://www.mathsisfun.com/algebra/matrix-introduction.html) are (from math), it's handy to think about the iterated integers as rows (each line) and columns (amount per row).

### Shape-Printing
Using nested loops, we can print out various 2-dimensional shapes in the console window.

#### Square
If we were to want to print out a 

#### Right-Triangle
#### Equilateral Triangle](#equilateral-triangle)
#### Diamond
We'll go over the first half of solving this one, then as an exercise you can try to get the other half.

Recalling back to printing out an equilateral triangle, we can 

### Practice Assignments
These are all listed under their relevant note pages, except for [this](#github tic-tac-toe) one, which will help with honing-in on using both loops and if-else checks 
if you wish to do so.

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
