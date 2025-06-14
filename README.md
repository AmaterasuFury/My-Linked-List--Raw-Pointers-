# 🔗 Custom Linked List in C++

This project is a custom implementation of a singly linked list data structure written in C++. It was built from scratch without relying on the STL containers to demonstrate a fundamental understanding of dynamic memory management, pointer manipulation, and object-oriented design.

---

## 📚 Features

The list includes all the standard operations expected from a basic singly linked list:

### ✅ Core Functionality

- `Add(int InValue)`: Appends a value to the end of the list
- `PushFront(int InValue)`: Adds a value at the beginning of the list
- `PushBack(int InValue)`: Adds a value to the end of the list (similar to `Add`)
- `AddElementOnIndex(int InValue, int InIndex)`: Inserts a value at a specific index
- `RemoveFirstElement()`: Removes the first node
- `RemoveLastElement()`: Removes the last node
- `RemoveOnIndex(int InIndex)`: Deletes a node at a given index
- `RemoveByValue(int InValue)`: Removes the first occurrence of a value
- `FindOnIndex(int InIndex)`: Returns the value at a specific index
- `GetIndexByValue(int InValue)`: Finds the index of a given value
- `Contains(int InValue)`: Checks if a value exists in the list
- `Clear()`: Empties the entire list
- `GetSizeOfList()`: Returns the number of elements in the list

---

## 💾 Serialization Support

A key feature of this project is **file-based serialization and deserialization**, enabling you to persist the list to disk and load it back:

- `SerializeToFile(const std::string InFileName, bool ClearListAfter)`: Writes the list to a file and optionally clears the list
- `DeserealizeFromFile(const std::string InFileName)`: Loads list data from a file and reconstructs it

This functionality demonstrates basic file I/O, stream handling, and error checking in C++.

---

## ⚙️ Technical Overview

- Written in **pure C++** with no external libraries
- Manual memory management (with destructor handling cleanup)
- Fully pointer-based, dynamically allocated nodes
- No use of STL containers — all logic is hand-crafted

---

## 📌 Notes for Reviewers / Recruiters

- Check `SerializeToFile()` and `DeserealizeFromFile()` for custom file I/O handling.
- The `~MyList()` destructor cleans up all dynamically allocated memory.
- See `AddElementOnIndex()` for index-based insertions and edge case handling.
- All error conditions are reported via `std::cout` or `std::cerr`, which can be replaced with a logging system.

---

## 🚀 Getting Started

1. Clone the repository.
2. Include `MyList.h` and `MyList.cpp` in your C++ project.
3. Create an instance of `MyList`, and use it in your code:

```cpp
MyList list;
list.Add(10);
list.Add(20);
list.SerializeToFile("data.txt", false);
