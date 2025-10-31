# Library_Management_System
# Overview
This is a simple Library Management System written in C++, designed for managing books in a library using a local text file (books.txt) for data storage.
It allows users (students) to list, borrow, return, and add books(extra added) through a console interface.

--Display all available and borrowed books
-- Borrow a book by its ID
-- Return a borrowed book
-- Add new books to the catalog
-- Automatically saves data to books.txt
-- Simple text-based interface for easy use

# File Structure
LibraryManagementSystem
 ┣  main.cpp          # Main source code
 ┣  books.txt         # Book database (created automatically)
 ┗  README.md         # Project documentation

 # How it works?
 --All book records are stored in books.txt in the following format:ID,Title,Author,Status
 --Where Status = 0 means available and 1 means borrowed.
 --When you run the program, it automatically loads books from books.txt.
 --All changes (borrow, return, add) are automatically saved back to the file.

 Example Usage
 Please enter your student id: 123
--------Library Menu--------
1. List All Books
2. Borrow a Book
3. Return a Book
4. Add New Book
5. Save and Exit
Enter your selection between 1-5:

Example books.txt
1,The Great Gatsby,F. Scott Fitzgerald,0
2,To Kill a Mockingbird,Harper Lee,1
3,1984,George Orwell,0

# Technologies Used
C++
File I/O (fstream)
Object-Oriented Programming
