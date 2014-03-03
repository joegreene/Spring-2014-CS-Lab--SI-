# Week 7

## Contents
- [Solutions (From Last Week)](#solutions-from-last-week)
- [Intro](#intro)
- [Chapter 2]
  - [Preprocessor Directives]()
  - [Namespaces]()
  - [Identifiers]()
- [Chapter 3]()
  - [iomanip]()
  - [cmath]()
- [Chapter 4]()
  - [Little more with `switch`]()
  - [More with if/else/else-if statements]()
  - [Validating User Input]()
  - [Block & Scope]()
  - [The Conditional Operator]()
  - [More with Strings and Characters]()
  - [Enumeration]()
- [Worksheets & Extra Practice]()
  - [Solutions to Worksheets & Extra Practice]()
- [Extra Challenges]()

BEGINNING:
TOP TEN TYPES OF ERRORS YOU NORMALLY GET IN C++ -> Ask class to list these out.

### Solutions (From Last Week)
If you have not finished the work from Week 6, **DO NOT** look at the solutions yet. Other than that, as usual, they are located above all of this.

### Intro
Not much else is new here from Week 6. This'll elaborate more on certain sections I believe might have been an issue or unclear from last week (and previous weeks too), alongside continue with the rest of Chapter 4.
Other than that, near the top of this page click "Spring-2014-CS-Lab--SI-" and then "Week 6" to go back to last week's work, or simply click [here](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%206).

I've also added more exercises and included a work sheet on this page near the bottom, so each of you can make sure that you are comfortable with the current work.

### Chapter 2
This might seem like a blast from the past, but I figured I might as well add this here.

#### Preprocessor Directives
Remember that there are two types of preprocessor directives we will work with in this class: `#include` and `#define`. These always go above the user-defined code.

The include directive, namely`#include`, allows us to use premade libraries so we don't have to remake already-made work. This includes the commonly used `iostream` and `string` libraries. 

The define directive, or `#define`, allows us to create constant variables. These go directly below the included libraries and above `using namespace ...` or (if you are not using `using namespace ...`) above 
the main function.

Another note: Because in this class we are making projects under the "Win32 Console Application" option, make sure to leave the line `#include "stdafx.h` above all the code, and to use the precompiled main (otherwise the 
`_tmain` line given when starting up the project). For now, doing this will leave you with less issues overall.

#### Namespaces
Later on in the course we (might) learn about making out own namespaces. For what we're currently working on at the moment, I highly doubt we'll require to many any though. 

If you'd like, below is an example of one:

```C++
  #include "stdafx.h"
  #include <iostream>
  using namespace std; //std is short for standard
  
  namespace ens //ens is short for example namespace
  {
    double TAX_RATE = .075;
    double PRICE = 3.75;
  }
  
  int _tmain(int argc, _TCHAR* argv[])
  {
    int num_boxes = -1; //initialization
    double total_price = -1; //initialization
    
    cout << "Enter in how many boxes you would like to purchase: ";
    cin >> num_boxes; 
    
    total_price = num_boxes * ens::PRICE; //just like std, because we do not have "using namespace" for ens, we need to use the scope operator on this.
    
    total_price+=(total_price * ens::TAX_RATE); //add tax to total_price
    
    cout << "Your purchase will cost you: " << total_price;
    
    return 0;
  }
```

Namespaces are namely helpful when organizing a bunch of items and each can be grouped separately. A good way to think of these is it works like a folder, or some sort of divider in a folder. 
With the namespace `std`, both `cout` and `cin` are located in a namespace.

#### Identifiers


### Chapter 3

### Chapter 4
#### Little more with `switch`
Remember that, with switch statements, the `break` statement is essential for all cases except `default`.

```C++
  #include "stdafx.h"
  #include <iostream>
  #include <cctype> //explained in "More with Strings and Characters"
  
  using namespace std;
  
  int _tmain()
  {
    char grade = 'z'; //
    cout << "Enter a grade to determine: ";
    cin >> grade;
    switch(tolower(grade)) //explained in "More with Strings and Characters"
    {
      case 'a':
        
        break;
      case 'b':
        
        break;
      case 'c':
        
        
      case 'd':
        
        break;
      case 'f':
      
        break;
      default:
        cout << "Unsure of
        
    }
    
    return 0;
  }
```

For the above, try entering in each character in the 

#### More with if/else/else-if statements


#### Validating User Input
If we want, we can use if, else, else-if, and switch statements for validating user input. Because we have control 
over the input given to us, we can direct the flow in which the program uses said input.


#### Block & Scope


#### The Conditional Operator
Something not seen too often, the conditional operator . It is a ternary operator, meaning it acts upon three variables/values.

#### More With Strings and Characters


#### Enumeration
An extremely handy tool in programming, [enumeration](http://www.merriam-webster.com/dictionary/enumerate) allows us to create a list of variables with incrementing values. 

A C++ example of enumeration:
```C++
  //...code...
  
```

More information [here](http://www.cprogramming.com/tutorial/enum.html).

### Worksheets & Extra Practice
All the below work problems should be done by pencil/paper.

#### Problems
- [Some list of boolean shiz]()
- [if/else outputs]()
- [syntax worksheet (what's wrong with the line and fix the code segment)]()
- [programming process (and difference between computer/programs/programmer)]()
- [iomanip]()
- [cmath stuff]()
When you are done with these, check `solutions.txt` to compare your answers to the actual ones. Alternatively, check your answers with Visual Studio outputs.

### Extra Challenges
If you feel comfortable with all the work we've done so far, I would suggest reading ahead in our book (Chapter 5).

Other than that, here's a list of resources/practice you may check out:
  1. [Loops (look under iteration statements)](http://www.cplusplus.com/doc/tutorial/control/)
  2. [More Work on Loops](http://www.cprogramming.com/tutorial/lesson3.html)
  3. TBD
  
  ...
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Some notes grabbed from Dr. Tian's Chapter 3 Powerpoints

Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>