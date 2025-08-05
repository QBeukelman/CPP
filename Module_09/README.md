# Module_09

Use generator for `ex02` for Merge-Insertion Sort (Ford-Johnson Algorithm).

```zsh
## Use included generator program
make generator && ./PmergeMe $(./generator 10 100)
```

---

<br/>



# 🔷 `ex00` Bitcoin Exchange

This program reads a list of Bitcoin transaction dates and values from `data/input.txt` and converts them into Euro amounts based on historical BTC exchange rates provided in `data/data.csv`.

For each input line, the value is matched to the corresponding (or closest earlier) date in the dataset, and the converted result is printed.


## 📦 Container Design: Why `std::array`?

The exchange rate data (from data.csv) is stored in a fixed-size container:

```cpp
std::array<RateEntity, N>
```

Motivation:
- The number of exchange rate entries is known or can be bounded in advance.
- std::array provides:
	- O(1) random access (like a C-style array or std::vector) needed for `Binary Search`.
	- No dynamic allocation at runtime (improves predictability and cache locality).
	- Safe indexing with bounds-checking via `.at()`.
	- Easy to sort using `std::sort` as it supports iterators.

Because the data set is relatively small and fixed in size, using `std::array`
is more efficient and deterministic than dynamic containers like `std::vector`
or `std::deque`.

---

<br/>



# 🔷 `ex01` Reverse Polish Notation

This exercise implements a calculator for evaluating expressions written in **Reverse Polish Notation (RPN)**, also known as postfix notation.

In RPN, operators follow their operands. For example:

- Input:	`3 4 + 2 * 7 /`
- Infix:	`((3 + 4) * 2) / 7`
- Output:	`2`

## 📦 Container Design: Why `std::stack`?

A **stack** is the natural and most efficient data structure for evaluating RPN expressions.

- **LIFO behavior** (Last In, First Out) matches RPN's operand order.
- No need for parentheses or operator precedence parsing.
- Operations are localized and easy to manage.
- STL's `std::stack` provides a clean abstraction with `.push()`, `.pop()`, `.top()`.

This makes the code simpler, safer, and more aligned with how postfix expressions are meant to be evaluated.

---

<br/>


# 🔷 `ex02` Merge-Insertion Sort (Ford-Johnson Algorithm)

The exercise requires sorting the same input using both containers to compare performance and demonstrate an understanding of their differences.

| Feature         | `std::vector`                      | `std::deque`                       |
|----------------|-------------------------------------|------------------------------------|
| Memory Layout  | Contiguous                         | Segmented                          |
| Access Time    | Fast random access (`O(1)`)        | Slightly slower than vector        |
| Insert/Erase   | Fast at end (`push_back`)          | Fast at both ends (`push_front`, `push_back`) |
| Cache Locality | Excellent                          | Moderate                           |
| Use Case       | Best for compact data & speed      | Best when frequent front insertion/removal is needed |

#### Motivation:

- `std::vector` is ideal for fast access, binary search, and sorting
- `std::deque` is included for completeness and performance comparison
- Running both highlights algorithmic behavior across different containers


### Jacobsthal Sequence Optimization

The **Jacobsthal sequence** is used during the insertion phase to decide the order in which `minima` elements are inserted. This reduces the number of comparisons in the worst-case scenario.

1. `J(0) = 0`
2. `J(1) = 1`
3. `J(n) = J(n-1) + 2 * J(n-2)`

By following this sequence, we insert elements in a way that balances the search space more effectively than a naive left-to-right approach.
