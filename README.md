# get_next_line Project

The get_next_line project is a critical component of the 42 school curriculum, designed to enhance students' understanding of file I/O operations and dynamic memory allocation in C programming. In this project, students are tasked with implementing a function that reads a line from a file descriptor and returns it without the newline character.

## Purpose

The primary objective of the get_next_line project is to deepen students' understanding of file handling in C and to introduce them to the concept of reading input from external sources such as files or standard input. By implementing a function capable of reading lines from a file descriptor, students gain practical experience in managing file streams, buffering input, and dynamically allocating memory to store data.

## Features

- Provides a function, `get_next_line`, capable of reading a line from a file descriptor and returning it as a dynamically allocated string.
- Supports reading lines of any length by dynamically resizing the buffer as needed.
- Handles multiple file descriptors simultaneously, allowing for concurrent reading from multiple files or input sources.
- Allows for easy integration into larger projects by providing a simple and intuitive interface for reading input from files.

## Usage

To use the get_next_line function in your projects, simply include the `get_next_line.h` header file and compile your source code with the `get_next_line.c` implementation file. The function takes a file descriptor as input and returns the next line from the corresponding file.

```c
#include "get_next_line.h"

int main(void) {
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
