#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedList(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}


int main(){
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    first->data=1;
    first->next=second;

    second->data=12;
    second->next=third;

    third->data=19;
    third->next=fourth;

    fourth->data=67;
    fourth->next=NULL;

    linkedList(first);

return 0;
}