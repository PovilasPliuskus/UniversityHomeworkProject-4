output: main.o gettingFile.o fileValidation.o menu.o
	gcc main.o gettingFile.o fileValidation.o menu.o -o output.exe

main.o: cFiles/main.c
	gcc -c cFiles/main.c

gettingFile.o: cFiles/gettingFile.c
	gcc -c cFiles/gettingFile.c

fileValidation.o: cFiles/fileValidation.c
	gcc -c cFiles/fileValidation.c

menu.o: cFiles/menu.c
	gcc -c cFiles/menu.c

test.o: cFiles/test.c
	gcc -c cFiles/test.c

test: test.o gettingFile.o fileValidation.o menu.o
	gcc test.o gettingFile.o fileValidation.o menu.o -o test.exe

clean:
	del *.o output.exe test.exe