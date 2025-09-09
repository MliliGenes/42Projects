# ft_printf

`ft_printf` is a project from 42 school that requires us to re-implement the famous `printf` function from the C standard library. This project is a great way to learn about variadic functions and how to handle different data types in C.

## Supported Format Specifiers

My implementation of `ft_printf` supports the following format specifiers:

- `%c`: Prints a single character.
- `%s`: Prints a string of characters.
- `%p`: Prints a pointer address in hexadecimal format.
- `%d`: Prints a decimal number (base 10).
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal number.
- `%x`: Prints a number in hexadecimal (base 16) with lowercase letters.
- `%X`: Prints a number in hexadecimal (base 16) with uppercase letters.
- `%%`: Prints a percent sign.

## How to Use

1. **Compile the library:** Run `make` to compile the project and create a static library `libftprintf.a`.
2. **Include the header:** Include the `ft_printf.h` header file in your C project.
3. **Link the library:** When compiling your project, link it with the `libftprintf.a` library.

## Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("The answer is %d.\n", 42);
    ft_printf("Hexadecimal for 42 is %x.\n", 42);
    return (0);
}
```
