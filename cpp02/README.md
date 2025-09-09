# C++ Module 02: Ad-hoc Polymorphism, Operator Overloading, and Orthodox Canonical Form

This module focuses on ad-hoc polymorphism, operator overloading, and implementing classes in the orthodox canonical form. The exercises revolve around creating a fixed-point number class.

## Exercises

### Exercise 00: My First Class in Orthodox Canonical Form

This exercise introduces the `Fixed` class, which represents a fixed-point number. The focus is on implementing the class in the orthodox canonical form, which includes a default constructor, a copy constructor, a copy assignment operator, and a destructor.

**Files:**
- `ex00/Fixed.hpp`, `ex00/Fixed.cpp`
- `ex00/main.cpp`
- `ex00/Makefile`

### Exercise 01: Towards a more useful fixed-point number class

This exercise extends the `Fixed` class by adding constructors to create instances from integers and floats, and methods to convert them back. It also overloads the `<<` operator to allow for easy printing of `Fixed` objects.

**Files:**
- `ex01/Fixed.hpp`, `ex01/Fixed.cpp`
- `ex01/main.cpp`
- `ex01/Makefile`

### Exercise 02: Now we're talking

This exercise further enhances the `Fixed` class by overloading a comprehensive set of operators:
- Comparison operators: `<`, `<=`, `>`, `>=`, `==`, `!=`
- Arithmetic operators: `+`, `-`, `*`, `/`
- Increment/decrement operators: `++`, `--`

It also includes static `min` and `max` functions.

**Files:**
- `ex02/Fixed.hpp`, `ex02/Fixed.cpp`
- `ex02/main.cpp`
- `ex02/Makefile`

### Exercise 03: BSP

This exercise introduces a `Point` class that uses the `Fixed` class for its coordinates. It also includes a function `bsp` (Binary Space Partitioning) that determines if a point is inside a triangle.

**Files:**
- `ex03/Point.hpp`, `ex03/Point.cpp`
- `ex03/Fixed.hpp`, `ex03/Fixed.cpp`
- `ex03/main.cpp`
- `ex03/Makefile`
