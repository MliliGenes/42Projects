# C++ Module 01: Memory Allocation, References, Pointers, and Function Overloading

This module covers memory allocation, references, pointers to members, and function overloading in C++.

## Exercises

### Exercise 00: BraiiiiiiinnnzzzZ

This exercise introduces dynamic memory allocation in C++. It features a `Zombie` class that is allocated on the stack and heap.

**Files:**
- `ex00/Zombie.hpp`, `ex00/Zombie.cpp`
- `ex00/newZombie.cpp`
- `ex00/randomChump.cpp`
- `ex00/main.cpp`
- `ex00/Makefile`

### Exercise 01: Moar brainz!

Building on the previous exercise, this one introduces the concept of a "horde" of zombies, which is an array of `Zombie` objects allocated in a single block.

**Files:**
- `ex01/Zombie.hpp`, `ex01/Zombie.cpp`
- `ex01/zombieHorde.cpp`
- `ex01/main.cpp`
- `ex01/Makefile`

### Exercise 02: HI THIS IS BRAIN

A simple program that demonstrates the use of pointers and references in C++. It highlights the differences in how they are declared, used, and what they represent.

**Files:**
- `ex02/main.cpp`
- `ex02/Makefile`

### Exercise 03: Unnecessary violence

This exercise illustrates the difference between using a reference and a pointer as a member variable. It features `HumanA` and `HumanB` classes, each equipped with a `Weapon`.

**Files:**
- `ex03/Weapon.hpp`, `ex03/Weapon.cpp`
- `ex03/HumanA.hpp`, `ex03/HumanA.cpp`
- `ex03/HumanB.hpp`, `ex03/HumanB.cpp`
- `ex03/main.cpp`
- `ex03/Makefile`

### Exercise 04: Sed is for losers

A program that performs a search and replace operation on a file. It reads a file, replaces all occurrences of a given string with another, and writes the result to a new file.

**Files:**
- `ex04/searchAndReplace.hpp`, `ex04/searchAndReplace.cpp`
- `ex04/main.cpp`
- `ex04/Makefile`

### Exercise 05: Harl 2.0

This exercise was skipped.

### Exercise 06: Harl

A program that features a `Harl` class with methods to complain at different levels (DEBUG, INFO, WARNING, ERROR). The `complain` method uses a pointer to a member function to call the appropriate private method.

**Files:**
- `ex06/Harl.hpp`, `ex06/Harl.cpp`
- `ex06/main.cpp`
- `ex06/Makefile`
