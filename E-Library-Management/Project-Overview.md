# E-Library Management System in C

A simple menu-driven E-Library Management System implemented in C to manage book records.

## Overview

This project is a console-based C program that allows users to manage books in a library. It provides options to add, display, search, borrow, return, update, and delete book records.

The project is designed to practice core C programming concepts using a practical real-world example.

## Features

- Add Book
- Display All Books
- Search Book by ID
- Borrow Book
- Return Book
- Update Book Details
- Delete Book
- Exit

## Book Information

Each book record contains:

- Book ID
- Book Title
- Author Name
- Publication Year
- Availability Status

## C Concepts Used

- Structures
- Arrays
- Loops
- Conditional Statements
- Strings
- Searching
- Record Management
- CRUD Operations

## How It Works

The program displays a menu and allows the user to select an operation.

```text
START
   ↓
Display Menu
   ↓
Choose Operation
   ↓
Add / Display / Search / Borrow / Return / Update / Delete
   ↓
Perform Operation
   ↓
Return to Menu
   ↓
Exit 
```

## E-Library Management System — Program Flowchart
 
This flowchart represents the complete logic of the C console program.
 
```mermaid
flowchart TD
    Start([START]) --> Menu[Display Main Menu]
    Menu --> Input[/Enter Choice/]
    Input --> Decision{Choice?}
 
    Decision -->|1| Add[Add Book]
    Add --> Menu
 
    Decision -->|2| Disp[Display All Books]
    Disp --> Menu
 
    Decision -->|3| SearchID[Search Book by ID]
    SearchID --> Found{Book Found?}
    Found -->|Yes| ShowDetails[Display Book Details]
    Found -->|No| NotFound["Display 'Book Not Found'"]
    ShowDetails --> Menu
    NotFound --> Menu
 
    Decision -->|4| Borrow[Borrow Book]
    Borrow --> Avail{Book Available?}
    Avail -->|Yes| MarkBorrowed[Change Status to Borrowed]
    Avail -->|No| AlreadyBorrowed["Display 'Book Already Borrowed'"]
    MarkBorrowed --> Menu
    AlreadyBorrowed --> Menu
 
    Decision -->|5| ReturnB[Return Book]
    ReturnB --> Borrowed{Book Borrowed?}
    Borrowed -->|Yes| MarkAvailable[Change Status to Available]
    Borrowed -->|No| AlreadyAvailable["Display 'Book Already Available'"]
    MarkAvailable --> Menu
    AlreadyAvailable --> Menu
 
    Decision -->|6| Update[Update Book Details]
    Update --> Menu
 
    Decision -->|7| Delete[Delete Book]
    Delete --> Menu
 
    Decision -->|8| End([EXIT])
 
    Decision -->|Invalid| InvalidMsg["Display 'Invalid Choice'"]
    InvalidMsg --> Menu
```
 
### Legend
 
| Symbol | Meaning |
|---|---|
| Oval | Start / End |
| Rectangle | Process (an action the program performs) |
| Diamond | Decision (branches based on a condition) |
| Arrow | Program flow / sequence |
 
## Author

Pooja Anbalagan

ECE Graduate
