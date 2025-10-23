# Makefile for C programs: smaller, average, and bmi

# Targets
all: smaller average bmi

smaller: smaller.c
	gcc -Wall smaller.c -o smaller.exe

average: average.c
	gcc -Wall average.c -o average.exe

bmi: bmi.c
	gcc -Wall bmi.c -o bmi.exe

clean:
	if exist smaller.exe del /F /Q smaller.exe
	if exist average.exe del /F /Q average.exe
	if exist bmi.exe del /F /Q bmi.exe

rebuild: clean all