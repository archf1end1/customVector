# CustomVector: A C++ Dynamic Array Implementation

---

## Overview

`CustomVector` is a templated C++ class that implements a dynamic array, similar in functionality to `std::vector`. It demonstrates core C++ concepts such as **dynamic memory management** using raw pointers, constructors (default, copy, move), destructors, copy and move assignment operators, and basic array manipulation (push, pop, access).

This project is an excellent learning resource for understanding how dynamic arrays work under the hood and the importance of the **"Rule of Five"** for proper resource management in C++.

---

## Features

* **Templated:** Can store elements of any data type (`int`, `double`, custom objects, etc.).
* **Dynamic Resizing:** Automatically doubles its capacity when new elements are added and the internal array is full.
* **Memory Management:** Proper allocation (`new[]`) and deallocation (`delete[]`) of memory to prevent leaks.
* **Copy Semantics (Deep Copy):**
    * **Copy Constructor:** Creates an independent copy of an existing `CustomVector`.
    * **Copy Assignment Operator:** Assigns the elements of one `CustomVector` to another existing `CustomVector`, ensuring a deep copy.
* **Move Semantics (Efficient Resource Transfer):**
    * **Move Constructor:** Efficiently transfers ownership of resources from an rvalue `CustomVector` to a new one, avoiding costly deep copies.
    * **Move Assignment Operator:** Transfers ownership of resources from an rvalue `CustomVector` to an existing one.
* **Basic Operations:**
    * `push_back(value)`: Adds an element to the end.
    * `pop_back()`: Removes the last element.
    * `operator[]`: Provides direct, array-like access to elements (both mutable and constant versions).
    * `getSize()`: Returns the current number of elements.
    * `clear()`: Empties the vector (resets size to 0).
    * `empty()`: Checks if the vector is empty.

---

## Getting Started

### Prerequisites

You'll need a C++ compiler that supports C++11 or later (e.g., g++, clang++).

### Building and Running

1.  **Save the code:** Save the provided C++ code into a file named `custom_vector.cpp`.

2.  **Compile:** Open your terminal or command prompt and compile the code using a C++ compiler.

    ```bash
    g++ custom_vector.cpp -o custom_vector -std=c++11
    # Or for a newer standard like C++17
    # g++ custom_vector.cpp -o custom_vector -std=c++17
    ```

3.  **Run:** Execute the compiled program.

    ```bash
    ./custom_vector
    ```

### Expected Output

The `main` function includes various tests that demonstrate the `CustomVector`'s functionality, including `push_back`, `pop_back`, and the correct behavior of copy and move operations. You should see output similar to this: