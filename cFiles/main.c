// LSP - 2213783, pastas - povilas.pliuskus@mif.stud.vu.lt
// uzduotis - 4.8

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../headerFiles/menu.h"
#include"../headerFiles/gettingFile.h"
#include"../headerFiles/fileValidation.h"

int main()
{
    char *fileName;
    char menuKey;

    Node *firstNode = NULL;

    do {
        fileName = GetFileName("Iveskite duomenu failo pavadinima: ");
    } while (!FileValidation(fileName));

    printf("Jei norite atidaryti meniu iveskite '?'\n");
    while (menuKey != '3') {
        menuKey = MenuInput("Iveskite meniu komanda: ");
        if (menuKey == '0') {
            firstNode = CreateList(fileName);
        }
        else if (menuKey == '1') {
            if (firstNode == NULL) {
                printf("Sarasas nesukurtas arba tuscias\n");
            }
            else {
                PrintList(firstNode);
            }
        }
        else if (menuKey == '2') {
            if (firstNode == NULL) {
                printf("Sarasas nesukurtas arba tuscias\n");
            }
            else {
                DeleteAnElement(&firstNode);
            }
        }
        else if (menuKey != '3') {
            PrintMenu();
        }
    }
    
    firstNode = NULL;
    free(fileName);
}