# Module_08

# STL (Standard Template Library) Containers

## 1. Sequence containers

- vector
- list
- deque
- array
- forward_list

### std::vector

A vector in c++ is essentially a dynamic array, which grows automatically. Vectors use contiguous memory storage, meaning elements are stored next to eachother in memory, allowing for fast random-access.

- Fast incertion/removal at end `O(1)`.
- Slow incertion/removal in middle `O(n)`, items neet to be shifted.

### std::list

A list in c++ is implemented as a `doubly-linked list`. Lists use non-contiguous memory storage, and random access is not supported.

- Find item `O(n)`.
- Incertion/removal in middle `O(1)`.
- Lists are useful for splicing operations, moving items between lists.

## 2. Associative Containers

- set
- map
- multiset
- multimap

### std::map & std::set

These are ordered containers based on `balanced binary-trees`. Elements in maps and sets are always sorted by key.

> **Maps** - do not allow duplicate keys, each element is unique. A map stores key value pairs.

> **Set** - is a collection of unique keys only.

- Fast look-up operations `O(log(n))`.



## 3. Unordered Containers

- unordered_set
- unordered_map
- unordered_multiset
- unordered_multimap

