# Week 9

## Contents
- [Solutions (From Last Week)](#solutions-from-last-week)
- [Intro](#intro)
- [Chapter 1](#chapter-1)
  - [Definitions & Terms](#definitions-terms)
- [Chapter 2](#chapter-2)
  - [Operators (General)](#operators-(general))
    - [Arithmetic & Assignment](#arithmetic--assignment)
    - [Relational Operators](#relational-operators)
    - [Logical Operators](#logical-operators)
- [Chapter 3](#chapter-3)
  - [iomanip](#iomanip)
- [Chapter 4](#chapter-4)
  - [if/else statements](#if-else)
  - [switch](#switch)
  - [enum](#enum)
  - [Conditional Operator](#conditional-operator)
- [Miscellaneous](#miscellaneous)
  - [Truth Tables](#truth-tables)
- [Extra Challenges](#extra-challenges)

### Solutions (From Last Week)
In the usual spot (under files location) above. If there are any issues with it, let me (the SI instructor) know. I added in a bunch of 
comments, so hopefully the code isn't too difficult to run through.

### Intro
This week's work is to review/practice topics for the exam. It namely goes over topics people have felt to be difficult to grasp, or simply wanted to 
review.

Try doing as much of the material on this page as you can before referring to another information source (other than a partner).

### Chapter 1
Blast from the past, dawg. Really though, just to be safe you might be tested on the following terms (so remember them!).

#### Definitions & Terms
Here's a list of possible definitions/terms you might have to remember. I honestly doubt all of these would be on the exam(s), but to be safe it's 
best to get used to the terms anyways:

1. Computer
2. Program/Software; Types of software; Examples
3. Programmer
4. Hardware & its component categories; Examples of hardware; Hardware versus Software
5. CPU and its (Two) Components
6. Main Memory versus Secondary Storage; Give examples of each.
7. How is main memory organized? HINT: There are three types and think of the numbers 0 and 1.
8. Input/Output (I/O) devices; Give examples of each
9. Difference between a programming language and program
10. What is an algorithm?
11. High-level language versus low-level language
12. Process of a high-level program to an executable file
13. Difference between a variable, identifier, and literal.
14. Types of errors and debugging
15. Anything else I might have missed from the Chapter 1 notes

See if you can come up with the definitions/examples/etc. per term.

Look at the power point notes of Chapter 1 for answers.

__NOTE:__ In my previous programming courses, on exams we focused more on terms relating to syntax, memory types, algorithms, high/low level languages, and types of errors. It's good 
to know the other terms too, but the others weren't focused on as much from what I remember.

### Chapter 2
Just operator stuff. Good to practice if you're still are hesitant with type coercion, division, modulus, etc. I've sort of snuck in `cmath` into the first portion as well. For all of 
these (except cmath), check the Chapter 2 notes for more information if required. cmath can be found under Chapter 3.

#### Operators
##### Arithmetic & Assignment
Other than below, check Lab 3 and 4 for practice as well.

__Questions and Practice__:

1. What is an assignment operator? Give an example of one in use.
2. How would you translate [this]() into C++ code? You only need to provide a snippet.
3. Create a program to calculate the square root of a number, including imaginary numbers. An example output is provided in the "example outputs" folder.

##### Relational Operators
Other than the practice we did in the SI session, check Lab 4 for practice.



##### Logical Operators
Other than the practice we did in the SI session, check Lab 4 and 5 for practice.



### Chapter 3
Only covers one topic: iomanip. You might want to try this one at home, since it might take a bit to type out. 

#### iomanip
Refer to either some online reference, Lab 4, the teacher's notes, or [Week 6's notes](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%206) on this site to review these topics. 

__PRACTICE:__
Create a program that converts fahrenheit to celsius (or vice-versa, doesn't matter) but prints out its result similar to the example outputs provided 
under the example outputs folder on this page (at the top). 

__NOTE:__ The output does not need to be exactly the same as mine. This is merely practice, but if you can get it to look like mine then that's cool too.

If you want it exactly like mine though, there are fifty dashes, the temperature outputs cover five spaces and are right-justified (so having temperatures more than five digits cause errors), 
the periods fill in roughly the same range (doesn't have to be exactly the same as mine), the "Celsius" and "Fahrenheit" prompts are left-justified and cover about 12-13 spaces. I didn't care 
too much about having the digits cover more, although you're free to use iomanip to support more places.

Make sure to use `iomanip`, have the menu, and _DO NOT__ simply type in spaces to do the correct output. It doesn't need to loop like the output does, just have similar output for doing the work 
(i.e. ask the user once, then quit). If you'd like, practice loops (although they won't be on the upcoming exam next week). I only included loops in my version to make my life easier to show example 
outputs.

### Chapter 4
Review over if/else statements, switch cases, and enumerated data types.

#### if/else statements
Refer to the Chapter 4 powerpoint, the book, the [Week 6](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%206) notes, or some other online source and try the following:

__Problems:__
1. Write two different ways to check whether or not a character variable equals 'y' (e.g. if input is yes). Print to the user whether they chose yes or no afterwards.
2. Write two ways to check if a value is between a set range, then for each way see if the value is the average of the range. In this, have the upper limit as 100 and lower limit as 1.

#### switch
Refer to the powerpoint on Chapter 4, the [Week 6](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%206) and [Week 7](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%207) 
notes, or any online sources to do the following:

__PRACTICE:__
1. Make a program that can calculate the square root of a number, even if the number inputted is negative. Remember to use only a switch case in this. HINT: sqrt(-49) = sqrt(-1) * sqrt(49); example output: sqrt(-49) = 7i
2. Redo problem 1 from the if/else statements section so that you're only using a switch statement, and write it in two different ways (HINT: Nearly the same technique as if/else).

__Questions:__
1. Which is more robust: switch or if/else? Why?
2. Can all if/else statements be translated to switch cases? Why or why not? Give an example as proof.
3. Can all switch statements be translated to if/else cases? Why or why not? Give an example as proof.
4. Can a switch statement go inside an if/else statement? Can an if/else statement go inside a switch statement? Provide examples of each if so.

#### enum
Either look at the Chapter 4 powerpoint, the book, the [Week 7](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%207) notes, or some online reference.

__Practice:__
1. Make a program that allows the user to input a number (from 1 to 7) and outputs the day of the week, alongside stating whether or not its a weekend, weekday, or humpday (Wednesday).
2. 

__Questions:__
1. What does it mean for a data type to be enumerated?
2. In what situations would we use an enumerated data type? In which situations would enumerated data types prove to be inferior to other methods?
3. Can we set up enumerated data types without an identifier? 
4. Are enumerated data types immutable (i.e. are they constant)?

#### Conditional Operator
Refer to the Chapter 4 powerpoint, the book, [Week 7](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/tree/master/Week%207) notes, or an online resource.

### Miscellaneous
#### Truth Tables
If you're ever given a tough boolean statement to work with, a neat way to solve them (other than looking for least-precedent operators) 
is by using a truth table. I don't think you guys will need this for the upcoming exam, but it's good to know for future usage.

[This site](http://www.cs.utah.edu/~germain/PPS/Topics/truth_tables_and_logic.html) looks promising to help you guys out. If you'd like too, I can write up an example 
on the board to better clarify this topic.

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>

Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>