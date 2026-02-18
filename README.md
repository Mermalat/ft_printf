# ft_printf

*This project has been created as part of the 42 curriculum by merma.*

## Description
`ft_printf` is a custom implementation of the standard C library function `printf`. This project mimics the behavior of `printf` for a specific set of conversions, providing a deep understanding of variadic functions and formatted output in C.

## Instructions

### Compilation
To compile the library `libftprintf.a`, run:
```bash
make
```

### Usage
Include the header in your C source files:
```c
#include "ft_printf.h"
```

Compile your program with the library:
```bash
gcc main.c libftprintf.a -o my_program
```

### Conversions
The function handles the following conversions:
- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: The `void *` pointer argument is printed in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

## specificities
- Buffer management of the original `printf` is not implemented.
- The library is created using `ar` command.

## Resources
- [printf(3) man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- 42 School subject PDF.
