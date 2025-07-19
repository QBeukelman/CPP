# Module 04

Subtype Polymorphism, Abstract Classes, and Interfaces


## Polymorphism

In C++, **polymorphism** is a core concept of **object-oriented programming** that allows objects of different types to be treated through the same interface.

---
<br/>


### 1. Compile-Time Polymorphism (Static)

When the decision about which function to call is made at compile time. It can be achieved through:

- **Function overloading**: Same function name with different parameter types.
- **Operator overloading**: Redefining operators like `+`, `-` for custom types.


### 2. Run-time polymorphism (Dynamic polymorphism)

The decision about which function to call is made at runtime, usually using inheritance and virtual functions.

- **Virtual functions**: A base class function that can be overridden in derived classes.
- **Base class pointers/references**: Used to invoke overridden functions of derived classes.

---
<br/>


## Abstract Class (Virtual class)

In c++ an abstract class is a class that cannot be instanciated directly, it is meant to be inherited from, not used on its own. You can create an abstract class when you want to define a common interface or base structure for derived classes, but can not create a base version.

A class becomes virtual when you define a least one **pure virtual function**. A pure virtual function is a function that must be overridden in derived classes; it is declared in a base class but has no implementation (empty body).

```
virtual void someFunction() = 0;
```

```cpp
class Animal {
public:
    virtual void speak() const = 0; // pure virtual (interface)
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof\n"; }
};

Animal* a = new Dog();
a->speak();  // Outputs: Woof
```

- `virtual` in base class declaration. Enables derived class to override "dynamic dispatch (polymorphism)".

- `override` in derived class implementations. Ensures that the method overrides the virtual methon in base class.


### Interface in C++

While C++ doesn't have a keyword interface like Java/C#, we can simulate one using an abstract class with only pure virtual functions and no data members.

> 💡 An "interface" is just an abstract class in C++ that defines a contract: what a class should do, but not how.

---
<br/>


## Diamond inheritance problem

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

---