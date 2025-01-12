### **README: Running a Custom Terminal Globally**

This repository contains a custom terminal implemented in C++ and a Python script to automate its compilation and global accessibility.

---

### **Files and Directories**

1. **`terminal.cpp`**  
   - The core implementation of the custom terminal.  
   - Features include:
     - **JavaScript Programming**: Creates a `javaScriptProgramming` folder for testing.
     - **Python Programming**: Creates a `pythonProgramming` folder for testing.
     - **Shell Programming**: Creates a `shellProgramming` folder for testing.  
   - These folders and files are dynamically created when running or testing `terminal.cpp`.

2. **`run_terminal.py`**  
   - A Python script to automate:
     - Compilation of `terminal.cpp` using `g++`.
     - Moving the generated executable to a folder (`bin` by default) for easy global access.

---

### **Setup Instructions**

1. **Prepare the Environment**  
   - Ensure you have the following installed:
     - **Python 3.x**
     - **g++ Compiler** (part of GCC)  
   - Add the GCC compiler to your system's PATH if it’s not already accessible.

2. **Compile and Deploy the Terminal**  
   - Run the Python script from the repository's root directory:
     ```bash
     python run_terminal.py
     ```
   - What happens:
     - The script compiles `terminal.cpp`.
     - The resulting executable (e.g., `customTerminal.exe` or `my_terminal`) is moved to the `bin` directory within the repository.

3. **Add `bin` Directory to System PATH**  
   To make the terminal accessible globally:
   - Locate the `bin` directory path (relative to the repository root).  
     Example: `./bin/`  
   - Add the path to your system's PATH environment variable:
     - **Windows**:
       1. Search for "Environment Variables" in the Start menu.
       2. Edit the `Path` variable under User Variables.
       3. Add the full path to the `bin` folder (e.g., `C:\path\to\repository\bin`).


---

### **Usage**

After completing the setup, you can run the terminal globally from anywhere in your system by typing:
```bash
customTerminal
```

---

### **Notes**

- Ensure the `bin` directory remains intact to avoid breaking the global command.
- If any issues arise during compilation or execution, ensure the `g++` compiler is installed and properly added to your system's PATH.

--- 

Happy coding! 😊