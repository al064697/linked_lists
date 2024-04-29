#include <stdio.h>
#include "list.h"

/*En el contexto de las estructuras de datos, un nodo es un objeto que contiene información y puede tener referencias a otros nodos. Los nodos son los elementos fundamentales utilizados en estructuras de datos como listas enlazadas, árboles y grafos.

El typedef struct en C es una declaración que se utiliza para definir un nuevo tipo de datos que agrupa varios datos de diferentes tipos.

El operador -> en C se utiliza para acceder a los miembros de una estructura o unión a través de un puntero.

Declaración de punteros: Cuando declaras una variable con un asterisco(*), estás declarando un puntero a una variable de cierto tipo.*/

int main(){
    List *l;
    l=createList();
    Node *n;
    //Node *n=createNode(47);
    insertAtEnd(l,createNode(47));
    insertAtEnd(l,createNode(7));
    insertAtEnd(l,createNode(5));
    //insertAtStart(l,createNode(50));
    //insertAtIndex(l,createNode(6),2);
    //deleteByValue(l,7);
    print(l);
    /*n=searchByValue(l,2);;
    if(n!=NULL){
        printf("Node found = ");
        printNode(n);
    }*/
    emptyList(l);
    printf("After emptying the list: ");
    print(l);
    printf("After inserting: ");
    insertAtEnd(l,createNode(10));
    print(l);
    return 0;
}