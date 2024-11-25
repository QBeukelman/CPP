# C++

[C++ Language Reference](https://learn.microsoft.com/nl-nl/cpp/cpp/cpp-language-reference?view=msvc-170)

`man std::toupper`

`git push -u origin head`

`getters` Make a private attribute readable
`setters` Make a private attribite writable

`::` scope resolution operator. 

`Namespace` declarative space that provides scope to identifiers (functions, variables...). Organize code into logical groups, to prevent name collisions.

### Orthodox Canonical Form

- **Default constructor**
- **Copy constructor** (initialize a previously uninitialized object from other object's data)
- **Copy assignment constructor** (replace the data of a previously initialized object with other object's data)
- **Deconstructor**

Deep copy creates a new object and itrativly copies its members.
Shallow copy creates a new object and maintains reference to the orignal. This can be faster, but changing the copy will change the orignal.