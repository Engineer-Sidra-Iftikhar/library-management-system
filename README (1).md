# Library Management System (C++ | OOP Project)

A console-based **Library Management System** built in C++ to demonstrate core Object-Oriented Programming concepts: **inheritance, composition, aggregation, and polymorphism**.

> Submitted By: Sidra Iftikhar, Iraj Taimur Malik, Sehrish Fatima
> Submitted To: Dr. Sobia Khalid
> Course: Object Oriented Programming

## Overview

This project simulates how a library manages its books and members (students and faculty). Users must log in before accessing the system, after which they can add, search, update, and list books, as well as register student and faculty details.

## Class Design

| Class | Responsibility |
|---|---|
| `verification` | Handles user authentication via email/password check |
| `book` | Represents a single book (id, title, author, quantity) |
| `library` | Manages a collection of `book` objects — add, display, search, update |
| `member` | Base class for a library member (name, age, id) |
| `student` | Inherits from `member`; adds program & email; can issue books |
| `faculty` | Inherits from `member`; adds department & email; can issue books |

### OOP Relationships

- **Inheritance ("is-a")** — `student` and `faculty` inherit common attributes/behaviour from `member`.
- **Composition ("part-of")** — `library` owns an array of `book` objects; books are destroyed when the library object is destroyed.
- **Aggregation ("uses-a")** — `student` and `faculty` each hold a `library` object to search for books, but don't own its lifetime.
- **Polymorphism** — `display()` and `input_data()` are virtual in `member` and overridden in `student`/`faculty`.

## Features

- User authentication before granting access
- Add, display, search, and update books
- Register student and faculty member details
- Simple menu-driven console interface

## Project Structure

```
library-management-system/
├── main.cpp              # Full source code
├── sample_input.txt       # Example input used to demo the program
├── sample_output.txt       # Captured output from a sample run
├── docs/
│   └── PROJECT_REPORT.docx # Original submitted project report
└── README.md
```

## Build & Run

Requires a C++ compiler (g++ recommended).

```bash
g++ -std=c++17 -O2 -o library main.cpp
./library
```

### Demo login credentials

| Email | Password |
|---|---|
| sidrarajput@gmail.com | sidra2005 |
| irajtaimur@gmail.com | iraj2006 |
| sehrish123@gmail.com | sehrish2005 |
| sobiakhalid@gmail.com | sobia123 |

> ⚠️ These are demo credentials hardcoded for the project assignment, not real production secrets.

### Try it with the sample input

```bash
./library < sample_input.txt
```

This will log in, add a book, list books, register a student, search/issue the book, update it, and exit — matching `sample_output.txt`.

## Sample Output

```
Enter your Email to Login : Enter your Password to Login : Welcome, You are Member of this Library
	Library Management System	
1.Add Books to Library
2.Books List of Library
3.Enter Student Detail
4.Enter Faculty Detail
5.Search for book you want to Issue 
6.Update Books 
7.Program end 

Enter your choice: Enter ID of book: Enter title of book: Enter name of author: Enter quantity: 
Books added successfully 
---------------------------------------------
	Library Management System	
1.Add Books to Library
2.Books List of Library
3.Enter Student Detail
4.Enter Faculty Detail
5.Search for book you want to Issue 
6.Update Books 
7.Program end 

Enter your choice: 
--------------Book List-------------
ID of book	Name of book	Author of book		Quantity
101		CppPrimer		 StanleyLippman 		5
---------------------------------------------
...
```

Full output is available in [`sample_output.txt`](sample_output.txt).

## Menu Options

1. Add Books to Library
2. Books List of Library
3. Enter Student Detail
4. Enter Faculty Detail
5. Search for book you want to Issue
6. Update Books
7. Program end

## Notes

- The original report's `main()` declared two `library*` pointers (`p`, `p1`) without initializing them before use. This repo's `main.cpp` fixes that by pointing them at the active `library` object, so the program builds and runs cleanly with a standard compiler (the report used Visual Studio-specific headers like `stdafx.h` and `_tmain`, which were also replaced with standard `main()` for portability).
- The original Word report is kept in `docs/PROJECT_REPORT.docx` for reference.

## License

This project was created for academic purposes as part of an Object-Oriented Programming course assignment.
