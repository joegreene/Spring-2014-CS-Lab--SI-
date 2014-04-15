# Week 12

## Contents
- [Intro](#intro)
- [Arrays](#arrays)
  - [Holding Multiple Values](#holding-multiple-values)
  - [Accessing Array Contents](#accessing-array-contents)
  - [Mixing Concepts: Loops and Arrays](#mixing-concepts-loops-and-arrays)
  - [Other Ways to Initialize Arrays](#other-ways-to-initialize-arrays)
  - [Summary: Arrays](#summary-arrays)
- [Practice Assignments](#practice-assignments)
- [Extra Challenges](#extra-challenges)

### Intro
We'll be talking about these in lecture. Pretty much, arrays are a neat way to store a list of the same object. [This](http://www.cplusplus.com/doc/tutorial/arrays/) explains it pretty well although we'll cover more on what they are in the following sections on this page.

### Arrays
Let's say we wanted to have a list of scores for some skaters, and we knew for sure the scores would be 
given to us in order. Currently, we would then have a program like the following to get the job done.
```C++
  double score0, score1, score2, score3, score4, score5;
  
  cout << "Enter first, second, third, fourth, fifth, and sixth score: ";
  cin >> score0 >> score1 >> score2 >> score3 >> score4 >> score5;
```

... and we would have to make as many variables and as many `cin` statements as we needed in order to 
account for each skater score. While doing this, you may be thinking to yourself: Isn't there a more efficient way to do this? Of course there is!

We'll work at this in the following sections.

#### Holding Multiple Values
Since the scores are similar variables (i.e. they are all `double`), we can convert this nasty code:
```C++
  double score0, score1, score2, score3, score4, score5;
```

Into this, much easier to type code:
```C++
  double scorelist[6];
```

The syntax structure for an array is as follows:
```C++
  datatype identifier[size];
```

What we did above is created an (one-dimensional) __array__ of doubles of size 6. The "one-dimensional" part doesn't really matter to us for now (in about two weeks it will), it just means that it's working one way (left to right). As this type of array is type double, we are allowed to hold multiple double variables within it. When we say size of 6, we mean that we allowed ourselves to have a total of six doubles inside our array. 

The size is important, especially when we work with initializing arrays. We'll begin to understand why this is in the following section.

#### Accessing Array Contents
Alright, we made the code a bit cleaner, but how exactly do we access the contents of the array?

In order to grab values from an array we grab values by __index__. This pretty much means we grab the value by the position (index) it is in within the array.

Let's say, for instance, we wanted to set the value of the first score to `8`. All we have to do is the following:
```C++
  scorelist[0] = 8;
```

It's really that simple. If we wanted to change the last score in the array to 10 (because we have bias, beats me) we can do the following:
```C++
  scorelist[5] = 10;
```

At this point, many students raise the question: Why is the first value in the array equal to 0, and the last value equal to one less than the total size? 

Well, a couple of reasons for this include: So we have an extra value to work with, it's how our counting system works (e.g. we count by the decimal system, or 0 through 9 until we go to the next place value), and certain algorithms only work when starting from zero (making our lives easier when implementing them). It's also due to how arrays work in RAM. 

Keep in mind that, to account for starting at zero, we have to shift back one value from the maximum (in our case, our last value is five and not six).

Here is a general rule when accessing an array:
> The valid index range of an array is 0 <= n < length of array, where n is an integer


If we attempt to access a index outside of the above range, what we get is an `out of bounds exception`. This is because there are no negative positions nor are there positions outside of the array within the array. This probably seems like a no-brainer, but many errors with arrays come from this and being confused on what index you're on.

If we were to initialize the remainder of our code, we would have something like the following:
```C++
  double scoreslist[6]; //array of doubles, for scores
  
  cout << "Enter first, second, third, fourth, fifth, and sixth score: ";
  cin >> scorelist[0] >> scorelist[1] >> scorelist[2] >> scorelist[3] >> scorelist[4] >> scorelist[5];
```

Keep in mind that, at first, the values in an array are either uninitialized or are set to zero. Whichever value it is (be it garbage or zero), we'll want to initialize the list as soon as possible if we plan on using it to our disposal.

#### Mixing Concepts: Loops and Arrays
The beginning seems nicer now, but the latter seems even worse. How do you suppose we can fix that?

To further make our code much easier to type (and read), instead of our previous code we may do the following:
```C++
  double scoreslist[6];
  
  int score_amt = 6;
  
  cout << "Enter first, second, third, fourth, fifth, and sixth score";
  
  for (int i = 0; i < score_amt; i++)
  {
    cin>>scoreslist[i];
  }
```

This way we can easily initialize each position, type less lines of code, and spend less time doing the same thing over and over.

#### Other Ways to Initialize Arrays
If we know already what values we want for the array upon initialization, we can write the following:
```C++
  int evens[] = {2,4,6,8,10};
```

Note that we didn't specify a size. The reason we can get away with this is because we specified a size __implicitly__. 

If we only know some of the variables, and will put the rest in later, we can also definite the size explicitly plus include variables on initialization:
```C++
  int fib_seq[100] = {1, 1, 2, 3, 5};
```

Which is the equivalent of doing:
```C++
  int fib_seq[100];
  fib_seq[0] = fib_seq[1] = 1;
  fib_seq[2] = 2;
  fib_seq[3] = 3;
  fib_seq[4] = 5;
```

We can use other data types as well for arrays. For instance:
```C++
  int odd_num_list[] = {1,3,5,7};
  bool truth_table[5];
  string names[] = {"Jack", "Jill", "Jacob", "Jennifer", "John"};
```

are all valid arrays.

Remember [c(haracter) strings](#https://www.prismnet.com/~mcmahon/Notes/strings.html)? Those are `char` arrays. Strings are technically character arrays as well, but can change size during compilation of the program's run time. This is one of the reasons we prefer using strings over cstrings in C++, and on top of that they're just plain easier to work with.

Note how we have been using "constant" numbers to define arrays? Because the size of an array is defined at start up, we're forced to stick with whatever size we allocate it to on initialization. This is one downfall of using an array.

If we wanted to have a variable define the size of the array, we can use the following:
```C++
  const int AMT_STUDENTS = 20;
  char grades[AMT_STUDENTS];
```

We can't use an a variable such as `int amt` because it isn't constant, and we can't use a `double` to represent the size of an array (we can't have half a position/index). We can't set the size of the array to a negative number, namely because that would make no sense logically.

#### Summary: Arrays
- Use an array...
  - When you have a list of similar variables (e.g. a score list or a list of merchandise)
  - Know the size of the array won't change over the course of the program (IMPORTANT!!!)
- Arrays can be defined three ways: explicitly (when defining the size) and implicitly (when the contents define the size), and a mixture of both
- The syntax structure of an array is always the same: datatype, name plus brackets with an optional size inside, then an optional initialization of some or all the variables. You must have either the size, the initialization, or both.
- It's best to initialize the array as soon as possible, like other variables, so you don't get uninitialization errors.
- The reange of indices in an array are `0 <= n < length of array` where n is an integer.

### Practice Assignments
1. Create an array to hold a list of the first 100 even integers using a loop, then print them out. Afterwards, print the sum of the array (i.e. sum of the first 100 even integers). You may mix the initialization and print list steps together if you know how to.

### Extra Challenges
1. Make a program to sort a list of numbers given by a user. You may want to look up sorting algorithms online, or use a temporary variable to hold a value as it goes. 

Look up two-dimensional arrays.

Loop up pointers and how they relate to both arrays and two-dimensional arrays.

-------------------------------------------------------------------------------
Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/Spring-2014-CS-Lab--SI-/>
