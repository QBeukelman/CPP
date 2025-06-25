# Module_06

## What is `uintptr_t`

An unsigned integer type with the property that any valid pointer to void can be converted to this type, then converted back to pointer to void, and the result will compare equal to the original pointer.


## What does it mean to serialize / deserialize?

Serialization is used in c++ for converting an object into a linear format (e.g. bytes or text) that can be sent somewhere.

- Save data to a file.
- Send over a network.
- Store in memory safely (e.g. for undo/redo).
- Cache, clone, or debug complex state.


## What does dynamic_cast<>() do?

Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.

`dynamic_cast< target-type >( expression )`

`target_type` - pointer to complete class type, reference to complete class type, or pointer to void.
`expression` - value of a complete class type if target target_type is a reference.


## What does it mean to have a virtual destructor?

`virtual ~Base();` ->  a virtual destructor ensures that the correct destructor is called when deleting a derived class object through a base class pointer.

```cpp
struct Base {
	virtual ~Base() {
		std::cout << "Base destroyed\n";
	}
};

struct Derived : Base {
	~Derived() {
		std::cout << "Derived destroyed\n";
	}
};

int main() {
	Base* obj = new Derived;
	delete obj;  // Calls Derived::~Derived() then Base::~Base()
}

// Derived destroyed
// Base destroyed
```
