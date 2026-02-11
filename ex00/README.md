# C++ Module 06 — ex00: ScalarConverter

## Overview
Converts a literal provided as a command-line argument to `char`, `int`, `float`, and `double`, printing all conversions. Handles special pseudo-literals like `nan`, `+inf`, `-inf`, and their `f` variants, plus single-character input.

## Build
- Requires a C++17 compiler.
- Uses the provided Makefile.

```sh
make
```

This produces the `convert` binary.

## Run
Provide a single literal as argument:

```sh
./convert 42
./convert a
./convert 3.14f
./convert nan
./convert -inff
```

## Notes
- Inputs accepted: single `char`, integral numbers, `float` with `f` suffix, and `double`.
- Pseudo-literals are printed according to specification and may be non-displayable for `char`.
- Overflow and non-convertible cases are reported appropriately.
