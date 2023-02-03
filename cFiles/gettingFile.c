#include<stdio.h>
#include<stdlib.h>
#include"../headerFiles/gettingFile.h"


char *GetFileName(char text[])
{
    int fileNameLength = 0;
    char *fileName = (char *)malloc(fileNameLength);
    char tempChar;

    printf("%s", text);
    tempChar = getchar();
    while (tempChar != '\n') {
        fileNameLength++;
        fileName = (char *)realloc(fileName, sizeof(char) * fileNameLength);
        *(fileName + fileNameLength - 1) = tempChar;
        tempChar = getchar();
    }
    fileName = (char *)realloc(fileName, (sizeof(char) * fileNameLength) + 1);
    *(fileName + fileNameLength) = '\0';

    return fileName;
}