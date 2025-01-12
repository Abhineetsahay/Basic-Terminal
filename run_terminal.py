import os
import subprocess
import shutil
import platform

source_file = "terminal.cpp"
executable = "customTerminal.exe" if platform.system() == "Windows" else "my_terminal"
bin_dir = os.path.join(".", "bin")  

def compile_code():
    print("Compiling C++ code...")
    if os.path.exists(executable):
        try:
            os.remove(executable) 
        except PermissionError:
            print(f"Permission denied while deleting '{executable}'. Close any programs using it and try again.")
            return False

    result = subprocess.run(["g++", "-o", executable, source_file], capture_output=True, text=True)
    if result.returncode == 0:
        print("Compilation successful.")
        if os.path.exists(executable):
            print(f"Executable '{executable}' created successfully.")
        else:
            print(f"Error: Compilation succeeded but '{executable}' not found.")
        return True
    else:
        print("Compilation failed:")
        print(result.stderr)
        return False

def move_executable():
    print(f"Checking if source file '{executable}' exists in: {os.getcwd()}")
    if not os.path.exists(executable):
        print(f"Error: Executable '{executable}' not found. Check compilation output.")
        return

    print(f"Checking if destination folder exists: {bin_dir}")
    if not os.path.isdir(bin_dir):
        print(f"Destination folder '{bin_dir}' does not exist. Creating it...")
        try:
            os.makedirs(bin_dir)
            print(f"Folder '{bin_dir}' created successfully.")
        except Exception as e:
            print(f"Error while creating folder '{bin_dir}': {e}")
            return

    print(f"Attempting to move '{executable}' to '{bin_dir}'...")
    try:
        shutil.move(executable, os.path.join(bin_dir, executable))
        print(f"The terminal is now accessible globally. Run it using '{os.path.join(bin_dir, executable)}'.")
    except FileNotFoundError as e:
        print(f"FileNotFoundError: {e}")
    except PermissionError:
        print(f"Permission denied. Close any programs using '{executable}' and check folder permissions.")
    except Exception as e:
        print(f"Unexpected error during move: {e}")

def main():
    if not os.path.exists(source_file):
        print(f"Error: Source file '{source_file}' not found in the current directory: {os.getcwd()}")
        return

    if compile_code():
        move_executable()

if __name__ == "__main__":
    main()
