# C++


This repository contains my solutions and notes for the Codam C++ modules.
Each module has its own `README.md` with detailed explanations and exercises. This file provides a high-level overview of the topics covered across all modules.

### C++ Concepts

Access c++ manual page in therminal: `man std::vector`

- `getters` Make a private attribute readable.
- `setters` Make a private attribite writable.
- `::` scope resolution operator.
- `Namespace` declarative space that provides scope to identifiers (functions, variables...). Organize code into logical groups, to prevent name collisions.

---
<br/>


### Orthodox Canonical Form

Classes following the canonical form should implement:

- **Default constructor**
- **Copy constructor**: Initializes a new object as a copy of an existing one.
- **Copy assignment operator**: Assigns one object's contents to another.
- **Destructor**

> 💡 **Deep copy** creates a new object and recursively copies members. 

> 💡 **Shallow copy** duplicates references, not the data — changes affect both.

---
<br/>


### 📦 Modules Overview

#### [Module 00](./Module_00)
Namespaces, classes, member functions, initialization lists, `static`, `const`, and basic I/O streams.

#### [Module 01](./Module_01)
Memory allocation, pointers to members, references, and switch statements.

#### [Module 02](./Module_02)
Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical class form.

#### [Module 03](./Module_03)
Inheritance.

#### [Module 04](./Module_04)
Subtype polymorphism, abstract classes, and interfaces.

#### [Module 05](./Module_05)
Exception handling and repetition.

#### [Module 06](./Module_06)
C++ type casts (`static_cast`, `dynamic_cast`, etc.).

#### [Module 07](./Module_07)
C++ templates.

#### [Module 08](./Module_08)
Templated containers, iterators, and algorithms.

#### [Module 09](./Module_09)
STL (Standard Template Library).

---
