
## Ex02

`str` This is the regular base string.
`stringPTR` A pointer to the string. This is the actual address of the string. To access the string it needs to be dereferenced.
`stringREF` This is an alias for str, not a seperate object. You can change what it points to. Changes to stringREF directly effect str, vice versa. It does not need to be dereferenced.


## Ex03 Unnecessary Violance

`void attack() const;` -> Const does not modify the state of the object.

Reference (Weapon&):
- A reference must always point to a valid object and cannot be `nullptr`.
- Ownership is not transfered. A reference does not take ownership of the object it refers to. Referenced objects must exist for the duration the reference is being used.

Pointer (Weapon*):
- Can point to `nullptr`. Can or cannot be a valid object. Need to check pointer before dereferencing it.
- Ownership can be changed by assigning a new pointer to another object.
