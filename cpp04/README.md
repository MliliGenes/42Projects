# C++ Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces

This module delves into subtype polymorphism, abstract classes, and interfaces in C++. The exercises focus on creating a hierarchy of classes and using virtual functions to achieve polymorphic behavior.

## Exercises

### Exercise 00: Polymorphism

This exercise introduces a base `Animal` class with derived `Cat` and `Dog` classes. It demonstrates polymorphism by calling the `makeSound()` virtual function on pointers to the base class. It also includes `WrongAnimal` and `WrongCat` classes to illustrate the importance of virtual destructors.

**Files:**
- `ex00/Animal.hpp`, `ex00/Animal.cpp`
- `ex00/Cat.hpp`, `ex00/Cat.cpp`
- `ex00/Dog.hpp`, `ex00/Dog.cpp`
- `ex00/WrongAnimal.hpp`, `ex00/WrongAnimal.cpp`
- `ex00/WrongCat.hpp`, `ex00/WrongCat.cpp`
- `ex00/main.cpp`
- `ex00/Makefile`

### Exercise 01: I don't want to set the world on fire

This exercise builds upon the previous one by adding a `Brain` class. The `Cat` and `Dog` classes are modified to have a `Brain`, which demonstrates the need for deep copies to avoid issues with shared data between objects.

**Files:**
- `ex01/Animal.hpp`, `ex01/Animal.cpp`
- `ex01/Cat.hpp`, `ex01/Cat.cpp`
- `ex01/Dog.hpp`, `ex01/Dog.cpp`
- `ex01/Brain.hpp`, `ex01/Brain.cpp`
- `ex01/main.cpp`
- `ex01/Makefile`

### Exercise 02: Abstract classes

This exercise introduces the concept of abstract classes by making the `Animal` class abstract. This is achieved by declaring at least one pure virtual function, which prevents the class from being instantiated directly.

**Files:**
- `ex02/AnimalA.hpp`, `ex02/AnimalA.cpp`
- `ex02/Cat.hpp`, `ex02/Cat.cpp`
- `ex02/Dog.hpp`, `ex02/Dog.cpp`
- `ex02/Brain.hpp`, `ex02/Brain.cpp`
- `ex02/main.cpp`
- `ex02/Makefile`

### Exercise 03: Interfaces and recap

This exercise introduces the concept of interfaces and abstract classes. It features an `AMateria` abstract class and two interfaces, `ICharacter` and `IMateriaSource`. This allows for a flexible system where different types of "materia" can be created and used by characters.

**Files:**
- `ex03/AMateria.hpp`, `ex03/AMateria.cpp`
- `ex03/ICharacter.hpp`
- `ex03/IMateriaSource.hpp`
- `ex03/Character.hpp`, `ex03/Character.cpp`
- `ex03/MateriaSource.hpp`, `ex03/MateriaSource.cpp`
- `ex03/Ice.hpp`, `ex03/Ice.cpp`
- `ex03/Cure.hpp`, `ex03/Cure.cpp`
- `ex03/main.cpp`
- `ex03/Makefile`
