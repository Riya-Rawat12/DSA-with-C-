#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void circularLinkedList(struct Node*head){
    struct Node*ptr=head;
    do{
        printf("Element is %d \n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

struct Node * insertionAtFirst(struct Node * head, int data){
    struct Node*ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node*p=head->next;
    while(p->next!=head){
        p=p->next;
    }

    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

struct Node* insertAtIndex(struct Node*head,int data, int index){
    struct Node*ptr= (struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node * insertionAtEnd(struct Node * head, int data){
    struct Node*ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node*p=head->next;
    while(p->next!=head){
        p=p->next;
    }

    p->next=ptr;
    ptr->next=head;
    return head;
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
    head->next=second;

    second->data=33;
    second->next=third;

    third->data=45;
    third->next=fourth;

    fourth->data=56;
    fourth->next=head;

    printf("The circular linked list trasversal is \n");
    circularLinkedList(head);

    // printf("After insertion at first \n");
    // head=insertionAtFirst(head,80);
    // circularLinkedList(head);

    // printf("After insertion at end \n");
    // head=insertionAtEnd(head,32);
    // circularLinkedList(head);

    printf("After insertion at index\n");
    head = insertAtIndex(head,67,1);
    circularLinkedList(head);
return 0;
}