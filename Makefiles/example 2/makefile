# Default target
all: StackApp.exe

# Build executable from object files
StackApp.exe: main.o stack.o
	gcc -Wall main.o stack.o -o StackApp.exe

# Compile each C file to an object file
main.o: main.c stack.h
	gcc -Wall -c main.c

stack.o: stack.c stack.h
	gcc -Wall -c stack.c

# Run the program
run: StackApp.exe
	.\StackApp.exe

# Clean up object and executable files
clean:
	if exist main.o del /F /Q main.o
	if exist stack.o del /F /Q stack.o
	if exist StackApp.exe del /F /Q StackApp.exe

# Rebuild (clean + all)
rebuild: clean all
