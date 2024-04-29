#include "node.h"

typedef struct list{
    Node *root;
    int total;
    Node *last;
}List;

List *createList(){
    List *l=(List*)malloc(sizeof(List));
    l->root=NULL;
    l->total=0;
    l->last=NULL;
    return l;
}

int isEmpty(List *l){
    if(l->root==NULL){
        return 1;
    }else{
        return 0;
    }
}

void insertAtEnd(List *l, Node *n){
    if(isEmpty(l)){
        l->root = n;
        l->last = n;
    }else{
        l->last->next = n;
        l->last = n;
    }
    l->total++;
} 

void insertAtStart(List *l, Node *n){
    if(isEmpty(l)) {
        l->root=n;
        l->last=n;
    }else{
        n->next=l->root;
        l->root=n;
    }
    l->total++;
}

void insertAtIndex(List *l, Node *n, int index){
    Node *previous, *aux;
    if((index>=0)&&(index<l->total)){
        if(isEmpty(l)) {
            l->root=n;
            l->last=n;
        }else{
            if(index==0){
            insertAtStart(l,n);
            }else if(index==l->total){
                insertAtEnd(l,n);
            }else{
                aux=l->root;
                for (int i=0; i<index; i++){
                    previous=aux;
                    aux=aux->next;
                }
                previous->next=n;
                n->next=aux;
                l->total++;
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

void deleteFirstElement(List *l){
    Node *aux;
    if(!isEmpty(l)){
        aux=l->root;
        if(l->total==1){
            l->root=NULL;
            l->last=NULL;
        }else{
            l->root=l->root->next;
        }
        free(aux);
        l->total--;
    }
}

void deleteLastElement(List *l){
    Node *aux,*penultimate;
    if(!isEmpty(l)){
        aux=l->last;
        if(l->total==1){
            l->root=NULL;
            l->last=NULL;
        }else{
            penultimate=l->root;
            while(penultimate->next!=l->last){
                penultimate=penultimate->next;
            }
            l->last=penultimate;
            l->last->next=NULL;
        }
        free(aux);
        l->total--;
    }
}

void deleteByIndex(List *l,int index){
    Node *before, *aux;
    if((index>=0)&&(index<l->total)){
        if(index==0){
            deleteFirstElement(l);
        }else if(index==l->total-1){
            deleteLastElement(l);  
        }else{
            aux=l->root;
            for(int i=0; i<index; i++){
                before=aux;
                aux=aux->next;
            }
            before->next=aux->next;
            free(aux);
            l->total--;
        }
    }
}

void deleteByValue(List *l,int value){
    int i=0;
    Node *aux=l->root;
    while((aux!=NULL)&&(aux->data!=value)){
        aux=aux->next;
        i++;
    }
    if(aux!=NULL){
        deleteByIndex(l,i);
    }
}

Node* searchByIndex(List *l,int index){
    Node *aux=NULL;
    if((index>=0)&&(index<l->total)){
        aux=l->root;
        for(int i=0; i<index; i++){
            aux=aux->next;
        }
    }
    return aux;
}

Node* searchByValue(List *l,int value){
    Node *aux=l->root;
    aux=l->root;
    while((aux!=NULL)&&(aux->data!=value)){
        aux=aux->next;
    }
    return aux;
}

void emptyList(List *l){
    while(!isEmpty(l)){
        deleteFirstElement(l);
    }
}

