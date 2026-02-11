# C++ Module 06 — ex02: RTTI Identify

## Overview
Uses runtime type information (`dynamic_cast`) to identify the concrete type of objects derived from `Base` (`A`, `B`, `C`). Includes identification via both pointer and reference forms.

## Build
- Requires a C++98-compatible compiler.
- Uses the provided Makefile.

```sh
make
```

This produces the `identify` binary.

## Run
Run without arguments to generate and identify random instances:

```sh
./identify
```

## Notes
- `identify(Base*)` and `identify(Base&)` use `dynamic_cast` to detect `A`, `B`, or `C`.
- Random instance generation showcases RTTI behavior and exception handling for references.
- Useful for practicing polymorphism and safe downcasting.
