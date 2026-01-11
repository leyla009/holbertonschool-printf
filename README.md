Description

This project is a custom implementation of the C standard library function printf. It was developed as part of the low-level programming curriculum. The function handles formatted output to the standard output stream, mimicking the behavior of the original printf while adhering to strict coding standards.
Technical Specifications

    Environment: Ubuntu 20.04 LTS

    Compiler: gcc

    Flags: -Wall -Werror -Wextra -pedantic -std=gnu89

    Style: Betty Style

    No Global Variables

    Maximum 5 functions per file

Authorized Functions & Macros

    write (man 2 write)

    malloc (man 3 malloc)

    free (man 3 free)

    va_start (man 3 va_start)

    va_end (man 3 va_end)

    va_copy (man 3 va_copy)

    va_arg (man 3 va_arg)

Implemented Conversions

The function _printf handles the following conversion specifiers:
Specifier	Description
%c	Prints a single character.
%s	Prints a string of characters.
%%	Prints a percent sign.
%d	Prints a decimal (base 10) number.
%i	Prints an integer.

(Note: Add %b, %u, %x, etc., if you completed those specific advanced tasks.)
Usage

To use this function in your code, include the header file:
C

#include "main.h"

Compilation Example
Bash

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf

Example Code
C

#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Character: %c\n", 'H');
    _printf("Score: %d%%\n", 100);
    return (0);
}

Files
File	Description
_printf.c	Main function file that parses the format string.
main.h	Header file containing all prototypes and standard library includes.
man_3_printf	Custom manual page for the _printf function.
functions.c	Helper functions for printing characters and strings.
Authors

    Leyla Khaspoladova

    Nigar Namazova 
