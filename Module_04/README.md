# Subtype Polymorphism, Abstract Classes, and Interfaces

## Polymorphism

In c++ polymorphism is a core concept of **object-oriented programming** that allows objects of different types to be treated through the same interface.

### 1. Compile-time polymorphism (Static polymorphism)

When the decision about which function to call is made at compile time. It can be achieved through:

- **Function overloading:** Same funcation name with different parameters.
- **Operator overloading:** Redefining operators line `+`, `-` etc, for your own types.

### 2. Run-time polymorphism (Dynamic polymorphism)

The decision about which function to call is made at runtime, usually using inheritance and virtual functions.

- **Virtual functions**: A virtual function in base classes is a function that can be overridden in derived classes.
- **Base class pointers** or reference pointing to derived class objects.


## Abstract Class (Virtual class)

In c++ an abstract class is a class that cannot be instanciated directly, it is meant to be inherited from, not used on its own. You can create an abstract class when you want to define a common interface or base structure for derived classes, but can not create a base version.

A class becomes virtual when you define a least one **pure virtual function**. A pure virtual function is a function that must be overridden in derived classes; it is declared in a base class but has no implementation (empty body).

```
virtual void someFunction() = 0;
```

### Diamond inheritance problem

```
    A
  /   \
 B     C
  \   /
    D
```

- `B` and `C` inherit from class `A`.
- `D` inherits from both `B` and `C`.

Without special handeling, class `D` will inherit two copies of `A`, one from `B` and one from `C`. This leads to ambiguity and inefficenty.

C++ introduces virtual inheritance to solve this problem. Instead of both `B` and `C` creating its own copy of `A`, they share a singe shared base.
