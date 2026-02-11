<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Custom C Printf: A Low-Level Formatting Engine

This project is a custom implementation of the C standard library function `printf`. Developed from scratch, this function handles formatted output by parsing format strings and managing variable arguments without using the standard `printf` library. 

**This implementation was developed as a solo project, covering the full scope of design, logic parsing, and edge-case handling.**



## Tech Stack

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Ubuntu](https://img.shields.io/badge/Ubuntu-20.04LTS-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![Vim](https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white)
![Bash](https://img.shields.io/badge/bash-%234EAA25.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)

---

## Key Features

* **Variadic Functions:** Utilizes `va_list`, `va_start`, and `va_arg` to handle an unknown number of arguments.
* **Buffer Management:** Efficiently handles output to the standard output stream.
* **Complex Parsing:** Manages Flags, Width, Precision, and Length modifiers.
* **Custom Specifiers:** Includes advanced conversions like ROT13 and Binary.

### Supported Specifiers

| Specifier | Description | Example |
| :--- | :--- | :--- |
| `%c` | Single character | `_printf("%c", 'H');` |
| `%s` | String of characters | `_printf("%s", "Holberton");` |
| `%d` / `%i` | Signed decimal integer | `_printf("%d", 1024);` |
| `%b` | Binary conversion | `_printf("%b", 98);` // Output: 1100010 |
| `%u` | Unsigned decimal integer | `_printf("%u", 4000);` |
| `%o` | Octal (base 8) | `_printf("%o", 1024);` |
| `%x` / `%X` | Hexadecimal (lower/upper) | `_printf("%x", 255);` // Output: ff |
| `%p` | Memory address (pointer) | `_printf("%p", addr);` |
| `%R` | **ROT13** encoded string | `_printf("%R", "Hello");` // Output: Urryb |
| `%%` | Literal percent sign | `_printf("%%");` |

### Advanced Formatting Flags
| Flag | Description |
| :--- | :--- |
| **`-`** | Left-justify the output within the given field width. |
| **`+`** | Forces a sign (+ or -) to be used even for positive numbers. |
| **`0`** | Left-pads the number with zeroes instead of spaces. |
| **`.`** | Precision handling for strings and integers. |

---

## System Architecture

The project is structured to ensure modularity and scalability. Each file handles a specific set of logic to remain within the **Betty Style** constraints (max 5 functions per file).

| File | Responsibility |
| :--- | :--- |
| `_printf.c` | The main engine: parses the format string and calls specific handlers. |
| `main.h` | Global header containing function prototypes and the `struct` mapping specifiers to functions. |
| `print_functions.c` | Standard handlers for characters, strings, and integers. |
| `unsigned_functions.c` | Logic for `%u`, `%o`, `%x`, and `%X`. |
| `pointer_functions.c` | Custom logic for memory address printing and formatting. |
| `custom_string_functions.c`| Implementation of the **ROT13** (`%R`) specifier. |
| `man_3_printf` | A professional Unix manual page for this custom function. |

---

## Requirements & Compilation

* **Standard:** Compiled on Ubuntu 20.04 LTS using `gcc` with flags:  
  `-Wall -Werror -Wextra -pedantic -std=gnu89`
* **Style:** 100% compliant with the **Betty style guide**.
* **Memory:** Checked for leaks using **Valgrind**.

### Usage
```c
#include "main.h"

int main(void)
{
    _printf("Solo Project by: %s\n", "Leyla");
    _printf("Pointer Address: %p\n", (void *)0x7ffe637541f0);
    _printf("ROT13: %R\n", "Holberton");
    return (0);
}
```
## Author
**LEYLA KHASPOLADOVA**
GitHub: [@leyla009](https://github.com/leyla009)
