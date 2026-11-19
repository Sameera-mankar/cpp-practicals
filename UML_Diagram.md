# UML Class Diagram – Library Management System

```mermaid
classDiagram
    class LibraryItem {
        <<abstract>>
        +display()*
    }

    class Book {
        -int id
        -string title
        -string author
        -bool available
        +getId() int
        +issue() void
        +returnBook() void
        +display() void
        +save() void
    }

    class Library {
        -vector~Book~ books
        +searchBook(int id) Book*
        +addBook(int id, string title, string author) void
        +displayBooks() void
        +issueBook(int id) void
        +returnBook(int id) void
        +saveToFile() void
        +loadFromFile() void
    }

    LibraryItem <|-- Book
    Library o-- Book
```

## Class Description

1. **LibraryItem:** Abstract base class containing the virtual display function.
2. **Book:** Derived class that stores book details and manages issue and return operations.
3. **Library:** Manages book records using a vector and provides search, display and file-handling operations.

## Relationships

- Book inherits from LibraryItem.
- Library manages multiple Book objects.
