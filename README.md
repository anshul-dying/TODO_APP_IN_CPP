# 📝 Simple TODO App in C++

This is a console-based TODO list manager written in C++. It allows users to:

- Add tasks with a title, start time, and end time
- View all tasks in a tabular format
- Delete tasks by ID
- Persist tasks using a plain text file (no external libraries required)

todo-app/<br>
├── todo.cpp<br>
├── todo.h<br>
├── tasks.txt<br> 
├── README.md<br>
└── .gitignore<br>

## 💡 Features

- Unique ID for each task
- Uses `std::tm` and `ctime` for time handling
- Neatly formatted output using `iomanip`
- Simple and extendable design using classes
- File I/O based storage (via `fstream`) for saving and loading tasks
- Easy to extend with new features (e.g., sorting, priority)        

## 📁 File Structure

- `todo.h` – Contains the `Todo` class definition
- `todo.cpp` – Implements the logic for task creation, deletion, and display and MAIN function

## 🛠️ Build & Run

### Using g++ (Linux/Mac/WSL/MinGW):

```bash
g++ -o todo_app todo.cpp
./todo_app
```

## Future Improvements 
- Add task editing
- Support task priorities or categories
- Set reminders using system time
- Use JSON or SQLite for more structured storage
