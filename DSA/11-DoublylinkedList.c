#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};

void doublyLinkedList(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element is %d \n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head= (struct Node*)malloc(sizeof(struct Node));
    second= (struct Node*)malloc(sizeof(struct Node));
    third= (struct Node*)malloc(sizeof(struct Node));
    fourth= (struct Node*)malloc(sizeof(struct Node));

    head->data=23;
    head->prev=NULL;
    head->next=second;

    second->data=33;
    second->prev=head;
    second->next=third;

    third->data=45;
    third->prev=second;
    third->next=fourth;

    fourth->data=56;
    fourth->prev=third;
    fourth->next=NULL;

    printf("The circular linked list trasversal is \n");
    doublyLinkedList(head);
    return 0;
}