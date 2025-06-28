# 📘 Readability

This project analyzes a block of English text and estimates the U.S. school grade level needed to understand it, based on the **Coleman-Liau index**. It was developed as part of the [CS50x](https://cs50.harvard.edu/x/) course by Harvard.

---

## 📌 Problem Statement

The program calculates a readability score using this formula:

index = 0.0588 * L - 0.296 * S - 15.8

Where:
- `L` is the average number of letters per 100 words  
- `S` is the average number of sentences per 100 words

It then outputs:
- `"Grade X"` (e.g., Grade 5)
- `"Grade 16+"` for anything above Grade 16
- `"Before Grade 1"` for anything below Grade 1

---

## 💻 How to Compile and Run

### 🔨 Compile
If using a Makefile:
make readability

Or manually:
clang -o readability readability.c -lm

▶️ Run
./readability

example -

$ ./readability
Text: Alice was beginning to get very tired of sitting by her sister...
Grade 8

