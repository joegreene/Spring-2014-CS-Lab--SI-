# Week 12

## Contents
- [Intro](#intro)
- [Nested Loops](#nested-loops)
- [Shape-Printing](#shape--printing)
  - [Square & Rectangle](#square-rectangle)
  - [Right-Triangle](#right--triangle)
  - [Equilateral Triangle](#equilateral-triangle)
  - [Diamond](#diamond)
- [Practice Assignments](#practice-assignments)
- [Extra Challenges](#extra-challenges)

### Intro
A bit of an extension to the [loops page](#), this will go furthermore into looping by introducting nested loops, and how we can 
utilize nested loops for processes such as printing shapes in the console window. This section will help test how well you can 
comprehend iterative processing, pattern solving, and (a bit on) optimization of code.

NOTE: We will be counting in these loops from 0 to n, where n is the last value we get to in our loops.
NOTE 2: I'm sure there are plenty of examples online on how to do these. If you only copy what is going on from an online example, chances are you won't understand how the 
looping process actually works. Take time in learning the material, or else future problems will be more troublesome than they should be. Attempt doing the work on your 
own or with a partner before consulting online help. 

### Nested Loops
Recall how, in a `for` loop, if we were to print out each step all we need to do is the following: 
```C++
  for (int z = 0; z < 5; ++z)
  {
    cout << z << " ";
  }
```

Where we would get:
```
  0 1 2 3 4
```

Note that it does not print 5 because, by then, z is equal to 5 and the conditional expression is false.

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
| --- | --- | --- | --- | --- |
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

Another cool trick is you can use nested-loops to print out something like the multiplication chart. For instance, the following code prints out the multiplication chart of 1 to 4:
```C++
  int size = 4;

  cout << "  | 1 | 2 | 3 | 4 |" << endl; //top line
  for(int base = 1; base <= size; ++base)
  {
    cout << base << " | ";
    for(int multiple = 1; multiple <= size; ++multiple)
      cout << base * multiple << " | ";
    
    cout << endl;
  }
```

Output:
```
    | 1 | 2 | 3 | 4 |
  1 | 1 | 2 | 3 | 4 | 
  2 | 2 | 4 | 6 | 8 | 
  3 | 3 | 6 | 9 | 12 | 
  4 | 4 | 8 | 12 | 16 | 
```

Note: If you really want to, you can edit the output on the inside to make correct spacing (and get all the pipes (`|`) aligned by using `iomanip`, however that 
will make the code more messy to read as an example. 

Make sure you understand how the nested loops section works, or else shape-printing in general will make no sense to you whatsoever.

### Shape-Printing
Using nested loops, we can print out various 2-dimensional shapes in the console window. We will use `for` loops in the following examples, namely because we know how long 
we want to iterate. These can be done via `while` and `do-while` loops, but `for` loops tend to be much easier to read when working with these.

NOTE: I know there might be more efficient ways of writing these examples, however for teaching purposes they are probably harder to comprehend.

#### Square & Rectangle
If we were to want to print out a square, we can do the following: 
```C++
  int r; //r stands for row
  int c; //c stands for column
  int side = 4;
  for(r = 0; r < side; ++r)
  {
    for(c = 0; c < side; c++)
    {
      cout << "* ";
    }
    cout << endl;
  }
```

Which outputs the following:
```C++
  * * * * 
  * * * * 
  * * * * 
  * * * * 
```

Note that, if we did do `<=`, we would have an extra row and column of asterisks. If you don't understand why this is the case, look at the situation iteratively. If you still don't 
know, review how conditional expressions work.

Similarly, if you want to draw a rectangle, just define a `width` and a `height` at the start.
```C++
  int r, c; //row and column
  int height = 2;
  int width = 4;
  
  for(r = 0; r < height; ++r)
  {
    for(c = 0; c < width; ++c)
      cout << "* ";
    cout << endl;
  }
```

Which prints out the following:
```
  * * * * 
  * * * * 
```

If you are having issues grasping how this works at this point, go back to the nested-loops section or else the rest of this page will not make sense.

#### Right-Triangle
Printing right-triangles are very similar to printing squares and rectangles. We only need to make a few adjustments to our previous examples.

If we want to print a right-triangle (with the right-angle corner on the bottom left), we may do the following: 
```C++
  int r, c; //row and column
  int base = 3;
  
  for(r = 0; r < base; ++r)
  {
    for(c = 0; c <= r; c++)
    {
      cout << "* "; 
    }
    cout << endl;
  }
```

Which prints the following: 
```
  * 
  * * 
  * * * 
```

Everything looks the same except for the conditional in the inner loop. Note how we say `c<=r`. The reason for this is because we want to print as many asterisks as what 
row we are on. For instance, first run of the inner loop prints one asterisk since we're on the first row, second run loops twice as we're on the second level, and 
third prints three as we're on the third row. 

For the top-left, we change the inner loop so that `c = base`, compare it to the row we're on, and decrement `c`:
```C++
  int r, c; //row and column
  int base = 3;
  
  for(r = 0; r < base; ++r)
  {
    for(c = base; c > r; --c)
    {
      cout << "* "; 
    }
    cout << endl;
  }
```

Which prints the following: 
```
  * * * 
  * * 
  * 
```

Top-right is a bit different, but not so bad. We'll need a for loop to cover the spaces, and another to cover the asterisks.
```C++
  int r, c; //row and column
  int base = 3;
  
  for(r = base; r > 0; --r)
  {
    for(c = base; c > r; --c) //spaces, inner loop #1
    {
      cout << "  ";
    }
    
    for(c = base; c > base - r; --c) //asterisks, inner loop #2
    {
      cout << "* ";
    }
    
    cout << endl;
  }
```

Which prints the following:
```
  * * * 
    * * 
      * 
```

This may seem really strange on how it works, but if you take it piece-by-piece and write it out on paper, it should be alright.

Here are the steps it takes:
```
  1. First run of outer loop, (row == base == 3)
    a. First inner loop does nothing (since both c and r equal base, the check is c > base)
    b. Second inner loop prints an asterisk three times (since r equals base, base - r equals 0, the check is c > 0)
  2. Second run of outer loop, (row == base - 1 == 2)
    a. First inner loop prints one space (since c == base, and r == base - 1, the check is c > 2)
    b. Second inner loop prints two asterisks (since r equals base - 1, base - r equals 1, the check is c > 1)
  3. Third run of outer loop, (row == base - 2 == 1)
    a. First inner loop prints two spaces (since c == base, and r = base - 2, the check is c > 1)
    b. Second inner loop prints one asterisk (since r equals base - 2, base - r equals 2, the check is c > 2)
  DONE
```

The fourth type (bottom-right) will be left as an exercise. It's nearly the same as top-right.

#### Equilateral Triangle](#equilateral-triangle)
If you don't kremember what an equilateral triangle is: It's a triangle with all three side lengths equal (and all angles are 60 degrees, as a triangle's angles add up to 180 degrees).

This one is a bit tricky, but not impossible. There are two ways to go about this one: One with three loops, another with absolute value.



In one instance, we may do the following (three loops):
```C++
  int r, c; //row and column
  int side = 3; //equal sides
  
  for(r = 0; r < side; ++r)
  {
    for(c = r; c < side; ++c) //spaces; inner loop #1
    {
      cout << " ";
    }
    
    for (c = 0; c < ((2 * r) + 1); ++c) //asterisks; inner loop #2
    {
      cout << "*";
    }
    
    cout << endl;
  }
```

Which prints the following:
```
   *
  ***
 *****
```

There are two ways to look at this: One in a mathematical approach, and another in an iterative approach.

By iteration (just like the top-right example from the previous section), we have:
```
  1. Outer-loop first run (r == 0)
    a. 
    b. 
  2. Outer-loop second run (r == 1)
    a. 
    b. 
  3. Outer-loop third run (r == 2)
    a. 
    b. 
  4. DONE (r == 3, base == 3, so r < side is false)
```

In a somewhat mathematical approach:
```
  Take a look at what is printed per row.
    There are three spaces and one asterisk in the first row.
    There are two spaces and three asterisks in the second row.
    There are one space and five asterisks in the third row.
  
  Note how in in the first row we have base spaces, then the second is base - 1, then base - 2.
  Note also how, upon each iteration of the for loop, we have an odd number of asterisks (i.e. 1, then 3, then 5).
  
  From here we can make a general equation for the number of spaces per row, and another for the number of asterisks we need per row.
    Number of spaces = base - row where row is the row we are currently on (we start at 0 in this case).
      NOTE: We can change this 
    Number of asterisks = 2(row) + 1, where this is the definition of odd numbers (row starts at 0 here too).
  
  We need to print the spaces before the asterisks.
  
  Therefore, our loops (inside the outer loop) should look as follows:
    for(c = r; c < side; ++c) // for spaces
    for (c = 0; c < ((2 * r) + 1); ++c) //asterisks
```

NOTE: I know that the base doesn't have the same amount of asterisks as the sides. If you were to account for the gaps on the sides, the actual side lengths come out as roughly the same.
NOTE 2: If you want to make the spaces more visible for yourself, replace the like `cout << " ";" with `cout << "r"`; or any character (to distinguish the spaces).

The another way to solve this problem is to use absolute value (allowing us to only need two loops at most):
```C++
  int r, c;
  int side = 3;
  
  for(r = side; r > 0; --r) //outer loop
  {
    for(c = side; c > -side; --c) //inner loop
    {
      if((abs(r) + abs(c)) <= side)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }
```

Which prints exactly the same thing as before.

The best way to do this is by looking at it as a grid and check when the asterisks or spaces are placed.

For instance, here is a grid of how the above code works (read as left to right, top to bottom): 
| - | 3 | 2 | 1 | 0 | -1 | -2 |
| --- | --- | --- | --- | --- | --- | --- |
| 3 | " " | " " | " " | "*" | " " | " " |
| 2 | " " | " " | "*" | "*" | "*" | " " |
| 1 | " " | "*" | "*" | "*" | "*" | "*" |

Note that, if we were to ignore signs, the following is true: 
> The asterisks are printed when |row| + |col| is less than the side length.

More specifically, we see when `|row| + |col| >= 3` is true, where `T` means true and `F` means false:
| - | 3 | 2 | 1 | 0 | -1 | -2 |
| --- | --- | --- | --- | --- | --- | --- |
| 3 | F | F | F | T | F | F |
| 2 | F | F | T | T | T | F |
| 1 | F | T | T | T | T | T |

To think of this as a number scheme:
```
  First row has an asterisk (or T) when abs(row) + abs(col) == 3 (i.e. sum is 3)
  Second row has an asterisk (or T) when abs(row) + abs(col) >= 3 (i.e. sum is 3 or 2)
  Last row has an asterisk (or T) when abs(row) + abs(col) >= 3 as well (i.e. sum is 3, 2, or 1)
```

From here we can create the if/else check system inside of the inner for loop, knowing when to print asterisks or spaces.

Note that, if we change how the `if` check works in the inner loop, we can get all sorts of designs.

For instance, changing `if((abs(r) + abs(c)) <= side)` to `if((abs(r) + abs(c)) >= side)` gives the following:
```
******
*** **
**   *
```

Otherwise, it swaps the asterisks and spaces.

Using `if((abs(r) + abs(c)) == side)` gives the following:
```
   *  
  * * 
 *   *
```

Why do you think the printing behaves that way? If you don't know, the grid explanation might help.

#### Diamond
We'll go over one way of solving this, then the second way will be left for you to do as an exercise.

Recalling back to printing out an equilateral triangle, we can think of a diamond as two equilateral triangles. One represents the top half, the other the bottom half.
```C++
  int r, c; //row and column
  int side = 3; //equal sides
  
  for(r = 0; r < side; ++r)
  {
    for(c = r; c < side; ++c) //spaces; inner loop #1
    {
      cout << " ";
    }
    
    for (c = 0; c < ((2 * r) + 1); ++c) //asterisks; inner loop #2
    {
      cout << "*";
    }
    
    cout << endl;
  }
  
  for(r = side; r >= 0; --r)
  {
    for(c = r; c < side; ++c) //spaces; inner loop #3
    {
      cout << " ";
    }
    
    for (c = ((2*r)+1); c > 0; --c) //asterisks; inner loop #4
    {
      cout << "*";
    }
    
    cout << endl;
  }
```

This will print out the following:
```
   *
  ***
 *****
*******
 *****
  ***
   *
```

The first loop is exactly the same as the previous, whereas the second is adding an extra line (the middle) and decreases the number of asterisks we have (to move downward to 1 asterisk).

Since we already went over the top loop, here's how the second loop works (by iteration):
```C++
  1. First run of second outer loop (r == side)
    a. 
    b. 
  2. Second run of second outer loop (r == side - 1)
    a. 
    b. 
  3. Third run of second outer loop (r == side - 2)
    a. 
    b. 
  4. Fourth run of second outer loop (r == side - 3 == side - side == 0)
    a. 
    b. 
  5. DONE (r == -1 && r < 0)
```

Doing this one as absolute value will be given as an exercise.

### Practice Assignments
As usual, work with a partner to try these exercises out.

1. Print a right-triangle, using nested `for` loops, with its right-angle corner in the bottom right. Make sure to write out a table of iteration somewhere to check your steps, or to help others 
around you.
2. Print out a diamond shape using absolute value. HINT: This is almost exactly the same as doing the equilateral triangle problem with absolute value. It only requires a few tweaks. Best way to approach this is to 
go back to how the asterisks are printed and how the grid explanation works.

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
