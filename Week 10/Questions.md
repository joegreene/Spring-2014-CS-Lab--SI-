# Week 10

## Contents
- [Sample Questions](#sample-questions)
- [Free Response Questions](#free-response-questions)

### Sample Questions:

1) What is the output of the following code?

```C++
  int i = 12;
  cout << i % 4 << endl;
```

a. 12 
 
b. 3 
 
c. 0 
 
d. 4 

2) What is `some_dbl` equal to after the below code segment is run?

```C++
  double some_dbl = 2.0;
  
  if (some_dbl == 4.0)
    some_dbl += 3.0;
    some_dbl -= 2.0;
    
  if (some_dbl = 1.1)
    some_dbl = -1.3;
  
```

a. 2.0 
 
b. 4.0 
 
c. -1.3 
 
d. Compile error 
 
e. 3.0

3) What is the output of the following code if the user inputs `22 3` into the input stream?

```C++
  int some_num1, some_num2;
  
  cout << "Enter two numbers: ";
  cin >> some_num1 >> some_num2;
  
  if(some_num1 < some_num2 + 20) {
    cout << "First. "
    if(some_num1 != 22)
      cout << "Firstish. ";
  }
  else if(some_num2 == 3)
    cout << "Second. ";
  else
    cout << "Third. ";
    cout << "Done. ";
```

a. "First. Done." 
 
b. "First. Firstish. Done." 
 
c. "First. Second. Done." 
 
d. None of the above 
 
e. "Third." 

4) What is the output of the following code?

```C++
  int i = 55;
  cout << i % 7 << endl;
```

a. 6 
 
b. 0 
 
c. 55 
 
d. 7 

5) What is the output of the following code?

```C++
  bool not_true = -1;
  bool somewhat_true = 0;

  if(not_true)
    if(!somewhat_true)
      cout << "Okay ";
      cout << "Alright ";
  else
    cout << "Let's go." << endl;
```

a. "Okay Alright" 

b. "Alright." 

c. Compile error. 

d. "Okay Alright Let's go." 

e. "Let's go." 

### Free Response Questions

1) What are the five data types we most concern ourselves with in this class?

2) What are the five steps taken when compiling a program for use?

3) What is a programming language? What programming language are we concerning ourselves with? Name two other programming languages you've heard of.

4) What is an algorithm?