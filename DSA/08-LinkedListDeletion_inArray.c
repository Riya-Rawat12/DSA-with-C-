#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void linkedlist(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;

    }
}

struct Node* deletionAtFirst(struct Node*head){
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    return head;

}

struct Node * deletionAtIndex(struct Node * head, int index){
    struct Node*p=head;
    struct Node*q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
   p->next=q->next;
   free(q);
    return head;
}

struct Node*deletionAtEnd(struct Node*head){
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

struct Node * deletionWithValue(struct Node * head, int value){
    struct Node*p=head;
    struct Node*q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
     if(q->data == value){
        p->next=q->next;
        free(q);
    }
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
    fourth->next=NULL;

        printf("Linked list before deletion\n");
    linkedlist(head);

    // printf("Linked list after deletion at first\n");
    // head=deletionAtFirst(head);
    // linkedlist(head);

    // printf("Linked list after deletion at index\n");
    // head = deletionAtIndex(head,2);
    // linkedlist(head);

    // printf("Linked list after deletion at the end\n");
    // head = deletionAtEnd(head);
    // linkedlist(head);

    printf("Linked list after deletion with value\n");
    head = deletionWithValue(head,45);
    linkedlist(head);
return 0;
}