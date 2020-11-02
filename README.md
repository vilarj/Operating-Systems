# README

## Introduction

In this project you will be working on a number of small projects to get used to the C programming language.
FIrst follow the instructions in [Installation.md] to get Ubuntu LTS (20.04) installed on your system.

Once Ubuntu and the build-essentials package is installed on your system, clone the Github classroom link onto your
system using git.

git clone {GITHUB_URL}

You may also choose to skip Github classrom and download the ZIP file instead. In this case, please upload the ZIP file
in Brightspace.

Once the repository is downloaded on your system, go through each level one by one. You do not need to follow in
order, but the directories will be explained in order below.

TL;DR Fix anything that says TODO

## Level 1

In this level, you will be writing some simple functions to compute statistics. The directory contains the following
files:

- stats.c: This is the main C source file that will contain code for the functions. You will need to modify this file.
- stats.h: This is the main header file for this directory. In order to use the functions, the header file must first
    be included (otherwise the compiler will complain).
- Makefile: The makefile uses the make program to compile the C programs. To use this file, you can run two commands in
    this directory:
    * `make` will compile the programs `make clean` will clean things up
- test_two_averages.c: This file contains various test cases that can be used to help you implement Level 1 Part A,
    compute averages over two numbers
- test_array_averages.c: This file contains various test cases that can be used to help you implement Level 1 Part B,
    compute averages over an array

### Level 1 Part A

For this part, you will implement a function that returns the average over two integer numbers. The function definition
looks like the following:

   float two_averages(int a, int b);

and should return the arithmetic mean of `a` and `b`.

### Level 1 Part B

For this part, you will implement a function that returns the average over an array of integers. If the array is empty
(length 0), then the function should return 0.0. The function definition looks like the following:

   float array_averages(int *array, int array_len);

`array` points to an integer array of size `array_len`.

## Level 2

In this level, you will practice using struct types. The type you will be implementing will keep track of time,
using two different member variables. It should look like the following:

| Member       | Type |
|:------------:|:----:|
| Seconds      | int  |
| Milliseconds | int  |

One thing to note about the struct is that it has an invariant. It should make sure that the milliseconds field is >=0
and less than 1000.

THe directory contains the following files:

- time.c: This is the main C source file that will contain code for the functions. You will need to modify this file.
- time.h: This is the main header file for this level. In order to use the functions, the header file must first be
    included (otherwise the compiler will complain). You will need to modify this file as well.
- Makefile: This file uses the make program to compile the C programs.
- test_time_assign.c: This file contains various test cases that can be used to help you implement Level 2 Part A.
- test_time_diff: This file contains various test cases for Level 2 Part B.

### Level 2 Part B

For this part, you will implement a function that acts as a "constuctor" to the struct type. The function definition
looks like the following:

    struct time time_assign(int seconds, int milli);

and should return a new struct with the seconds field and milliseconds field filled in. Note that to preserve the type
invariant, any milliseconds value that's outside of the valid range should adjust the seconds field accordingly. For
example, time_assign(0, 1001) should return 1 second and 1 milliseconds.

You should also document the header file time.h. Example for how to do so can be found in level1/stats.h (essentially
Javadoc-style)

### Level 2 Part B

Fir this part, you will implement a function that will take the difference between to times, and return milliseconds.
The function definition looks like the following:

    int time_diff_in_milli(struct time t1, struct time t2)

and should return t1 - t2. Here again, remember that you should preserve the type invariants and make sure that the
milliseconds field is within bounds.

You should also document the header file time.h. Example for how to do so can be found in level1/stats.h (essentially
Javadoc-style)

## Level 3

In this level, you will practice working with C-style strings (or 0-terminated strings). Recall that a string in C is
an array of `char`s, with a 0 at the end. This is quite different from strings in other languages, for example strings
in Java. In this level you'll be exercising a number of features unique to C-style strings.

Note: To reduce misunderstanding `size` means the size of an array, whereas `length` means the length of a string
(number of chars).

### Level 3 Part A

For this part, you will implement a function that returns the length of a string. In other languages, the string object
themselves contain the length. However, in C, the length of the string is implicit. As an alternative, one option is to
create a variable that manually holds on to the length. However, sometimes you don't know what the length is (i.e. user
input). In tihs case, you need to look at the data and count, until you find the terminator (denoted as '\0'), but *exclude*
the terminator.

The function definition looks like the following:

   int get_string_length(char* s);

The function should return the length of the string (excluding the terminator!). If `s` is NULL, return -1 instead.

To be a bit more concrete, let's take a look at the following string "Hello". In the computer, this string looks like
the following:

|1|2|3|4|5|6|
|-|-|-|-|-|-|
|H|e|l|l|o|\0|

The array of chars has size 6, *but*, the length of the string is 5.

How about an empty string?

|1|
|-|
|\0|

Thus, the length of the string is 0, although the size of the array is actually 1.

What about `s` being a NULL? Because strings are char arrays, someone can always pass a NULL pointer. In this case, the
function should return -1. Returning a negative length is a commonly used trope to indicate invalid input.

You should also document the header file string.h. Example for how to do so can be found in level1/stats.h (essentially
Javadoc-style)

### Level 3 Part B

For this part, you will implement a function that copies a string from one place to another. 

The function definition looks like the following:

   int string_copy(char* dest, char* s, int dest_size);

The function copies the string inside `s` into `dest`. If `s` is too large to fit within `dest`, you should copy only up
to `dest_size` - 1 characters, *not* `dest_size` characters. Why?

The function should return the number of characters copied as its return value. If either `s` or `dest` is NULL, the
function should return -1.

You should also document the header file string.h. Example for how to do so can be found in level1/stats.h (essentially
Javadoc-style)

## Grading Rubric

There are 6 sub-levels with equal weight each. Within each sublevel, you will be graded using the following criteria:

- 75% Specifications: The program should work and satisfy test cases
- 15% Readability: The program have clear flow and have clear documentation (including header file
    documentation).
- 10% Deliverables: There source code is delivered on time and without significant changes to make things work (i.e. if
    you use non-Ubuntu Linux GCC for development).
