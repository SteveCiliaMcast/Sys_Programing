#REMEMBER TO ONLY USE TABS IN THE RECIPE AREA - NO SPACES
#build - create the executable from source code
all: Hello.exe

#build only if the source code is new
Hello.exe: Hello.c #target dependency - the command will execute only if Hello.c is newer tha Hello.exe
	@echo Building...
	@gcc Hello.c -o Hello.exe
	@echo Done.

run: Hello.exe
	@echo Running...
	@.\Hello.exe

clean:
	@echo Removing executable files...
	@if exist Hello.exe del /F /Q Hello.exe
	@echo Done.

rebuild: clean all