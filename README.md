# Leetcode-279.-Perfect-Squares
# Minimum Number of Perfect Squares

This repository explains the solution for finding the **minimum number of perfect square numbers which sum to a given number `n`**.

---

## 📖 Problem Statement

Given an integer `n`, return the least number of perfect square numbers (for example, `1, 4, 9, 16, ...`) which sum to `n`.

### Example:

```txt
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9
```

---

## 🔧 Approaches

### 1. 🤝 Recursive + Memoization (Top-down Dynamic Programming)

We use a recursive function `hlo(n)` to solve the problem:

* At each step, we try subtracting every perfect square `i*i` (where `i*i <= n`)
* For every subtraction, we solve the subproblem `n - i*i`
* We memoize the results using a `dp[]` array to avoid recomputation

#### Base Cases:

* If `n == 0` ➔ return 0 (no squares needed)
* If `n == 1` ➔ return 1 (only 1^2 needed)

#### Transition:

```cpp
hlo(n) = min(hlo(n - i*i) + 1) for all i such that i*i <= n
```

#### Memoization:

We use `dp[n]` to store the result for each value of `n` once it is computed.

---

## ⏱ Time Complexity

* **O(n \* sqrt(n))**

  * For each number from `1` to `n`, we try up to `sqrt(n)` square numbers

## 📊 Space Complexity

* **O(n)** for the memoization array `dp[]`
* **O(n)** recursive stack depth in worst case

---

## 🎨 Example Trace

Let's say `n = 12`:

* Try 1^2: `12 - 1 = 11` ➔ recurse
* Try 2^2: `12 - 4 = 8` ➔ recurse
* Try 3^2: `12 - 9 = 3` ➔ recurse
* Eventually finds: `4 + 4 + 4`

---

## 👤 Author

**Ridham Garg**
B.Tech Computer Engineering
Thapar University, Patiala
Roll Number: 102203014

---

Feel free to ⭐ star this repo if it helped you!

Happy Coding! 🤖
