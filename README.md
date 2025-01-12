### **README: Running a Basic Terminal Globally**

This repository contains a basic custom terminal implemented in C++ and a Python script to make it accessible globally.

---

#### **Files and Directories:**

1. **`terminal.cpp`**  
   - Contains the main implementation of the custom terminal.
   - Provides functionality for:
     - **JavaScript Programming** (`javaScriptProgramming` folder)
     - **Python Programming** (`pythonProgramming` folder)
     - **Shell Programming** (`shellProgramming` folder)
   - These folders and their respective files are created dynamically while testing `terminal.cpp`.

2. **`run_terminal.py`**  
   - A Python script that compiles `terminal.cpp` and moves the executable (`customTerminal.exe`) to a directory for global access.

---

#### **Setup Instructions:**

1. **Compile and Run the Terminal:**
   - Run the Python script:
     ```bash
     python run_terminal.py
     ```
   - It will:
     - Compile `terminal.cpp`.
     - Move the executable to a specified folder (`bin_dir`).

2. **Add `bin_dir` to System Variables:**
   - Include the path of `bin_dir` in the system `PATH` variable:
     - On **Windows**:
       - Search for "Environment Variables" in the Start menu.
       - Edit the `Path` variable under User Variables.
       - Add the `bin_dir` folder path.

---

#### **Usage:**
After setup, you can run the terminal globally using:
```bash
customTerminal
```

---