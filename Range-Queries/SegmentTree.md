# Range Query – Identity & Neutral Elements Reference

This repository file serves as a central cheat sheet for **Neutral Elements (Identity Elements)**, **Data Types**, and **Merge Operations**. Use this reference to configure your template constructors, lazy propagation nodes, or sparse table variables instantly during contests.

---

##  Core Operations Reference Table

| Operation | C++ Type | Neutral Element (`neutral_value`) | Merge Logic / Code | Use-Case Examples |
| :--- | :--- | :--- | :--- | :--- |
| **Range Sum** | `long long` / `int` | `0` | `a + b` | Standard addition |
| **Range Minimum** | `long long` | `2e18` (`LLONG_MAX`) | `min(a, b)` | Dynamic / Static Range Min |
| **Range Maximum** | `long long` | `-2e18` (`LLONG_MIN`) | `max(a, b)` | Dynamic / Static Range Max |
| **Range GCD** | `long long` / `int` | `0` | `std::__gcd(a, b)` | Overlap-friendly GCD queries |
| **Range XOR** | `long long` / `int` | `0` | `a ^ b` | `X ^ 0 = X` |
| **Range OR** | `long long` / `int` | `0` | `a \| b` | Bitwise inclusive OR |
| **Range AND** | `unsigned long long` | `~0ULL` (All bits `1`) | `a & b` | `X & 111...111 = X` |
| **Range Product** | `long long` / `int` | `1` | `a * b` | Standard multiplication |

---

##  Framework Specific Implementations

### 1. Segment Tree, Lazy propagation
in consturctor `Node()` we will replace the value with it's suitable initial value.


### 2. Sparse Table (The Skip / Initialization State)
in variable `skip` we will initialize it with it's suitable initial value.

<!-- ### 4. Matrix Exponentiation Queries
When applying Range Queries on transitions or graphs using matrices:
* **Matrix Multiplication Identity:** The **Identity Matrix** (Main diagonal filled with `1`s, all other cells are `0`s).
* **Shortest Path Matrix (Distance Product):** Main diagonal filled with `0`s, all other cells are **`INF`**. -->


---
*💡 Tip: Keep this reference lightweight. Append new complex identities (e.g. Bitset ranges) as you solve more advanced problems.*
