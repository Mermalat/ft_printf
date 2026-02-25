*This project has been created as part of the 42 curriculum by merma.*
# ft_printf

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

## Hex conversions — details

- **Algorithm**: For hexadecimal representation the number is divided by 16 to extract digits. To print the most significant digits first, the function is typically called recursively: for example `if (n >= 16) recurse(n / 16); write_digit(n % 16);` which prints digits from high to low.

- **Character selection**: A fixed character array is used to map a nibble (0..15) to its character. Use `"0123456789abcdef"` for lowercase hex and `"0123456789ABCDEF"` for uppercase. Indexing the array (e.g. `digits[n % 16]`) returns the corresponding character.

- **Code line explained**: The expression `ft_putchar_len("0123456789ABCDEF"[n % 16]);` does the following:
  - `"0123456789ABCDEF"` provides a string literal containing all hex digits.
  - `[n % 16]` selects the character corresponding to the current nibble (0..15).
  - The selected character is passed to `ft_putchar_len`, which writes the character using `write` and returns the number of bytes written (1).

- **Notes**: `ft_puthex_len` switches between lowercase and uppercase based on the `format` parameter (`'x'` or `'X'`). When printing pointers (`%p`) the address is cast to `unsigned long` (`(unsigned long)ptr`) since pointer width is platform dependent.

## specificities
- Buffer management of the original `printf` is not implemented.
- The library is created using `ar` command.

## Variadic Functions — In-Depth Overview

This project aims to teach the correct and safe usage of variadic functions in C, which form the core of `ft_printf`. Below are the fundamental mechanics, important rules, and common pitfalls when working with variadic functions.

- **Basic concepts**: Variadic functions accept a variable number of arguments after a fixed set of parameters. In standard C this is handled using macros and types from `stdarg.h`: `va_list`, `va_start`, `va_arg`, `va_end`, and `va_copy`.

- **Main macros**:
  - `va_list ap;` — declares a variable representing the argument list.
  - `va_start(ap, last_fixed_arg);` — initializes `ap` to point to the first variadic argument; `last_fixed_arg` is the last fixed parameter (for example the format string).
  - `va_arg(ap, type)` — retrieves the next argument from `ap` as `type` and advances the list.
  - `va_end(ap)` — performs cleanup for `ap` (required by the standard).
  - `va_copy(dest, src)` — copies a `va_list`; the copied list must be ended with `va_end` as well.

- **Default argument promotions**:
  - In variadic calls a `float` is promoted to `double`, and small integer types like `char` and `short` are promoted to `int` or `unsigned int`. Therefore you must request the promoted type with `va_arg` (e.g. use `double` for a `float`). Using the wrong type invokes undefined behavior.

- **Correct type selection**:
  - Use the actual (possibly promoted) type that was passed: `int`, `unsigned int`, `long`, `long long`, etc.
  - For pointer types (`char *`, `void *`) use `va_arg(ap, void *)` or the appropriate pointer type.

- **Safe forwarding / forwarding va_list**:
  - If a function receives a `va_list` and needs to pass it on (or re-use it), use `va_copy` to make a copy and end both lists with `va_end`.

- **Usage example (simple)**:

```c
#include <stdarg.h>
#include <stdio.h>

void example(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int i = va_arg(ap, int);       // the caller must have passed an int
    double d = va_arg(ap, double); // float arguments are promoted to double
    char *s = va_arg(ap, char *);
    va_end(ap);
    printf("i=%d d=%f s=%s\n", i, d, s);
}
```

- **`ft_printf` specifics**:
  - While parsing the format string, each conversion specifier (`%d`, `%s`, `%p`, `%x`, etc.) corresponds to pulling an argument with `va_arg` of the correct type: `%d`/`%i` → `int`, `%u` → `unsigned int`, `%p` → `void *`, `%x`/`%X` → usually `unsigned int`.
  - Flags, field width, and precision are parsed first, then the appropriate argument is read and converted (number → string, pointer → hex string, etc.).

- **Common mistakes and pitfalls**:
  - Passing the wrong type to `va_arg` (for example using `float` instead of `double`) causes undefined behavior.
  - Failing to call `va_end` may cause issues on some implementations.
  - Mismatches between the format string and the provided arguments (e.g. `%s` but an `int` is passed) lead to undefined behavior.
  - Consuming a `va_list` multiple times without copying it first is an error.

- **Performance and design notes**:
  - Functions like `printf` perform format-string parsing and argument handling, which has non-trivial cost; avoid unnecessary formatting when performance matters.
  - Use standard helpers like `vsnprintf`/`vfprintf` to centralize `va_list` handling and reduce code duplication.

This section collects the theory and practical tips needed to understand how `ft_printf` works. Paying careful attention to `stdarg.h` usage, correct `va_arg` types, and the format-string parsing logic is essential for a reliable implementation.

## Resources
- [printf(3) man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- 42 School subject PDF.
