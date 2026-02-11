# C++ Module 06 — ex01: Serializer

## Overview
Demonstrates safe pointer serialization and deserialization using `reinterpret_cast` and `uintptr_t`. Converts a `Data*` to an integer type (`uintptr_t`) and back.

## Build
- Requires a C++98-compatible compiler.
- Uses the provided Makefile.

```sh
make
```

This produces the `serializer` binary.

## Run
Run without arguments to see serialization/deserialization demonstration:

```sh
./serializer
```

## Notes
- `serialize(Data*)` returns a `uintptr_t`, preserving the pointer value.
- `deserialize(uintptr_t)` returns the original `Data*`.
- This exercise illustrates type-punning via `reinterpret_cast` and the use of an integer type guaranteed to hold a pointer.
