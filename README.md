# DSA-C++

A clean, topic-based repository for Data Structures and Algorithms practice in C++, with a small Python Titanic EDA side project.

## Repository Layout

```text
.
├── src/
│   ├── cpp/
│   │   ├── arrays/
│   │   ├── binary_search/
│   │   ├── fundamentals/
│   │   ├── hashing/
│   │   ├── math/
│   │   ├── patterns/
│   │   ├── recursion/
│   │   └── sorting/
│   └── contests/
│       └── leetcode/
├── projects/
│   └── titanic-eda/
│       ├── generate_report.py
│       └── outputs/
├── data/
│   └── samples/
├── build/                # local binaries/debug files, ignored by Git
└── .github/
```

## Topics Covered

- Arrays
- Binary Search
- C++ Basics and STL
- Hashing
- Math for DSA
- Patterns
- Recursion
- Sorting
- LeetCode Contest Solutions

## Quick Start

Compile and run any C++ file:

```bash
mkdir -p build/local
g++ -std=c++17 -Wall -Wextra src/cpp/arrays/arrays4.cpp -o build/local/arrays4
./build/local/arrays4
```

## Notes

- `build/` is for local macOS binaries and debug symbols only.
- `projects/titanic-eda/outputs/` stores generated charts and CSV summaries.
- Keep new solutions grouped by topic under `src/cpp/`.
