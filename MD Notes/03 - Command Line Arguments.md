
### 🧠 What Are Command Line Arguments?

Command line arguments allow you to **pass information to a C program** when it is executed through the terminal.

When you run a C program, you can pass additional inputs right after the executable name.  
For example:

```bash
./add 5 10
```

Here:

- `./add` → is the program being run.
- `5` and `10` → are **command line arguments** passed to the program.

---
### 🧩 The `main()` Function Format

To accept command line arguments, `main()` is written as:

```c
int main(int argc, char *argv[])
```

|Parameter|Type|Meaning|
|---|---|---|
|`argc`|`int`|Argument count → number of arguments passed (including program name).|
|`argv`|`char *argv[]`|Argument vector → an **array of strings** containing the arguments.|

---
### 🧾 Example 1 — Display Command Line Arguments (`args.c`)

```c
#include <stdio.h>

/*
This program accepts command line arguments.

argc = number of arguments passed
argv = array of strings holding the arguments
*/

int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
```

#### 🧩 Example Output

**Command:**

```bash
./args hello world 123
```

**Output:**

```
Number of arguments: 4
Argument 0: ./args
Argument 1: hello
Argument 2: world
Argument 3: 123
```

---
### 🧮 Example 2 — Adding Numbers Using Command Line Arguments (`add.c`)

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Expect exactly two arguments (program name + 2 numbers)
    if (argc != 3)
    {
        printf("Error: Please provide exactly two integer arguments.\n");
        return 1; // Exit with error
    }

    // Convert arguments from string to integer
    int num1 = atoi(argv[1]); // atoi = ASCII to Integer
    int num2 = atoi(argv[2]);

    // Calculate and print result
    int sum = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    return 0;
}
```

#### 🧩 Example Output

**Command:**

```bash
./add 7 5
```

**Output:**

```
The sum of 7 and 5 is 12
```

---
### ⚙️ Makefile Example for Both Programs

```makefile
#---------------------------------------------
# Makefile for Command Line Argument Programs
#---------------------------------------------

all: args add

# Build args program
args: args.c
	gcc -Wall args.c -o args.exe

# Build add program
add: add.c
	gcc -Wall add.c -o add.exe

# Run examples
run_args:
	./args.exe Hello 123 world

run_add:
	./add.exe 10 20

clean:
	if exist args.exe del /F /Q args.exe
	if exist add.exe del /F /Q add.exe
```

---
### 🧩 Summary Table

| Symbol                  | Meaning                                               |
| ----------------------- | ----------------------------------------------------- |
| `argc`                  | Number of arguments passed (including program name).  |
| `argv[0]`               | Always contains the **program name**.                 |
| `argv[1]`, `argv[2]`, … | Contain the **actual arguments** entered by the user. |
| `atoi()`                | Converts string to integer (`#include <stdlib.h>`).   |
| `argc` check            | Prevents errors if arguments are missing.             |

---
### 🧠 Key Points to Remember

- Always check `argc` to ensure the correct number of arguments.
- `argv` elements are **strings** (text), even if they look like numbers.
- Use `atoi()` or `strtol()` to convert text arguments into numbers.
- `argv[0]` is always the **program name**.
- You can pass arguments using both **Linux** and **Windows PowerShell**.