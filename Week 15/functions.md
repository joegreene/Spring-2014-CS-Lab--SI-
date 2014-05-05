# Week 15

## Contents
- [Intro](#intro)
- [User-Defined Functions](#functions)
  - [What is a User-Defined Function?](#what-is-a-user-defined-function?)
  - [Initialize a User-Defined Function](#)
  - [Function Prototypes](#function-prototypes)
  - [Using Your Functions](#)
  - [](#)
  - [Why Have User-Defined Functions?](#)
- [Practice Assignments](#practice-assignments)
- [Extra Challenges](#extra-challenges)

### Intro
This page goes over general ideas with functions.

### User-Defined Functions
You've been working with functions already, except they were pre-defined functions. Now we'll start creating 
our own (user-defined) functions, which makes programming a heck of a lot nicer on our end for various reasons.

#### What is a User-Defined Function?
Literally what it states in its name, a user-defined function is a function made by the user. They allow us to create a snippet of 
code that can be reused.

The structure of a function in C++:
```
  return_type function_name ()
  {
    //code
    //return type
  }
```

The best way (in my opinion) to understand these is to think about math. In math, a function is simply an equation that takes an input and yields an output. 
If, for instance, we wanted to make a function that represents a parabola shifted right 5 units and up one, we would have the following:
```
  f(x) = (x-5)^2 + 1
```

The above takes some value x as an input, and yields a f(x). The C++ version of this is the following:
```C++
  double funct(double x)
  {
    double output = pow(x-5, 2.0) + 1;
    return output;
  }
```

In the C++ version, we have to define the type of input and type of output. 

#### Initialize a User-Defined Function
Normally, user-defined functions are set up above main. We have our header/library includes, our namespace usage, any global variables we 
may need, then our functions, and finally afterwards our main function. Visually, this would look like the following: 

```
  Libraries/Headers
  using namespace stuff
  Global variables
  Functions
  main
```

As a C++ example, using the parabola function we discussed in the previous section:
```C++
  #include <iostream>
  using namespace std;
  
  //Any sort of global variables go here
  
  
  
  int main()
  {
    //code
  }
  
```

__NOTE:__ Remember that order is important -- We need to make sure that the function is visible by main before using it.



#### Function Prototypes
To make your code look less messy at startup, we use __function prototypes__ to let the compiler know that we will eventually 