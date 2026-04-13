#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

int main () {
    struct Node *n1, *n2, *n3;
    n1 = malloc(sizeof(struct Node));
    n2 = malloc(sizeof(struct Node));
    n3 = malloc(sizeof(struct Node));
    
    n1->data=1;
    n1->next=n2;
    n1->prev=NULL;

    n2->data=2;
    n2->next=n3;
    n2->prev=n1;

    n3->data=3;
    n3->next=NULL;
    n3->prev=n2;

    //traversal maju
    struct Node *temp=n1;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    //traversal mundur
    temp =n3;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->prev;
    }
    return 0;
}