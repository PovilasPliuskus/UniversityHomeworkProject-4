#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../headerFiles/menu.h"
#include"../headerFiles/gettingFile.h"
#include"../headerFiles/fileValidation.h"

float GetBiggestElement(Node *headPointer);

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
            //
            assert(firstNode != NULL);
            //
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
                float biggestElement = GetBiggestElement(firstNode);
                float deletedElement = DeleteAnElement(&firstNode);
                //
                assert(biggestElement == deletedElement);
                //
            }
        }
        else if (menuKey != '3') {
            PrintMenu();
        }
    }

    //
    assert(menuKey == '3');
    //
    
    firstNode = NULL;
    free(fileName);
}

float GetBiggestElement(Node *headPointer)
{
    Node *tempHeadNode = headPointer;
    float max = tempHeadNode->data;
    Node *toDelete = tempHeadNode;

    if (tempHeadNode->nextNode == tempHeadNode) {
        headPointer = NULL;
        return 0;
    }

    SearchNode(&max, tempHeadNode, tempHeadNode, &toDelete);

    Node *oneNodeBefore = toDelete->prevNode;
    Node *oneNodeAfter = toDelete->nextNode;

    if (toDelete == tempHeadNode) {
        headPointer = tempHeadNode->nextNode;
    }

    return toDelete->data;
}