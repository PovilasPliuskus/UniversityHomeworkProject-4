#ifndef MENU_H
#define MENU_H

typedef struct Node Node;

struct Node {
    float data;
    Node *prevNode;
    Node *nextNode;
};

char MenuInput(char text[]);
void PrintMenu();
Node *CreateList(char *fileName);
void CreateNode(float number, Node **headPointer, Node **tempPointer);
void PrintList(Node *headPointer);
float DeleteAnElement(Node **headPointer);
void SearchNode(float *max, Node *node, Node *headPointer, Node **toDelete);

#endif