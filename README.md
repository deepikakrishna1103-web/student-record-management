# Student Record Management System

A complete, menu-driven **Student Record Management System** written in **C**, using a **singly linked list** for storage, **dynamic memory allocation** for nodes, and **file handling** for persistence.

The project is modular (one function per source file), well-commented, and demonstrates the core concepts of linked lists, pointers, and file I/O.

Built as a Mini Project – II assignment.

---

## Table of Contents

- [What This Project Does](#what-this-project-does)
- [Concepts Demonstrated](#concepts-demonstrated)
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Build](#build)
- [Run](#run)
- [First-Time Usage Walkthrough](#first-time-usage-walkthrough)
- [Menu Options](#menu-options)
- [Detailed Menu Explanation](#detailed-menu-explanation)
- [Data File Format](#data-file-format)
- [Memory Management](#memory-management)
- [Modules Overview](#modules-overview)
- [Function Reference](#function-reference)
- [Input Validation Rules](#input-validation-rules)
- [Error Handling](#error-handling)
- [Testing Checklist](#testing-checklist)
- [Troubleshooting](#troubleshooting)
- [Author](#author)

---

## What This Project Does

This program lets you manage a simple list of student records from a text-menu interface. You can:

- **Add** students (each gets a unique, auto-assigned roll number)
- **Delete** students by roll number or by name
- **Show** all students in a neatly formatted table
- **Modify** a student's name or percentage
- **Sort** the list by name or by percentage
- **Reverse** the entire list
- **Save** the list to a file so it survives between runs
- **Delete all** students (from memory only)

Everything is stored in a **singly linked list** built with `malloc`. When the program exits, every node is `free`d — no memory leaks.

---

## Concepts Demonstrated

| Concept | Where It's Used |
|---|---|
| Structures (`struct`) | `struct student` in `student.h` |
| Pointers (single & double) | Every list operation |
| Singly linked list | All records management |
| Dynamic memory (`malloc`, `free`) | Adding / deleting nodes |
| File I/O (`fopen`, `fprintf`, `fscanf`) | `stud_save.c`, `stud_load.c` |
| Modular programming | One function per `.c` file |
| Input validation | Percentage range, name non-empty |
| Searching | By rollno / name / percentage |
| Sorting | Bubble sort on list data |
| Reversal | Classic 3-pointer link reversal |

---

## Features

- Menu-driven interface that loops until the user selects **Exit**
- Student records stored in a **singly linked list**
- Each node **dynamically allocated** with `malloc`
- Automatic assignment of the **smallest unused positive roll number**
- **Search** by roll number, name, or percentage
- **Sort** the list by name (alphabetical) or percentage (descending)
- **Reverse** the linked list using pointer manipulation only
- **File handling** with `student.dat` (save / auto-load at startup)
- **Input validation** for percentage, empty names, and invalid choices
- **Proper memory management** — every node is freed before exit
- **Modular** source — one function per file, shared header

---

## Project Structure

```
student-record-management/
├── student.h          # Structure definition, prototypes
├── main.c             # Main menu and program flow
├── stud_add.c         # Add a new student record
├── stud_del.c         # Delete a record (by rollno or name)
├── stud_show.c        # Display the complete list
├── stud_mod.c         # Modify an existing record
├── stud_save.c        # Save records to student.dat
├── stud_load.c        # Load records from student.dat
├── stud_sort.c        # Sort by name or percentage
├── stud_reverse.c     # Reverse the linked list
├── delete_all.c       # Free all nodes from memory
├── stud_exit.c        # Save & exit / exit without saving
├── Makefile           # Build automation
├── .gitignore         # Ignored files
└── README.md          # This file
```

### Why so many files?

Splitting the project this way mirrors **real-world C projects**: each file handles one clear responsibility. If you need to change how sorting works, you only touch `stud_sort.c`. If the file format changes, you only touch `stud_save.c` and `stud_load.c`.

---

## Requirements

| Requirement | Version / Notes |
|---|---|
| C compiler | GCC, Clang, or MinGW |
| Make | GNU Make (for the provided Makefile) |
| OS | Linux, macOS, WSL, or MinGW on Windows |
| Standard | C99 or later |

---

## Build

### Using the Makefile (recommended)

```bash
make
```

This compiles every `.c` file, links them, and produces an executable named **`student`**.

### Or manually

```bash
gcc -Wall -Wextra -std=c99 *.c -o student
```

### Cleaning up

```bash
make clean       # Removes .o files and the student binary
make distclean   # Also removes student.dat
```

---

## Run

```bash
./student
```

On startup, the program looks for the saved file `student.dat`. If the file exists, its records are loaded into the linked list. Otherwise, the program starts with an empty list.

---

## First-Time Usage Walkthrough

Here's a complete example of a fresh session:

**Step 1 — Start the program**

```bash
$ ./student
No saved file found. Starting with an empty list.

******** STUDENT RECORD MENU ********
a/A : Add new record
d/D : Delete a record
s/S : Show the list
m/M : Modify a record
v/V : Save records
e/E : Exit
t/T : Sort the list
l/L : Delete all the records
r/R : Reverse the list
*************************************
Enter your choice:
```

**Step 2 — Add a student (`a`)**

```
Enter your choice: a
Enter student name: Rahul
Enter percentage (0.00 - 100.00): 78.5
Record added successfully. Roll No = 1
```

**Step 3 — Add another (`a`)**

```
Enter your choice: a
Enter student name: Priya
Enter percentage (0.00 - 100.00): 85.25
Record added successfully. Roll No = 2
```

**Step 4 — Show the list (`s`)**

```
Enter your choice: s

******** STUDENT LIST ********
Roll No.   Name                 Percentage
---------------------------------------------
1          Rahul                78.50
2          Priya                85.25
******************************
```

**Step 5 — Save (`v`)**

```
Enter your choice: v
Student records saved successfully
```

**Step 6 — Exit (`e` → `s`)**

```
Enter your choice: e

S/s : Save and exit
E/e : Exit without saving
Enter your choice: s
Student records saved successfully
Exiting...
```

Next time you run `./student`, both records will be automatically loaded.

---

## Menu Options

| Option | Description |
|:------:|-------------|
| `a / A` | Add a new student record (roll number is auto-assigned) |
| `d / D` | Delete a record by **roll number** or by **name** |
| `s / S` | Display the complete student list in a tabular format |
| `m / M` | Modify a record by **roll number**, **name**, or **percentage** |
| `v / V` | Save the current list to `student.dat` |
| `e / E` | Save & exit, or exit without saving |
| `t / T` | Sort the list by **name** (A→Z) or **percentage** (descending) |
| `l / L` | Delete all records from memory (does **not** delete `student.dat`) |
| `r / R` | Reverse the linked list in place |

---

## Detailed Menu Explanation

### `a / A` — Add a new record

- You enter a **name** and a **percentage**.
- The program finds the **smallest positive integer not already used** as a roll number.
- Example: if roll numbers `1, 2, 4, 5` exist, the next roll number is `3`.
- The node is dynamically allocated with `malloc` and appended to the list.

### `d / D` — Delete a record

Two sub-options:

- **By roll number (`R/r`)** — you type a roll number; the matching record is unlinked and freed.
- **By name (`N/n`)** — all matching names are shown with their roll numbers. You then pick one to delete.

### `s / S` — Show the list

Prints every record in a three-column table: roll number, name, percentage.

### `m / M` — Modify a record

Three sub-options:

- **By roll number (`R/r`)**
- **By name (`N/n`)** — if multiple records share a name, all are listed, and you pick one by roll number.
- **By percentage (`P/p`)** — same behaviour.

You can update the **name** and **percentage**, but the **roll number stays the same**.

### `v / V` — Save records

Writes the entire linked list to `student.dat`. Overwrites the file if it exists.

### `e / E` — Exit

Shows a sub-menu:

- **`S/s` — Save and exit** — saves first, then exits.
- **`E/e` — Exit without saving** — exits without touching the file.

In both cases, all memory is freed before the process terminates.

### `t / T` — Sort the list

- **By name (`N/n`)** — alphabetical, A → Z
- **By percentage (`P/p`)** — descending (highest first)

### `l / L` — Delete all records

Frees **every node** and sets the head to `NULL`. Does **not** touch `student.dat`.

### `r / R` — Reverse the list

Reverses the linked list by changing pointers — no new nodes are created.

---

## Data File Format

Records are stored in **`student.dat`** as plain text, one record per line:

```
<rollno> <name> <percentage>
```

Example:

```
1 Rahul 78.50
2 Priya 85.25
4 Arjun 91.00
```

The file is written only when the user explicitly saves:

- Selecting `v / V` from the main menu, or
- Selecting `e / E → S / s` (save & exit)

The file is **not** modified by:

- Deleting all records from memory (`l / L`)
- Exiting without saving (`e / E → E / e`)

---

## Memory Management

| Rule | Implementation |
|---|---|
| Allocate nodes dynamically | `malloc` in `stud_add` and `stud_load` |
| Check allocation failure | `if (new == 0)` guard in both functions |
| Free deleted nodes | `free` in `stud_del` and `delete_all` |
| Release remaining nodes before exit | `delete_all` called from `stud_exit` on both paths |
| Avoid dangling pointers | Head updated before free; pointers advanced after |

The program is designed so that **no memory leak** occurs in any normal execution path — including early exits, save-and-exit, and exit-without-saving.

---

## Modules Overview

| Module | Responsibility |
|---|---|
| `main.c` | Menu display and dispatch loop |
| `stud_add.c` | Create new node, assign smallest unused rollno, insert into list |
| `stud_del.c` | Delete by rollno or by name (with multi-match listing) |
| `stud_show.c` | Print the list in tabular form; message if empty |
| `stud_mod.c` | Modify by rollno, name, or percentage |
| `stud_save.c` | Serialise list into `student.dat` |
| `stud_load.c` | Read `student.dat` at startup and rebuild the list |
| `stud_sort.c` | Sort by name (ascending) or percentage (descending) |
| `stud_reverse.c` | Reverse links of the list in place |
| `delete_all.c` | Free every node and set head to `NULL` |
| `stud_exit.c` | Sub-menu for save & exit / exit without saving |

---

## Function Reference

| Function | File | Signature |
|---|---|---|
| `stud_add` | `stud_add.c` | `void stud_add(SLL **ptr);` |
| `stud_del` | `stud_del.c` | `void stud_del(SLL **ptr);` |
| `stud_show` | `stud_show.c` | `void stud_show(SLL *ptr);` |
| `stud_mod` | `stud_mod.c` | `void stud_mod(SLL *ptr);` |
| `stud_save` | `stud_save.c` | `void stud_save(SLL *ptr);` |
| `stud_load` | `stud_load.c` | `void stud_load(SLL **ptr);` |
| `stud_sort` | `stud_sort.c` | `void stud_sort(SLL **ptr);` |
| `stud_reverse` | `stud_reverse.c` | `void stud_reverse(SLL **ptr);` |
| `delete_all` | `delete_all.c` | `void delete_all(SLL **ptr);` |
| `stud_exit` | `stud_exit.c` | `void stud_exit(SLL **ptr);` |

### Why some functions take `SLL **` and others `SLL *`

- Functions that can **change the head pointer** (add, delete, sort, reverse, delete_all, load) receive `SLL **` so they can modify the caller's head variable.
- Functions that only **read or edit existing nodes** (show, modify, save) receive `SLL *` — the head itself doesn't change.

This is a common C pattern for linked-list APIs.

---

## Input Validation Rules

The program enforces the following validations:

| Field | Rule |
|---|---|
| Roll number | Positive integer, auto-assigned, unique |
| Name | Must not be empty |
| Percentage | Must be in range `0.00` – `100.00` |
| Menu choice | Must be one of the listed letters; invalid choices are rejected without exiting |
| Delete / Modify on missing record | Friendly "not found" message; no crash |

If an invalid value is entered, the user is prompted again until a valid value is provided.

---

## Error Handling

| Situation | Behaviour |
|---|---|
| `malloc` fails | Prints "Memory allocation failed" and aborts the operation |
| `fopen` for save fails | Prints an error, no data loss |
| `student.dat` missing at startup | Silently starts with an empty list |
| `student.dat` corrupt mid-file | Loading stops at first malformed line; earlier records are kept |
| Invalid menu letter | Prints "Invalid choice" and re-displays the menu |
| Delete / Modify on missing rollno or name | Prints "not found"; no crash |

---

## Testing Checklist

Use this list to verify the program after building it:

- [ ] Add three students — the roll numbers should be `1, 2, 3`
- [ ] Delete roll number `2` — show list should now have `1, 3`
- [ ] Add another student — roll number should be `2` (smallest unused)
- [ ] Add two students with the same name — delete by that name, and both should be listed
- [ ] Modify a record's name and percentage; the roll number must stay the same
- [ ] Sort by name (A→Z) and confirm order
- [ ] Sort by percentage and confirm descending order
- [ ] Reverse the list; confirm order flips
- [ ] Save, exit, and rerun — records must reload from `student.dat`
- [ ] Delete all (`l/L`) and verify `student.dat` is untouched on disk
- [ ] Exit without saving (`e/E → E/e`) and confirm no changes were written

---

## Troubleshooting

| Problem | Possible Cause | Fix |
|---|---|---|
| `make: command not found` | GNU Make not installed | Install `make`, or build with `gcc *.c -o student` |
| `missing separator` in Makefile | Tabs were converted to spaces | Re-indent recipe lines with real tabs |
| Compilation error about `SLL` | `student.h` not found or not included | Ensure `#include "student.h"` in every `.c` |
| Executable runs but no records load | `student.dat` missing or empty | Add some records and save with `v/V` |
| Program loops forever with "Invalid choice" | Non-letter input | Type a single letter from the menu |
| Blank output after adding | Was `s/S` selected? | Press `s` to show the list |

---

## Author

**Boppana Deepika**
Mini Project – II — C Programming