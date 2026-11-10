# Online Examination Result Analyzer

A console-based student examination result management system built using **C programming**.

This project allows users to enter student details, calculate examination results, rank students based on their marks, search for individual student records, and analyze overall class performance.

## Features

- **Student Data Entry:** Enter student names, unique roll numbers, and marks in five subjects.
- **Input Validation:** Prevent duplicate or non-positive roll numbers and marks outside the 0–100 range.
- **Result Calculation:** Automatically calculate total marks and percentages.
- **Grade Calculation:** Assign grades based on student percentages.
- **Student Ranking:** Arrange students in descending order of total marks using Bubble Sort.
- **Search Student:** Find a student's result using their roll number.
- **Class Analysis:** Display class average, pass/fail counts, highest scorer, and lowest scorer.
- **Menu-Driven Interface:** Easily navigate between different operations.

## Modules

- **Result Data Entry Module**
- **Result Calculation Module**
- **Search Module**
- **Analysis and Ranking Module**

## Subjects

The program currently supports five subjects:

1. Maths
2. Physics
3. Chemistry
4. English
5. Computer

Each subject carries a maximum of 100 marks.

## DSA Concepts Used

This project demonstrates the following programming and DSA concepts:

- One-dimensional arrays
- Two-dimensional arrays
- Functions
- Loops and conditional statements
- Linear Search
- Bubble Sort
- Array manipulation and swapping
- Basic input validation

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC (or another compatible C compiler)
- **Editor:** Visual Studio Code

## How to Run

**1. Clone the repository**

```bash
git clone https://github.com/Aayush264/Online-Examination-Result-Analyzer.git
```

**2. Open the project folder**

```bash
cd Online-Examination-Result-Analyzer
```

**3. Compile the program**

```bash
gcc Online_Examination_Result_Analyzer.c -o exam_analyzer
```

**4. Run the program**

On Windows:

```bash
.\exam_analyzer.exe
```

On Linux/macOS:

```bash
./exam_analyzer
```

## How It Works

1. Enter the details of each student.
2. Enter marks for all five subjects.
3. The program calculates total marks and percentages.
4. Bubble Sort arranges students according to their total marks.
5. Use the main menu to view results, search for students, or analyze class performance.

## Project Structure

```text
Online-Examination-Result-Analyzer/
│
├── Online_Examination_Result_Analyzer.c
└── README.md
```

## Future Improvements

- Support for multiple-word student names.
- Improved handling of invalid and non-numeric inputs.
- Ranking with shared positions for students having equal marks.
- Saving student records permanently using file handling.


---

*Built as a C programming and Data Structures & Algorithms project.*