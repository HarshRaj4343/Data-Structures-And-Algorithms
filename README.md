# DSA-C++

A clean, topic-based repository for Data Structures and Algorithms practice in C++.
97 solution files organised by topic, plus LeetCode contest submissions.

## Repository Layout

```text
.
├── src/
│   ├── cpp/
│   │   ├── fundamentals/        # C++ basics, STL
│   │   ├── math/                # math for DSA
│   │   ├── patterns/            # star/number pattern printing
│   │   │   ├── pattern_solutions/
│   │   │   └── pattern_full_solns/
│   │   ├── recursion/
│   │   ├── hashing/
│   │   ├── sorting/
│   │   │   └── sorting_methods_new/   # bubble, selection, insertion, merge, quick
│   │   ├── arrays/
│   │   │   ├── array_basix/     # easy: search, rotate, dedup, missing number
│   │   │   └── array_medium/    # kadane, spiral, matrix ops, next permutation
│   │   ├── binary_search/
│   │   │   ├── bs_basix/        # bounds, occurrences, rotated arrays, 2-D
│   │   │   └── bs_answers/      # binary search on answer space
│   │   ├── strings/
│   │   │   └── strings_basix/
│   │   └── LinkedLists/
│   │       ├── SinglyLinked/
│   │       └── DoublyLinked/
│   └── contests/
│       └── leetcode/            # weekly contest solutions
├── data/
│   └── samples/                 # sample input/output for testing
└── .github/
```

## Topics Covered

| Topic | Location | Notes |
|---|---|---|
| C++ Basics & STL | `src/cpp/fundamentals/` | language refreshers |
| Math for DSA | `src/cpp/math/` | digits, GCD, primes |
| Patterns | `src/cpp/patterns/` | 19 pattern problems |
| Recursion | `src/cpp/recursion/` | |
| Hashing | `src/cpp/hashing/` | frequency counting |
| Sorting | `src/cpp/sorting/` | all five classic sorts |
| Arrays | `src/cpp/arrays/` | split into basic and medium |
| Binary Search | `src/cpp/binary_search/` | on arrays and on answers |
| Strings | `src/cpp/strings/` | |
| Linked Lists | `src/cpp/LinkedLists/` | singly and doubly |
| LeetCode Contests | `src/contests/leetcode/` | |

## Quick Start

Each file is a standalone program with its own `main()`. Compile and run any one of them:

```bash
mkdir -p build/local
g++ -std=c++17 -Wall -Wextra src/cpp/arrays/array_basix/2sum.cpp -o build/local/2sum
./build/local/2sum
```

To feed a solution the sample input:

```bash
./build/local/2sum < data/samples/input.txt
```

## Conventions

- One problem per file, named descriptively in `lower_snake_case`.
- New solutions go under the matching topic folder in `src/cpp/`.
- **Never commit compiled binaries.** `.gitignore` excludes every extensionless
  file under `src/`, so a stray `g++ -o src/cpp/.../foo` output stays untracked.
  Prefer compiling into `build/`, which is ignored entirely.
- If you add a topic, update this README (see `CONTRIBUTING.md`).

## License

See [LICENSE](LICENSE).
