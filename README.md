# 🔍 Inverted Search Engine

An Inverted Search Engine implemented in C using Hash Tables and Linked Lists.

---

## 📌 Overview

This project builds an inverted index from multiple text files.

It maps:
word → files → frequency

This allows efficient searching of words across multiple documents.

---

## 🚀 Features

- Create database from input files  
- Display database  
- Search for a word  
- Save database to file  
- Update database from file  

---

## 🧠 Core Concepts Implemented

### Hash Tables
- Indexing using first character
- Fast lookup

### Linked Lists
- Store words and file details
- Handle collisions

### File Handling
- Read multiple files
- Store and retrieve data

---

## 🛠️ Tech Stack

- Language: C  
- Data Structures: Hash Table, Linked List  
- Compiler: GCC  

---

## 📁 Project Structure

```
Inverted-Search-Engine
│
├── create_database.c
├── display_database.c
├── f1.txt
├── f2.txt
├── f3.txt
├── f4.txt
├── header.h
├── insert_last.c
├── main.c
├── save_database.c
├── search_database.c
├── update_database.c
├── validation.c
└── README.md
```

---

## ⚙️ How to Compile and Run

Compile:
```bash
gcc *.c
```

Run:
```bash
./a.out f1.txt f2.txt f3.txt f4.txt
```

---

## 📋 Program Menu

1. Create Database  
2. Display Database  
3. Search Database  
4. Save Database  
5. Update Database  
6. Exit  

---

## 📊 Example Output

```
| Index | Word  | Filecount |
|   7   | hello |     3     |
```

---

## 🔗 Applications

- Search Engines  
- Document Retrieval Systems  
- Text Processing Tools  

---

## 🎯 Learning Outcomes

- Hashing techniques  
- File handling in C  
- Efficient searching algorithms  
- Data structure integration  

---

## 👩‍💻 Author
Sheebha
