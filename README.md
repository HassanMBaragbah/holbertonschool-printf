# C - _printf

## Description
This project is a custom implementation of the C standard library function `printf`. The `_printf` function produces output according to a format string, handling conversion specifiers, standard input/output formatting, and variadic arguments using custom implementation patterns.

This project was developed as a collaborative group effort at Holberton School / Tuwaiq Academy.

---

## Authorized Functions & Macros
* write (man 2 write)
* malloc (man 3 malloc)
* free (man 3 free)
* va_start (man 3 va_start)
* va_end (man 3 va_end)
* va_copy (man 3 va_copy)
* va_arg (man 3 va_arg)

---

## Compilation & Options
All files will be compiled on Ubuntu 20.04 LTS using gcc with the following flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
---

## Handled Specifiers

| Specifier | Description | Example Output |
| :---: | :--- | :--- |
| %c | Prints a single character | _printf("%c", 'A') -> A |
| %s | Prints a string of characters | _printf("%s", "Hello") -> Hello |
| %% | Prints a literal percent symbol | _printf("%%") -> % |
| %d / %i | Prints a signed decimal integer | _printf("%d", 1024) -> 1024 |

---

## Function Prototypes

### Primary Function
`int _printf(const char *format, ...);`  
**Return Value:** Returns the total number of characters printed (excluding the null byte used to end output to strings), or -1 if an error occurs or if format is NULL.

### Helper Functions
* `int print_char(va_list args);`  
  **Return Value:** Returns 1 (the number of characters printed for a single character).

* `int print_string(va_list args);`  
  **Return Value:** Returns the total number of characters printed in the string, or 6 if string is NULL (prints "(null)").

* `int print_percent(va_list args);`  
  **Return Value:** Returns 1 (prints literal `%`).

* `int print_int(va_list args);`  
  **Return Value:** Returns the total count of digits/characters printed for signed integers (`%d` / `%i`).

* `int (*get_spec_func(char spec))(va_list);`  
  **Return Value:** Returns a pointer to the function that corresponds to the specifier, or NULL if no match is found.
  
---

## File Structure

| File | Description |
| :--- | :--- |
| main.h | Header file containing function prototypes, structure definitions, and standard library includes. |
| _printf.c | Main function that iterates through the format string and routes processing. |
| get_spec_func.c | Function pointer selector that maps specifier characters to their corresponding print functions. |
| print_functions.c | Contains handler functions for basic character and string conversion specifiers (%c, %s, %%). |
| print_numbers.c | Contains handler functions for integer conversions (%d, %i). |

---

## Usage Example

Create a test file main.c:

```c
#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");

    return (0);
}
```

Compile and run:
```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf
$ ./printf
```
Let's try to printf a simple sentence.
Length:[39, 39]
Character:[H]
String:[I am a string !]
Percent:[%]

---

## Coding Style & Standards
* All code adheres to the Betty Style guidelines. Checked using betty-style.pl and betty-doc.pl.
* No global variables are used.
* Functions are limited to a maximum of 5 per file.
* Header files are protected with include guards.
