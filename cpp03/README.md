# C++ Module 03: Inheritance

This module explores the concept of inheritance in C++, including single, multiple, and virtual inheritance, as well as the diamond problem.

## Exercises

### Exercise 00: Aaaaand... OPEN!

This exercise introduces the `ClapTrap` class, a simple robot with attributes like hit points, energy points, and attack damage. This class will serve as the base for other classes in this module.

**Files:**
- `ex00/ClapTrap.hpp`, `ex00/ClapTrap.cpp`
- `ex00/main.cpp`
- `ex00/Makefile`

### Exercise 01: Serena, my love!

This exercise introduces the `ScavTrap` class, which inherits from `ClapTrap`. `ScavTrap` is a specialized version of `ClapTrap` with its own unique ability, `guardGate`.

**Files:**
- `ex01/ScavTrap.hpp`, `ex01/ScavTrap.cpp`
- `ex01/main.cpp`
- `ex01/Makefile`

### Exercise 02: Repetitive work

This exercise introduces the `FragTrap` class, another specialized version of `ClapTrap`. `FragTrap` has its own unique ability, `highFivesGuys`.

**Files:**
- `ex02/FragTrap.hpp`, `ex02/FragTrap.cpp`
- `ex02/main.cpp`
- `ex02/Makefile`

### Exercise 03: Now it's weird!

This exercise introduces the `DiamondTrap` class, which inherits from both `ScavTrap` and `FragTrap`. This demonstrates multiple inheritance and the challenges that come with it, such as the diamond problem. The `DiamondTrap` class has a special `whoAmI` function to display its name and its ClapTrap name.

**Files:**
- `ex03/DiamondTrap.hpp`, `ex03/DiamondTrap.cpp`
- `ex03/main.cpp`
- `ex03/Makefile`
