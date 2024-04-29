#include "node.h"

typedef struct list{ //Crea una estructura de datos nueva
    Node *root;
    int total;
    Node *last;
}List; //Alias de la estructura de datos

List *createList(){ //Función que crea una nueva lista
    List *l=(List*)malloc(sizeof(List)); //Reserva memoria para la lista
    l->root=NULL; //Asigna NULL al primer nodo
    l->total=0; //Asigna 0 al total de nodos
    l->last=NULL; //Asigna NULL al último nodo
    return l;
}

int isEmpty(List *l){ //Función que verifica si la lista está vacía
    if(l->root==NULL){
        return 1;
    }else{
        return 0;
    }
}

void insertAtEnd(List *l, Node *n){  //Función que inserta un nodo al final de la lista
    if(isEmpty(l)){  //Si la lista está vacía
        l->root = n; //Asigna el nodo al primer nodo
        l->last = n; //Asigna el nodo al último nodo
    }else{ //Si la lista no está vacía
        l->last->next = n; //Asigna el nodo al siguiente nodo
        l->last = n; //Asigna el nodo al último nodo
    }
    l->total++; //Aumenta el total de nodos
} 

void insertAtStart(List *l, Node *n){ //Función que inserta un nodo al inicio de la lista
    if(isEmpty(l)) { //Si la lista está vacía
        l->root=n; //Asigna el nodo al primer nodo
        l->last=n; //Asigna el nodo al último nodo
    }else{ //Si la lista no está vacía
        n->next=l->root; //Asigna el primer nodo al siguiente nodo
        l->root=n; //Asigna el nodo al primer nodo
    }
    l->total++; //Aumenta el total de nodos
}

void insertAtIndex(List *l, Node *n, int index){ //Función que inserta un nodo en una posición específica
    Node *previous, *aux;
    if((index>=0)&&(index<l->total)){ //Si el índice es válido
        if(isEmpty(l)) { //Si la lista está vacía
            l->root=n; //Asigna el nodo al primer nodo
            l->last=n; //Asigna el nodo al último nodo
        }else{ //Si la lista no está vacía
            if(index==0){ //Si el índice es 0
            insertAtStart(l,n); //Inserta el nodo al inicio de la lista
            }else if(index==l->total){ //Si el índice es igual al total de nodos
                insertAtEnd(l,n); //Inserta el nodo al final de la lista
            }else{ //Si el índice no es 0 ni igual al total de nodos
                aux=l->root; //Asigna el primer nodo a un nodo auxiliar
                for (int i=0; i<index; i++){ //Recorre la lista hasta llegar al índice
                    previous=aux; //Asigna el nodo auxiliar al nodo anterior
                    aux=aux->next; //Asigna el siguiente nodo al nodo auxiliar
                }
                previous->next=n; //Asigna el nodo al siguiente nodo
                n->next=aux; //Asigna el siguiente nodo al nodo
                l->total++; //Aumenta el total de nodos
            }  
        }
    }else{
        
    }
}

void print(List *l){ 
    Node *aux =l->root;
    while(aux!=NULL){
        printNode(aux);
        aux=aux->next;
    }
}

void deleteFirstElement(List *l){ //Función que elimina el primer nodo de la lista
    Node *aux;
    if(!isEmpty(l)){ //Si la lista no está vacía
        aux=l->root; //Asigna el primer nodo a un nodo auxiliar
        if(l->total==1){ //Si el total de nodos es 1
            l->root=NULL; //Asigna NULL al primer nodo
            l->last=NULL; //Asigna NULL al último nodo
        }else{ //Si el total de nodos no es 1
            l->root=l->root->next; //Asigna el siguiente nodo al primer nodo
        }
        free(aux); //Libera la memoria del nodo auxiliar
        l->total--; //Disminuye el total de nodos
    }
}

void deleteLastElement(List *l){ //Función que elimina el último nodo de la lista
    Node *aux,*penultimate; 
    if(!isEmpty(l)){ //Si la lista no está vacía
        aux=l->last; //Asigna el último nodo a un nodo auxiliar
        if(l->total==1){ //Si el total de nodos es 1
            l->root=NULL; //Asigna NULL al primer nodo
            l->last=NULL; //Asigna NULL al último nodo
        }else{ //Si el total de nodos no es 1
            penultimate=l->root; //Asigna el primer nodo a un nodo penúltimo
            while(penultimate->next!=l->last){ //Recorre la lista hasta llegar al penúltimo nodo
                penultimate=penultimate->next; //Asigna el siguiente nodo al penúltimo nodo
            }
            l->last=penultimate; //Asigna el penúltimo nodo al último nodo
            l->last->next=NULL; //Asigna NULL al siguiente nodo
        }
        free(aux); //Libera la memoria del nodo auxiliar
        l->total--; //Disminuye el total de nodos
    }
}

void deleteByIndex(List *l,int index){ //Función que elimina un nodo por índice
    Node *before, *aux; 
    if((index>=0)&&(index<l->total)){ //Si el índice es válido
        if(index==0){ //Si el índice es 0
            deleteFirstElement(l); //Elimina el primer nodo
        }else if(index==l->total-1){ //Si el índice es igual al total de nodos menos 1
            deleteLastElement(l);   //Elimina el último nodo
        }else{ //Si el índice no es 0 ni igual al total de nodos menos 1
            aux=l->root; //Asigna el primer nodo a un nodo auxiliar
            for(int i=0; i<index; i++){ //Recorre la lista hasta llegar al índice
                before=aux; //Asigna el nodo auxiliar al nodo anterior
                aux=aux->next; //Asigna el siguiente nodo al nodo auxiliar
            }
            before->next=aux->next; //Asigna el siguiente nodo al siguiente nodo
            free(aux); //Libera la memoria del nodo auxiliar
            l->total--; //Disminuye el total de nodos
        }
    }
}

void deleteByValue(List *l,int value){ //Función que elimina un nodo por valor
    int i=0; 
    Node *aux=l->root; //Asigna el primer nodo a un nodo auxiliar
    while((aux!=NULL)&&(aux->data!=value)){ //Recorre la lista hasta encontrar el valor
        aux=aux->next; //Asigna el siguiente nodo al nodo auxiliar
        i++; //Aumenta el índice
    }
    if(aux!=NULL){ //Si el nodo auxiliar no es NULL
        deleteByIndex(l,i); //Elimina el nodo por índice
    }
}

Node* searchByIndex(List *l,int index){ //Función que busca un nodo por índice
    Node *aux=NULL; //Asigna NULL a un nodo auxiliar
    if((index>=0)&&(index<l->total)){ //Si el índice es válido
        aux=l->root; //Asigna el primer nodo al nodo auxiliar
        for(int i=0; i<index; i++){ //Recorre la lista hasta llegar al índice
            aux=aux->next; //Asigna el siguiente nodo al nodo auxiliar
        }
    }
    return aux;
}

Node* searchByValue(List *l,int value){ //Función que busca un nodo por valor
    Node *aux=l->root; //Asigna el primer nodo a un nodo auxiliar
    aux=l->root; //Asigna el primer nodo al nodo auxiliar
    while((aux!=NULL)&&(aux->data!=value)){ //Recorre la lista hasta encontrar el valor
        aux=aux->next; //Asigna el siguiente nodo al nodo auxiliar
    }
    return aux; 
}

void emptyList(List *l){ //Función que vacía la lista
    while(!isEmpty(l)){ //Mientras la lista no esté vacía
        deleteFirstElement(l); //Elimina el primer nodo
    }
}

