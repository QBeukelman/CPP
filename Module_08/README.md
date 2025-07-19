# Module 08

## 🧰 STL (Standard Template Library) Containers

This module covers the various STL container types in C++. STL containers are general-purpose classes and templates that store collections of objects.

---
<br/>


## 1. Sequence Containers

Sequence containers maintain the **order** of insertion. Common operations include element access, insertion, and deletion.

- `std::vector`
- `std::list`
- `std::deque`
- `std::array`
- `std::forward_list`

---

### 🔹 std::vector

A dynamically resizing array. Elements are stored in **contiguous memory**, enabling fast random access.

- Fast insertion/removal at the end: `O(1)`
- Slow insertion/removal in the middle: `O(n)` (elements must be shifted)
- Allocated on the **heap**
- Best for when frequent random access is needed

---

### 🔹 std::list

A **doubly-linked list** implementation.

- No random access — only sequential traversal
- Insertion/removal in the middle: `O(1)`
- Searching for an item: `O(n)`
- Useful for splicing (moving elements between lists in constant time)

---

### 🔹 std::forward_list

A **singly-linked list**. Similar to `std::list`, but with less overhead.

- No random access
- Insertion/removal at the front: `O(1)`
- More memory-efficient than `std::list`
- Cannot traverse backward

---

### 🔹 std::deque

A **double-ended queue**, allowing fast insertion and deletion at both front and back.

- Random access is supported but slightly slower than `std::vector`
- Internally implemented as a segmented array (not contiguous)
- Insertion/removal at both ends: `O(1)`
- Great when you need fast access to both ends

---

### 🔹 std::array

A fixed-size array. Size must be known at compile time.

- Allocated on the **stack**
- Supports random access (`O(1)`)
- Cannot resize
- Use when size is fixed and performance is critical

---
<br/>


## 2. Container Adaptors

These containers **wrap** other containers (like `deque` or `vector`) and restrict access to provide a specific data structure interface.

- `std::stack`
- `std::queue`
- `std::priority_queue`

---

### 🔹 std::stack

Implements **LIFO** (Last-In, First-Out) semantics.

- By default, uses `std::deque` internally
- Only allows access to the top element
- Operations: `push()`, `pop()`, `top()`

---

### 🔹 std::queue

Implements **FIFO** (First-In, First-Out) semantics.

- Also uses `std::deque` internally
- Operations: `push()`, `pop()`, `front()`, `back()`

---

### 🔹 std::priority_queue

Implements a **max-heap** by default.

- Elements are automatically ordered by priority
- Highest-priority item is always on top
- Internally uses a `std::vector` with `std::make_heap` / `push_heap`

---
<br/>


## 3. Associative Containers

These containers store sorted elements and provide fast **lookup** via keys using **balanced binary trees** (typically red-black trees).

- `std::set`
- `std::map`
- `std::multiset`
- `std::multimap`

---

### 🔹 std::set

- Stores **unique keys** in sorted order
- No duplicate values allowed
- Lookup, insert, and delete: `O(log n)`

---

### 🔹 std::map

- Stores **key-value pairs** with **unique keys**
- Values are associated with a key
- Lookup, insert, and delete: `O(log n)`

---

### 🔹 std::multiset

- Like `set`, but allows **duplicate keys**
- Useful for storing sorted values where duplicates are allowed

---

### 🔹 std::multimap

- Like `map`, but allows **duplicate keys**
- Useful when a key maps to multiple values

---
<br/>


## 4. Unordered Associative Containers

Unordered containers use **hash tables** instead of binary trees. They offer **average constant time** complexity for lookups and insertions (`O(1)`), but ordering is **not guaranteed**.

- `std::unordered_set`
- `std::unordered_map`
- `std::unordered_multiset`
- `std::unordered_multimap`

---

### 🔹 std::unordered_set

- Stores **unique keys**
- Elements are **not sorted**
- Lookup: average `O(1)`, worst-case `O(n)`

---

### 🔹 std::unordered_map

- Stores **key-value pairs** with **unique keys**
- Not sorted
- Lookup: average `O(1)`

---

### 🔹 std::unordered_multiset

- Like `unordered_set`, but allows **duplicate keys**

---

### 🔹 std::unordered_multimap

- Like `unordered_map`, but allows **duplicate keys**

---
<br/>


## Summary Table

| Container Type           | Ordered? | Allows Duplicates? | Key-Based? | Lookup Time    |
|--------------------------|----------|---------------------|------------|----------------|
| `vector`, `deque`, etc.  | Yes      | Yes                 | No         | `O(n)`         |
| `set` / `map`            | Yes      | No                  | Yes        | `O(log n)`     |
| `multiset` / `multimap`  | Yes      | Yes                 | Yes        | `O(log n)`     |
| `unordered_*`            | No       | Depends             | Yes        | `O(1)` average |


