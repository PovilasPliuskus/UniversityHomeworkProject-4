#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../headerFiles/menu.h"
#include"../headerFiles/gettingFile.h"

char MenuInput(char text[])
{
    char input;
    printf("%s", text);
    input = getchar();
    while (getchar() != '\n') {
        input = '?';
    }
    return input;
}

void PrintMenu()
{
    printf("Galimos meniu komandos:\n");
    printf("0 - sukuria sarasa is duoto duomenu failo\n");
    printf("1 - isspausdina sarasa\n");
    printf("2 - ismeta is saraso didziausia elementa\n");
    printf("3 - iseina is programos\n");
}

Node *CreateList(char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r+");

    float number;
    Node *headPointer = NULL;
    Node *tempPointer;

    while (!feof(file)) {
        if (fscanf(file, "%f", &number) != 1) {
            printf("duomenu failas yra netaisyklingas\n");
            exit(0);
        }
        else {
            CreateNode(number, &headPointer, &tempPointer);
        }
    }
    // Connecting the last node to a circular linked list
    tempPointer->nextNode = headPointer;
    headPointer->prevNode = tempPointer;
    fclose(file);
    printf("Sekmingai paimti duomenys is failo\n");
    return headPointer;
}

void CreateNode(float number, Node **headPointer, Node **tempPointer)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = number;

    if (*headPointer == NULL) {
        *headPointer = node;
    }
    else {
        node->prevNode = *tempPointer;
        (*tempPointer)->nextNode = node;
    }
    *tempPointer = node;
}

void PrintList(Node *headPointer)
{
    Node *node = headPointer;
    float data;

    printf("Sarasas:\n");

    do {
        data = node->data;
        printf("%f\n", data);
        node = node->nextNode;
    } while (node != headPointer);
}

float DeleteAnElement(Node **headPointer)
{
    Node *tempHeadNode = *headPointer;
    float max = tempHeadNode->data;
    Node *toDelete = tempHeadNode;

    if (tempHeadNode->nextNode == tempHeadNode) {
        *headPointer = NULL;
        printf("Sarasas buvo visiskai pasalintas\n");
        return 0;
    }

    SearchNode(&max, tempHeadNode, tempHeadNode, &toDelete);

    Node *oneNodeBefore = toDelete->prevNode;
    Node *oneNodeAfter = toDelete->nextNode;

    if (toDelete == tempHeadNode) {
        *headPointer = tempHeadNode->nextNode;
    }

    float temp = toDelete->data;

    oneNodeBefore->nextNode = oneNodeAfter;
    oneNodeAfter->prevNode = oneNodeBefore;

    printf("Pasalintas didziausias elementas is saraso\n");

    return temp;
}

void SearchNode(float *max, Node *node, Node *headPointer, Node **toDelete)
{
    if (*max < node->data) {
        *max = node->data;
        *toDelete = node;
    }
    node = node->nextNode;
    if (node != headPointer) {
        SearchNode(max, node, headPointer, toDelete);
    }
}