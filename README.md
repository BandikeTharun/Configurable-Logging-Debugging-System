# Design and Implementation of a Configurable Logging and Debugging System Using C Preprocessor Directives

## Mini Project

**Project ID:** 35703
**Project Type:** Mini Project
**Domain:** C Programming / C Preprocessor
**Assigned Date:** 03 August 2026
**Deadline:** 17 August 2026

---

## 1. Project Overview

This project demonstrates the basic working of a C preprocessor by implementing a custom preprocessor named `my_Preprocessor`.

The program accepts a C source file as input and generates a preprocessed `.i` file.

The implementation demonstrates important preprocessing concepts such as:

* Comment removal
* Header/include expansion
* Simple `#define` macro expansion
* Generation of an intermediate `.i` file
* Modular C programming
* Makefile-based compilation

The project also provides a foundation for configurable logging and debugging using C preprocessor directives.

---

## 2. Objectives

The main objectives of this project are:

1. To understand the purpose of the C preprocessor.
2. To understand how preprocessing takes place before compilation.
3. To implement comment removal.
4. To implement simple header-file inclusion.
5. To implement simple object-like macro substitution.
6. To generate a `.i` preprocessed source file.
7. To organize the implementation into multiple C modules.
8. To understand how preprocessor directives can be used for configurable debugging and logging.

---

## 3. System Workflow

```text
             C Source File
                   |
                   v
          +------------------+
          | Comment Removal  |
          +------------------+
                   |
                   v
          +------------------+
          | Include Expansion|
          +------------------+
                   |
                   v
          +------------------+
          | Macro Expansion  |
          +------------------+
                   |
                   v
          +------------------+
          |   .i Output File |
          +------------------+
```

---

## 4. Project Modules

### Module 1: Comment Removal

**Files:**

* `comment.c`
* `comment.h`

This module removes:

```c
// Single-line comments
```

and:

```c
/*
   Multi-line comments
*/
```

from the input source file.

---

### Module 2: Include Expansion

**Files:**

* `include.c`
* `include.h`

This module handles simple include directives such as:

```c
#include <stdio.h>
```

and:

```c
#include "header.h"
```

The contents of an available header file are inserted into the intermediate output.

---

### Module 3: Macro Expansion

**Files:**

* `macro.c`
* `macro.h`

This module identifies simple object-like macros defined using `#define`.

Example:

```c
#define VALUE 100

int x = VALUE;
```

After preprocessing:

```c
int x = 100;
```

---

### Module 4: Main Controller

**File:**

* `main.c`

The main program controls the complete preprocessing sequence.

It:

1. Accepts the source file name through the command line.
2. Creates temporary files.
3. Calls the comment-removal module.
4. Calls the include-expansion module.
5. Calls the macro-expansion module.
6. Generates the final `.i` file.
7. Removes temporary files.

---

## 5. Technologies Used

* C Programming Language
* C Preprocessor Concepts
* File Handling
* String Processing
* Dynamic/Modular Program Design
* GCC Compiler
* GNU Make
* Ubuntu Linux
* Git
* GitHub

---

## 6. Project Structure

```text
Configurable-Logging-Debugging-System/
│
├── main.c
├── common.h
│
├── comment.c
├── comment.h
│
├── include.c
├── include.h
│
├── macro.c
├── macro.h
│
├── Makefile
├── abc.c
├── .gitignore
├── README.md
│
└── screenshots/
    └── preprocessor_execution.jpg
```

---

## 7. Requirements

The project requires:

* Ubuntu/Linux system
* GCC compiler
* GNU Make
* Git

Check GCC:

```bash
gcc --version
```

Check Make:

```bash
make --version
```

Check Git:

```bash
git --version
```

---

## 8. Compilation

Navigate to the project directory:

```bash
cd ~/c_project
```

Compile the project using:

```bash
make
```

This generates the executable:

```text
my_Preprocessor
```

---

## 9. Execution

Use the following command:

```bash
./my_Preprocessor abc.c
```

Expected output:

```text
Preprocessing completed successfully.
Input  : abc.c
Output : abc.i
```

The generated preprocessed file can be viewed using:

```bash
cat abc.i
```

### Execution Demonstration

The following screenshot shows the execution of the custom preprocessor, generation of the `.i` file, and the resulting preprocessed output.

![Preprocessor Execution](./screenshots/preprocessor_execution.jpg)

---

## 10. Sample Input

Example `abc.c`:

```c
#include <stdio.h>

#define VALUE 100
#define OTHER 200

// Single-line comment

int x = VALUE;

/*
   Multi-line comment
*/

int y = OTHER;

int main()
{
    int k = 3456;
    printf("%d %d\n", k, 65);
    return 0;
}
```

---

## 11. Sample Output

After running:

```bash
./my_Preprocessor abc.c
```

the generated `abc.i` contains the processed source.

The comments are removed and the simple macros are substituted.

For example:

```c
int x = 100;
int y = 200;

int main()
{
    int k = 3456;
    printf("%d %d\n", k, 65);
    return 0;
}
```

---

## 12. Makefile

The project uses a Makefile to simplify compilation.

Build:

```bash
make
```

Clean generated build files:

```bash
make clean
```

The Makefile compiles:

```text
main.c
comment.c
include.c
macro.c
```

and links them to create:

```text
my_Preprocessor
```

---

## 13. Testing

### Test 1: Macro Expansion

Input:

```c
#define A 10
int x = A;
```

Expected:

```c
int x = 10;
```

### Test 2: Single-Line Comment

Input:

```c
int x = 10; // comment
```

Expected:

```c
int x = 10;
```

### Test 3: Multi-Line Comment

Input:

```c
/*
   comment
*/
int x = 10;
```

Expected:

```c
int x = 10;
```

### Test 4: Normal C Code

Input:

```c
int k = 3456;
printf("%d", k);
```

The normal source statements should remain unchanged.

---

## 14. Configurable Logging and Debugging Concept

C preprocessor directives can be used to make debugging configurable.

For example:

```c
#ifdef DEBUG
#define LOG(msg) printf("[DEBUG] %s\n", msg)
#else
#define LOG(msg)
#endif
```

When `DEBUG` is enabled, debugging messages can be included.

When `DEBUG` is disabled, the logging macro can expand to nothing.

This concept can be extended in future versions of the project to provide different logging levels such as:

```text
DEBUG
INFO
WARNING
ERROR
```

---

## 15. Limitations

This is an educational implementation of selected C preprocessing features and is not intended to completely replace the standard C preprocessor.

The current implementation does not fully support:

* Function-like macros
* Macro recursion
* Conditional compilation such as `#if`, `#ifdef`, and `#ifndef`
* Complete C tokenization rules
* Full system-header search-path handling
* Complete C standard preprocessing semantics

---

## 16. Future Enhancements

The project can be extended with:

1. Configurable `DEBUG` mode.
2. `INFO`, `WARNING`, and `ERROR` logging levels.
3. Command-line options such as `-DDEBUG`.
4. Function-like macro support.
5. Conditional compilation.
6. Better header search-path handling.
7. Line-number preservation.
8. Improved error handling.
9. Detailed preprocessing reports.

---

## 17. Result

The project successfully demonstrates a custom preprocessing workflow in C.

The implemented system:

* Accepts a C source file.
* Removes comments.
* Processes simple include directives.
* Expands simple macros.
* Generates a `.i` preprocessed output file.

---

## 18. Conclusion

The project provides practical understanding of how C preprocessing works before the compilation stage.

By implementing the preprocessing operations as separate modules, the project demonstrates modular programming, file handling, string processing, macro substitution, and build automation using Makefile.

The implementation also provides a foundation for developing configurable logging and debugging mechanisms using C preprocessor directives.

---

## 19. Author

**Bandike Tharun**

**Project ID:** 35703
