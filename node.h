#include <stdlib.h>
#include <stdio.h>

typedef struct node { //Crea una estructura de datos nuevq
    int data;
    struct node *next;
}Node;  //Alias de la estructura de datos

Node *createNode(int data){ //Función que crea un nuevo nodo
    Node *n=(Node*)malloc(sizeof(Node)); //Reserva memoria para el nodo
    n->data=data; //Asigna el valor al nodo
    n->next=NULL; //Asigna NULL al siguiente nodo
    return n;
} 

void printNode(Node *n) { //Función que imprime el nodo
    printf("%d\n", n->data);
}