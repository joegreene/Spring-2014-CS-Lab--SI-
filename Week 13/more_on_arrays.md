# Week 13

## Contents
- [More on Arrays](#more-on-arrays)
  - [How Arrays Work in RAM](#how-arrays-work-in-ram)
  - [Comparing Arrays](#comparing-arrays)
  - [Parallel Arrays](#parallel-arrays)
  - [Two Dimensional Arrays](#two-dimensional-arrays)

### More on Arrays
#### How Arrays Work in RAM
Arrays themselves aren't necessarily objects, rather an enclosed space in RAM where a group of similar objects exist. These similar objects are located in 
sequential addresses, where the addresses help locate where the variables are located in RAM. Overall, they're a handy way to group similar data.

If you ever need to, calculating the size of an array in terms of its bytes is simple. Remember how each each data type has a byte-size in RAM? We use that to calculate the size of an array.

For instance, if we were to have an array of `some_type`, we calculate the size of the array by the following:
```
   (byte-size of some_type) * (amount of some_type in array) = total byte-size of array
```

Simply put: If we have an array of twelve doubles, the byte-size of the array is `12 * 8 = 96 bytes`.

Click [here](http://www.cplusplus.com/doc/tutorial/arrays/) and look through all until the topic "Arrays as Parameters" (this topic deals with something else that we might go over later). 
This page also covers two-dimensional arrays (covered mid-way of this page), so if you want you can read that as well.

#### Comparing Arrays
Unfortunately, comparing two same-datatype arrays isn't as easy as using `==`. It's not too bad though: We use a `for` loop to do it, assuming we have a variable for the length 
of each (and that each is of equal length).

For example, assuming the arrays and size variables used are pre-defined:
```C++
  bool are_equal = true; //assume true for less coding later
  for(int i = 0; i < ARRAY_SIZE; ++i)
  {
    if(arrayone[i] != arraytwo[i])
    {
      are_equal = false;
      i = ARRAY_SIZE; //to get out of the loop
    }
  }
  
```

Note that, with the above example, we could have used 'break;' instead of 'i = ARRAY_SIZE;'. I'm just showing an alternative way to exit a `for` loop.

#### Parallel Arrays
When we have corresponding data it might be handy to use parallel arrays. They help when you have a list of records to keep, e.g. student names and student ids.

With my example before, the parallel array code would look similar to the following:
```C++
  cosnt int STUDENT_COUNT = 20; //arbitrary value
  
  string first_name[STUDENT_COUNT];
  string last_name[STUDENT_COUNT];
  int student_id[STUDENT_COUNT];
  
  //Initialization code for arrays
  
  first_name[0] = "Bob";
  last_name[0] = "Willis";
  student_id[0] = "0001";
  
  cout << "Here is the first student: ";
  cout << last_name[0] << ", " << first_name[0] << " has ID: " << student_id[0] << endl;
  
```

Output:
```
  Here is the first student: Willis, Bob has ID: 0001
```

#### Two Dimensional Arrays
Another type of array, two-dimensional arrays help with storing data as a sort of grid. They can be made as either square or rectangular. They work just like matrices (in the sense of accessing rows 
and columns).

When we were creating arrays before, they were one-dimensional arrays. This just means it required a single index to access a position. You can pretty much guess how many indices a two-dimensional 
array needs to access a piece of data in it.

Also, if you're curious, comparing two-dimensional arrays is just like comparing normal arrays: You must access and compare each corresponding position.

For example, assuming each array is initialized before usage (and they are the same size):
```C++
  
  bool are_equal = true; //assume true for nicer code
  
  for(int r = 0; r < ROW_SIZE; ++r)
  {
    for (int c = 0; c < COL_SIZE; ++c)
    {
      if(arrayone[r][c] != arraytwo[r][c])
      {
        are_equal = false;
        break; //get out of inner loop if case was found
      }
    }
    
    if(!are_equal)
    {
      break; //break out of outer loop as well
    }
  }
```

NOTE: Breaks are fine for this, but using something like `c = COL_SIZE;` then afterwards `r = ROW_SIZE;` might be better because it removes the need for an outer if-statement (where that if-statement is checked 
every single loop).

Here if you don't understand how the edit looks like:
```C++
  
  bool are_equal = true; //assume true for nicer code
  
  for(int r = 0; r < ROW_SIZE; ++r)
  {
    for (int c = 0; c < COL_SIZE; ++c)
    {
      if(arrayone[r][c] != arraytwo[r][c])
      {
        are_equal = false;
        c = COL_SIZE; //go to end of inner loop
        r = ROW_SIZE; //go to end of outer loop
      }
    }
  }
```

When comparing two two-dimensional arrays, it's important that they are of the same size. If you don't do this, chances are you'll get an out-of-bounds error when accessing an array position in either (or both) 
two-dimensional array. Also, if they are not of equal size, that automatically means the two 2d-arrays are unequal. It helps to think of these as matrices.

At this point, you should move onto the File IO page [here](file_io_new.md).

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
