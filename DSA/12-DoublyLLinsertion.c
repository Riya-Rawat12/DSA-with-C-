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

struct Node*insertionAtFirst(struct Node*head,int data){
    struct Node *ptr = (struct Node *)malloc (sizeof(struct Node));
    
    ptr->prev=NULL;
    ptr->data=data;
    ptr->next=NULL;
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
    return head;
}

struct Node * insertionAtEnd(struct Node *head,int data){
    struct Node*ptr=(struct Node *)malloc(sizeof(struct Node));
    
    struct Node*p=head;

    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->prev=p;
    ptr->next=NULL;
    return head;
}

struct Node*insertionAtIndex(struct Node*head, int data, int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
     int i=0;
    struct Node * p=head;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next = ptr;
     ptr->prev=p;
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


    printf("The linked list after insertion at the starting\n");
    head=insertionAtFirst(head,52);
    doublyLinkedList(head);

    printf("The linked list after insetion at the end\n");
    head = insertionAtEnd(head,99);
    doublyLinkedList(head);

    printf("The linked list after insertion at any index\n");
    head=insertionAtIndex(head,89,3);
    doublyLinkedList(head);
 
}