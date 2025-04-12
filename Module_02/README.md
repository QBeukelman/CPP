# Module_02

## Orthodox Canonical Form

### Opererator Overload

`Fixed& operator=(const Fixed& other);`

- The `operator=` keyword indicates this function is an overload of the `=` operator. It defines how the `=` operator behaves when used with `Fixed` objects.
- For example `b = a` will call this function.
- The `operator=` ensures that a deep copy of the `_wholeValue` is performed.
- Returning `*this` allows chaining of assignments, like `a = b = c`.


## Left shift operation `<<`

Left shifting is bitwise operation that shifts the bits of a number to the left by a specified number of positions. it's often used to multiply by powers of 2, as it moves the bits to higher place values.

`int result = number << n;`

- Shift the bits of `number` to the left by `n` positions.
- With each left shift, a `0` is assed to the rightmost (least significant) bit.
- In essence, multiplying by the number by `2`.

`5 << 1`

- The binary number shifts to the left by one position:
	- Before:		00000101 (5)
	- After:		00001010 (10)


## Fixed-poing numbers

A **fixed-point number** is a way to represent real numbers (numbers with a fractional part). A fixed-point number has a fixed number of digits after the decimal point (the point is fixed).

Suppose you have 8 bits to store a number.

- You could reserve 5 bits for the whole number part (integer).
- And 3 bits for the fractional part.

This could be represented as:

- `00010.101` -> 2.625
- `11111.111` -> 31.875

### Why use fixed-point numbers?

- **Faster and simpler** than floating point numbers.
- **More pridictable**, having the same precision throughout, without rounding errors.
 

## Floating Point Number Representation and Programming Considerations

Modern systems predominantly use the **IEEE-754** standard for floating-point number representation. This standard defines floats (4 bytes) and doubles (8 bytes) as consisting of three parts:

- **Sign bit**: Indicates positive or negative.
- **Exponent**: Encodes the order of magnitude (using a "shift-127" method for single precision).
- **Mantissa**: Represents the digits of the number, with an implied leading 1 ("1.m" representation).

### Accuracy vs. Precision

**Floating Point Numbers:**

Represent "real" numbers with decimals, capable of very large or small magnitudes.

**Precision**: Floats retain more granular details (fractional parts) than integers, never deliberately discarding information.
**Accuracy**: Floats are less accurate because not all fractions can be represented exactly in binary (e.g., 1/3 or 0.1).

### Integer Arithmetic:
Completely accurate; operations like addition and subtraction produce exact results as long as there’s no overflow.
Lack precision when dividing numbers, as fractional parts are discarded (e.g., 5/2 results in 2).

### Special Cases:

Zero: Represented with all bits set to zero.
Infinity (+/-): Exponent bits set to all 1s, with a zero mantissa.
NaN (Not-a-Number): Exponent bits set to all 1s, with a non-zero mantissa.

### Key Characteristics:

The smallest representable numbers and precision vary between single and double precision floats.
Special cases allow extremely small numbers (denormalized floats) at the cost of precision.
The smallest epsilon (difference such that 1 + epsilon > 1) reflects the precision limit of the representation.

### Programming Guidelines:

Equality Comparisons: Floating-point numbers should not be directly compared with `==`. Instead, use a tolerance or define "close enough" by comparing relative differences.
Overflow Handling: Floats gracefully handle overflow by representing results as `+/-inf`. However, converting large floats to integers risks loss of precision.
Avoid Loss of Significance: Rearrange calculations to prevent subtraction of nearly equal numbers or summing small terms after large terms, which can lead to precision loss.
Numerical Stability: Algorithms with feedback loops may accumulate floating-point errors. Favor resetting values explicitly when possible.
Leverage Integers: For fractional calculations, consider representing values as rational numbers (numerator and denominator) to avoid floating-point issues entirely.
