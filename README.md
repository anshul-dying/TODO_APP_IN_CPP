# 📝 Simple TODO App in C++

This is a console-based TODO list manager written in C++. It allows users to:

- Add tasks with a title, start time, and end time
- View all tasks in a tabular format
- Delete tasks by ID

todo-app/
├── todo.cpp
├── todo.h
├── README.md
└── .gitignore

## 💡 Features

- Unique ID for each task
- Uses `std::tm` and `ctime` for time handling
- Neatly formatted output using `iomanip`
- Simple and extendable design using classes

## 📁 File Structure

- `todo.h` – Contains the `Todo` class definition
- `todo.cpp` – Implements the logic for task creation, deletion, and display and MAIN function

## 🛠️ Build & Run

### Using g++ (Linux/Mac/WSL/MinGW):

```bash
g++ -o todo_app todo.cpp
./todo_app

