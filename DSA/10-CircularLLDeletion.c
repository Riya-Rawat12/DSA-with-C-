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

struct Node * deletionAtFirst(struct Node * head){
    struct Node*temp=head;
    struct Node*p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=temp->next;
    head=temp->next;
    free(temp);
   
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

struct Node*deletionatLast(struct Node*head){
    struct Node*p=head;
    struct Node*ptr=head->next;
    while(ptr->next!=head){
        p=p->next;
        ptr=ptr->next;
    }
 
    p->next=head;
    free(ptr);
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

    // printf("After deletion at first \n");
    // head = deletionAtFirst(head);
    // circularLinkedList(head);

    // printf("Deletion at any index\n");
    // head=deletionAtIndex(head,2);
    // circularLinkedList(head);

    printf("After deletion at the last\n");
    head=deletionatLast(head);
    circularLinkedList(head);


    return 0;
}