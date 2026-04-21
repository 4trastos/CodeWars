<p align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&duration=3000&pause=500&color=00FFAA&center=true&vCenter=true&width=600&lines=CodeWars+Training+%7C+4trastos;C+%7C+C%2B%2B+%7C+Python;Low-Level+%7C+Algorithms+%7C+Data+Structures" alt="Typing SVG" />
</p>

<p align="center">
  <a href="https://www.codewars.com/users/4trastos">
    <img src="https://www.codewars.com/users/4trastos/badges/large" alt="CodeWars Badge"/>
  </a>
</p>

---

## 📌 About

Personal repository tracking my [Codewars](https://www.codewars.com/users/4trastos) progress.  
All solutions are written from scratch — no AI-generated code. Every kata is debugged and tested locally before submission.

**Current focus:** C → C++ → Python  
**Goal:** Reach 4 kyu in C, then expand to C++ and Python for robotics/defense career targets.

---

## 📊 Stats

| Language | Rank | Katas Completed |
|----------|------|-----------------|
| C        | 5 kyu | 21             |
| C++      | —    | —               |
| Python   | —    | —               |

> Stats updated manually. Check live profile: [codewars.com/users/4trastos](https://www.codewars.com/users/4trastos)

---

## 🗂️ Solutions

### C

#### 4 kyu
| Kata | Solution |
|------|----------|
| [Snail Sort](https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1) | [solution.c](C/4kyu/snail/solution.c) |
| [Hamming Numbers](https://www.codewars.com/kata/526d84b98f428f14a60008da) | [solution.c](C/4kyu/hamming_numbers/solution.c) |

#### 5 kyu
| Kata | Solution |
|------|----------|
| [Weight for Weight](https://www.codewars.com/kata/55c6126177c9441a570000e0) | [solution.c](C/5kyu/weight_for_weight/solution.c) |
| [First Non-Repeating Character](https://www.codewars.com/kata/56a80c2f372c9ea6280000db) | [solution.c](C/5kyu/first_non_repeating/solution.c) |
| [ROT13](https://www.codewars.com/kata/52223df9e8f98c7aa7000062) | [solution.c](C/5kyu/rot13/solution.c) |
| [Primes in numbers](https://www.codewars.com/kata/54d512e62a5e54c96200019e) | [solution.c](C/5kyu/primes_in_numbers/solution.c) |
| [Mean Square Error](https://www.codewars.com/kata/51edd51599a189fe7f000015) | [solution.c](C/5kyu/mean_square_error/solution.c) |
| [Greed is Good](https://www.codewars.com/kata/5270d0d18625160ada0000e4) | [solution.c](C/5kyu/greed_is_good/solution.c) |

#### 6 kyu
| Kata | Solution |
|------|----------|
| [Convert String to Camel Case](https://www.codewars.com/kata/517abf86da9663f1d2000003) | [solution.c](C/6kyu/camel_case/solution.c) |
| [Credit Card Mask](https://www.codewars.com/kata/5412509bd436bd33920011bc) | [solution.c](C/6kyu/credit_card_mask/solution.c) |
| [Take a Ten Minutes Walk](https://www.codewars.com/kata/54da539698b8a2ad76000228) | [solution.c](C/6kyu/ten_minutes_walk/solution.c) |
| [Roman Numerals Decoder](https://www.codewars.com/kata/51b6249c4612257ac0000005) | [solution.c](C/6kyu/roman_numerals/solution.c) |
| [Bouncing Balls](https://www.codewars.com/kata/5544c7a5cb454edb3c000047) | [solution.c](C/6kyu/bouncing_balls/solution.c) |
| [Which Are In?](https://www.codewars.com/kata/550554fd08b86f84fe000a58) | [solution.c](C/6kyu/which_are_in/solution.c) |
| [Two Sum](https://www.codewars.com/kata/52c31f8e6605bcc646000082) | [solution.c](C/6kyu/two_sum/solution.c) |
| [Weight for Weight](https://www.codewars.com/kata/55c6126177c9441a570000e0) | [solution.c](C/6kyu/weight_for_weight/solution.c) |
| [Array.diff](https://www.codewars.com/kata/523f5d21c841566fde000009) | [solution.c](C/6kyu/array_diff/solution.c) |
| [Count Characters](https://www.codewars.com/kata/5808ff71c7cfa1c6aa00006d) | [solution.c](C/6kyu/count_characters/solution.c) |
| [Are_They_The_Same](https://www.codewars.com/kata/550498447451fbbd7600041c) | [solution.c](C/6kyu/are_they_the_same/solution.c) |
| [Your_Order_Please](https://www.codewars.com/kata/55c45be3b2079eccff00010f) | [solution.c](C/6kyu/your_order_please/solution.c) |

#### 7 kyu
| Kata | Solution |
|------|----------|
| [Binary Addition](https://www.codewars.com/kata/551f37452ff852b7bd000139) | [solution.c](C/7kyu/binary_addition/solution.c) |
| [Make the Deadfish Swim](https://www.codewars.com/kata/51e0007c1f9378fa810002a9) | [solution.c](C/7kyu/deadfish/solution.c) |

---

## 🧪 How to Run Tests Locally

Codewars uses [Criterion](https://github.com/Snaipe/Criterion) as its C testing framework.

### Install Criterion (Ubuntu/Debian)

```bash
sudo apt install libcriterion-dev
```

### File structure

```
kata_name/
├── solution.c      ← your implementation
└── test.c          ← copy the test block from Codewars
```

### Compile and run

```bash
gcc -Wall -Wextra -Werror -g solution.c test.c -lcriterion -o test && ./test
```

### Example test.c structure

```c
#include <criterion/criterion.h>

// paste the Test(...) block from Codewars here
// paste the static helper functions (dotest, tester, etc.) here

// declare your function as extern
extern void your_function(const char *input, char *output);
```

### Tips

- Copy the full test block from the **Sample Tests** tab in Codewars.
- Declare your function with `extern` in `test.c`.
- Keep `solution.c` clean — no `main`, no debug `printf`.
- Compile both files together with `-lcriterion`.

---

## 🔗 Connect

[![CodeWars](https://img.shields.io/badge/CodeWars-4trastos-B1361E?logo=codewars)](https://www.codewars.com/users/4trastos)
[![GitHub](https://img.shields.io/badge/GitHub-4trastos-181717?logo=github)](https://github.com/4trastos)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-blue?logo=linkedin&logoColor=white)](https://www.linkedin.com/in/david-gallego-gomez-9922b09a/)
