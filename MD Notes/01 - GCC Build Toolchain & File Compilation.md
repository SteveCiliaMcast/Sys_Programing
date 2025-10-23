
When compiling a C program, GCC (GNU Compiler Collection) performs **four main stages**:

| Stage                | Command Flag | Input         | Output                     | Description                                                                      |
| :------------------- | :----------- | :------------ | :------------------------- | :------------------------------------------------------------------------------- |
| **1. Preprocessing** | `-E`         | `.c` (source) | `.i` (preprocessed source) | Removes comments, expands macros (`#define`), and includes headers (`#include`). |
| **2. Compilation**   | `-S`         | `.i`          | `.s` (assembly)            | Converts preprocessed code into assembly instructions.                           |
| **3. Assembly**      | `-c`         | `.s`          | `.o` (object)              | Assembles assembly code into machine (object) code.                              |
| **4. Linking**       | *(none)*     | `.o`          | executable                 | Combines object files and libraries into a final executable.                     |

---
### ⚙️ Full Compilation

```bash
gcc hello.c -o hello
```

* Compiles `hello.c` through all stages to produce an executable named `hello`.

---
### 🧱 Step-by-Step Compilation

#### 1️⃣ Preprocessing

```bash
gcc -E hello.c -o hello.i
```

* Generates the **preprocessed code** (`hello.i`).

#### 2️⃣ Compilation

```bash
gcc -S hello.i -o hello.s
```

* Generates the **assembly code** (`hello.s`).

#### 3️⃣ Assembly

```bash
gcc -c hello.s -o hello.o
```

* Generates the **object file** (`hello.o`).

#### 4️⃣ Linking

```bash
gcc hello.o -o hello
```

* Produces the **final executable** (`hello`).

---
### 🧾 Save All Intermediate Files Automatically

```bash
gcc -save-temps hello.c -o hello
```

* Retains all intermediate files:

  * `hello.i` → preprocessed file
  * `hello.s` → assembly file
  * `hello.o` → object file
  * `hello` → final executable

---
### 🧩 Multi-File Compilation

Large programs are split into multiple **source (`.c`)** and **header (`.h`)** files for modularity.

#### Example Directory:

```
main.c
math.c
math.h
```

#### Contents:

**math.h**

```c
int add(int a, int b);
int multiply(int a, int b);
```

**math.c**

```c
#include "math.h"

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}
```

**main.c**

```c
#include <stdio.h>
#include "math.h"

int main() {
    printf("Sum: %d\n", add(5, 3));
    printf("Product: %d\n", multiply(5, 3));
    return 0;
}
```

---
### 🧠 Compiling Multiple Files

#### Option 1 — Compile and Link in One Step

```bash
gcc main.c math.c -o program
```

#### Option 2 — Separate Compilation + Linking

```bash
gcc -c main.c -o main.o
gcc -c math.c -o math.o
gcc main.o math.o -o program
```

#### Result

* Output executable: `program`
* Run it:

  ```bash
  ./program
  ```

---

### ✅ Advantages of Multi-File Compilation

* Faster recompilation — only modified files are recompiled.
* Improved organization and modularity.
* Easier debugging and testing.
* Enables reuse of code through headers and object files.