# Week 15

## Contents
- [Intro](#intro)
- [User-Defined Functions](#user-defined-functions)
  - [What is a User-Defined Function?](#what-is-a-user-defined-function)
  - [Initialize a User-Defined Function](#initialize-a-user-defined-function)
  - [Function Prototypes](#function-prototypes)
  - [Parameters and Arguments](#parameters-and-arguments)
  - [Using Your Functions](#using-your-functions)
  - [Various Return Types](#various-return-types)
- [Practice Assignments](#practice-assignments)
- [Extra Challenges](#extra-challenges)

### Intro
This page goes over general ideas when using functions. If you at all find my work to be hard to understand, hopefully [this](http://www.cplusplus.com/doc/tutorial/functions/) or 
[this](http://www.tutorialspoint.com/cplusplus/cpp_functions.htm) may suffice. If you plan to go that route, make sure to only read up to "Functions with no type. The use of void." on 
the cplusplus page, and "Calling a Function" on the tutorialspoint page.

### User-Defined Functions
You've been working with functions already, except they were pre-defined functions. Now we'll start creating 
our own (user-defined) functions, which makes programming a heck of a lot nicer on our end for various reasons.

#### What is a User-Defined Function?
Literally what it states in its name, a user-defined function is a function made by the user. They allow us to create a snippet of 
code that can be reused and can be extremely useful if we have similar code throughout our program.

The structure of a function in C++:
```
  return_type function_name(parameter, parameter1, parameter2, parameter3, ...)
  {
    //code
    //return a value of a return type
  }
```

Where the return_type must match the value that's returned in the end, each parameter is an input used in the function, the line
```
  return_type function_name(parameter, parameter1, parameter2, parameter3, ...)
```

is the function header, and the inside (between curly braces) is the function body.

The best way (in my opinion) to understand these is to think about math. In math, a function is simply an equation that takes in an input and yields an output. 
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

where `double funct(double x)` is the function header, `double output = pow(x-5, 2.0) + 1;` is the code, `return output` is the returned value, and both the code and return 
statement make up the function body.

In the C++ version, we have to define the type of input and type of output. The following does the same exact process as the previous function:
```C++
  double funct(double x)
  {
    return pow(x-5, 2.0) + 1;
  }
```

Which omits the need for a variable to hold the equation required (inside the code part).

Note that `int _tmain(...)` or `int main()` are both functions. You'll (hopefully) begin to understand each part in the following notes.

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
  
  double funct(double x)
  {
    double output = pow(x-5, 2.0) + 1;
    return output;
  }
  
  int main()
  {
    //code
    return 0;
  }
  
```

__NOTE:__ Remember that order is always important in programming -- We need to make sure that the function is "visible" by main before using it. To see why, try putting 
the parabola function definition below the main function and see what happens.

#### Function Prototypes
Although it's true that the function must be noticeable by whatever is calling it (in our case that's main), there is a way to make it so we define our 
function afterwards.

Function prototypes allow us to let the compiler know that we "will eventually" define the function in the same source file (.cpp). This helps make 
our code look a little bit more neat, although to some it might not make a difference at all.

A function prototype is just the function header, followed by a semi-colon:
```
  return_type function_name(parameter, parameter1, parameter2, ...);
```

If we wanted to revise our code from before to incorporate function prototypes, we have:
```C++
  #include <iostream>
  using namespace std;
  
  //Any sort of global variables go here
  
  double funct(double x);
  
  int main()
  {
    //code
    return 0;
  }
  
  double funct(double x)
  {
    return pow(x-5, 2.0) + 1;
  }
  
```

which works exactly the same way. It makes for nicer code when using multiple functions, and lets anyone viewing your code know what type of functions you 
are making for your program (otherwise a nice layout for your work). One example of this would be:
```C++
  #include <iostream>
  using namespace std;
  
  int addition(int a, int b);
  int subtraction(int a, int b);
  int multiplication(int a, int b);
  int division(int a, int b);
  //and more functions
  
  int main()
  {
    //code
  }
  
```

where, if you were to have all the function headers and bodies typed above main, it might become difficult for someone looking at your code to understand where 
everything is beginning and stopping. It probably won't be so bad if you were to have small functions at this point in time, but when creating big functions 
function prototypes prove to be highly useful.

__NOTE:__ We can omit the variable name part in the function prototype if we like (but not in the function header), for instance:
```C++
  char grade(int, int);
```

is valid, but isn't necessarily good practice. The reason for this is because the parameters are left ambiguous. It might be okay in some cases, but most times 
it proves to be damaging. Function prototypes exist to make syntax easier to read, and adding ambiguity to them pretty much defeats their purpose.

#### Parameters and Arguments
Remember to distinguish the two (they are __NOT__ the same): Parameters are what's required by the function (located in the function header), arguments are 
what is being thrown into the function at a function call (function calls are talked about in the next section).

Although already shown a bit before: Parameters are defined just like variables are, except we don't (necessarily) assign to them a value. If we had a function 
to add two numbers and return their sum:
```C++
  int add(int a, int b)
  {
    return a+b;
  }
```

The parameters are int a and int b.

We can also have no parameters in our function. For instance, a practically useless function:
```C++
  int mult_one_two()
  {
    return 1*2;
  }
```

returns one and two multiplied.

__NOTE:__ I'm not sure about the exact limit on the number of parameters (number of arguments is limited by the number of parameters of course), but if you require more 
than six then your might need to revise how your function operates. Typically, functions require 0 to 4 parameters/arguments, although at times I've had to use 
around six (which looked nasty). I believe the limit is defined by the compiler used.

#### Using Your Functions
Just like function calls like `pow` and `getline`, we call our function by typing `function_name` followed by a set of parenthesis, whatever parameters 
we need, and a semi-colon to end the statement.

Visually, this is:
```C++
  function_name(argument, argument1, argument2, ...);
```

which simply called the function, or

```C++
  some_var = function_name(argument, argument1, argument2, ...);
```

where the latter assigns the output of the called function to some_var.

If we wanted to print the (x,y) position of the parabola function made previously for x-inputs -2 to 2, all we need to do is:
```C++
  #include <iostream>
  using namespace std;
  
  double funct(double x);
  
  int main()
  {
    double x[] = {-2,-1,0,1,2};
    double y[5];
    for(int i = 0; i < 5; i++)
    {
      y[i] = funct(x[i]); 
    }
  }
```

Where each time we call our function, it puts the output into each position of the array y.

If you have a value returned by a function, chances are you're going to want to set a variable equal to whatever is returned by the function called. Although we 
can call the function without assigning it to a value (like above), most times it's unnecessary (except when using return type void, talked about in the following 
section).

#### Various Return Types
We can have varying return types, as long as they are defined and readily accessible for us to use.

Examples of different types of function prototypes (with different return types):
```C++
  char letter_grade(double grade);
  double get_avg(int list[]);
  string print_name(string first_name, string last_name); //remember to include "string"!
  void do_work();
```

The above three are pretty simple -- First returns a char type, second is a double, and third is a string. The last one returns nothing, otherwise 
that's what a void function does. It's set to do something, and that's it (nothing returned). If you ever hear it, void functions are sometimes referred to as 
"black box" functions (since they return no value, all the work done somewhat gets sucked into the function... if that makes sense).

If we wanted to make the function body of the last function prototype, we might have something like:
```C++
  void do_work()
  {
    char input = ' ';
    cout << "Work? ";
    cin >>input;
    //do more code
    
    return; //optional
  }
```

where the return statement `return;` just exits the function. We can omit that part too if we wish and the function would behave just as same.

### Practice Assignments
TBD

### Extra Challenges
Read past the points I mentioned to stop at on the cplusplus and tutorialspoint links I shared under the introduction section.

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
