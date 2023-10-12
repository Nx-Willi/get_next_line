# 🖱 42Paris Project | ft_printf

## Objectives

The goal of this project is to make a function that will read from a given file descriptor line by line.  
The return of the function is the line that is readed, NULL otherwise.

## Usage

Prototype: `char *get_next_line(int fd);`  
Compile: `clang -D BUFFER_SIZE=42 *.c`  
The given a.out will read in **testX** files in **tests** folder

## Tester

To test this project the following tester were usefull:  
- https://github.com/Tripouille/gnlTester  
It help me a lot to understand treaky behaviors.
