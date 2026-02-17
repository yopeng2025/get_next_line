# get_next_line - Reading a Line From a File Descriptor

**An essential C function that reads a file line by line, managing memory efficiently through static variables and buffer manipulation.**

## 🧠 Key Learning Objectives

* **🟢 Static Variables**: Understanding how to persist data between function calls to store leftover text from the previous read.
* **🔵 File Descriptors**: Managing I/O operations and handling multiple file streams simultaneously.
* **🟡 Memory Management**: Mastering dynamic allocation and prevent leaks when joining or trimming strings.
* **🔴 Buffer Optimization**: Balancing performance by reading in chunks defined by a configurable `BUFFER_SIZE`.


## 📂 Project Breakdown

### 🟢 Part 1: Buffer Management
* **Goal**: Read data from a file descriptor into a temporary buffer.
* **Concepts**:
    * **Read Loop**: Continuously reading until a newline (`\n`) or EOF (End Of File) is encountered.
    * **Static Cache**: Appending newly read data to a static string that "remembers" its content for the next call.

### 🔵 Part 2: Line Extraction
* **Goal**: Isolate the first line found in the static cache.
* **Concepts**:
    * **Substrings**: Locating the `\n` and allocating exactly enough memory to return that single line (including the newline character).

### 🟡 Part 3: Cache Cleanup
* **Goal**: Prepare the static variable for the next function call.
* **Concepts**:
    * **Trimming**: Removing the line that was just returned from the static cache, keeping only the "leftover" characters for future reads.


## 🛠️ Usage & Compilation

### 1. compile
```c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```
### 2. execute
```c
./gnl_test test.txt
```
