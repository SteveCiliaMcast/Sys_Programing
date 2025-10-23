
### ⚙️ What is `make`?

`make` is a **build automation tool** that automatically compiles and links programs by following rules defined in a file called a **Makefile**.

It determines which files need to be recompiled by checking **timestamps** — recompiling only what has changed.

---
### 🪟 Make on Windows

* `make` is **not automatically available**.
* If using **MinGW**, the command is:

  ```bash
  mingw32-make
  ```

* Executables end with `.exe` (e.g. `Hello.exe`).
* PowerShell is **not case-sensitive**.
* To specify a Makefile explicitly:

  ```bash

  mingw32-make -f MyMakefile.mk

  ```

---
### 🐧 Make on Linux

* `make` is **pre-installed by default**.
* To run the Makefile in the current directory:

  ```bash
  make
  ```

* The default Makefile name should be:
  * `Makefile` or
  * any `.mk` file (e.g., `MyMakefile.mk` → `make -f MyMakefile.mk`)
* Linux executables **have no file extension**.
* Linux is **case-sensitive**.

---
### 🧠 Good Practices When Writing Makefiles

✅ **Efficiency**

* Do not rebuild source code if it hasn’t changed.
* `make` should only rebuild when dependencies (like `.c` files) are newer than the target.

✅ **Dependency Awareness**

* If the executable doesn’t exist, `make` should automatically compile it.
  
✅ **Clean Build**

* Always check if files exist before deleting them (to avoid errors).

✅ **Formatting**

* **Use TABs, not spaces**, in the **recipe area** (the command lines after targets).

✅ **Documentation**

* Use comments (`# ...`), but never on the same line as a GCC command.
 
---
### 🧾 Naming Conventions

| File Type                 | Convention                               |
| ------------------------- | ---------------------------------------- |
| **C source files (`.c`)** | lowercase (e.g., `main.c`, `math.c`)     |
| **Header files (`.h`)**   | lowercase (e.g., `math.h`)               |
| **Directories**           | avoid spaces (use underscores if needed) |
  
---
### 🧩 Example: Basic Makefile (Windows Version)

> ⚠️ Remember: in PowerShell or CMD, use **tabs** before each recipe command!

```makefile
#---------------------------------------------
# Example Makefile (Windows)
#---------------------------------------------

# REMEMBER TO USE ONLY TABS IN THE RECIPE AREA!

# Default target — builds the executable

all: Hello.exe

# Build only if Hello.c is newer than Hello.exe
Hello.exe: Hello.c
  gcc Hello.c -o Hello.exe

# Run the program (requires executable)
run: Hello.exe
  .\Hello.exe

# Clean up compiled files (check if they exist first)
clean:
  if exist Hello.exe del /F /Q Hello.exe

# Rebuild: clean + compile
rebuild: clean all
```

---
### 🧩 Example: Linux Version

```makefile
#---------------------------------------------
# Example Makefile (Linux)
#---------------------------------------------

# Build the executable (default target)
all: hello

# Target and dependency
hello: hello.c
  gcc hello.c -o hello

# Run the program
run: hello
  ./hello

# Clean up
clean:
  rm -f hello

# Rebuild target
rebuild: clean all
```

---
### 🧠 Example Source Code (`hello.c`)

```c
#include <stdio.h>

int main(void)
{
    printf("Hello there!\n");
    return 0;
}
```

---
### 🔍 Key Takeaways

* **`make`** automates building, linking, and cleaning projects.
* **Targets** define actions (like `all`, `run`, `clean`).
* **Dependencies** ensure recompilation only when necessary.
* Always use **tabs**, not spaces, for commands.
* Separate `clean` and `rebuild` targets help manage build cycles efficiently.