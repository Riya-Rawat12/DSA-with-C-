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

struct Node*deletionAtFirst(struct Node*head){
    struct Node *ptr = head;
    struct Node*p=head->next;
    ptr=p;
    p->prev=NULL;
    return (ptr);
    
    return head;
}

struct Node * deletionAtEnd(struct Node *head){
    struct Node*ptr=head;
    struct Node*qtr=head->next;
    while(qtr->next!=NULL){
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=NULL;
    free(qtr);
    return head;
}

struct Node*deletionAtIndex(struct Node*head, int index){
    struct Node *ptr=head;
    struct Node* qtr=head->next;
    for(int i=0;i<index-1;i++){
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=qtr->next;
    qtr->prev=NULL;
    free(qtr);
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


    // printf("The linked list after deletion at the starting\n");
    // head=deletionAtFirst(head);
    // doublyLinkedList(head);

    // printf("The linked list after deletion at the end\n");
    // head = deletionAtEnd(head);
    // doublyLinkedList(head);

    printf("The linked list after deletion at any index\n");
    head=deletionAtIndex(head,2);
    doublyLinkedList(head);
 
}