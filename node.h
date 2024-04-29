#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
}Node; 

Node *createNode(int data) {
    Node *n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    return n;
} 

void printNode(Node *n) {
    printf("%d\n", n->data);
}