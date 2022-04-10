#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void LinkedList(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node*sorting(struct Node*head,int data){
    struct Node*ptr=head;
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL||temp->data<ptr->data){
        temp->next=head;
        head=temp;
    }
    else{
    while(ptr->next!=NULL && ptr->next->data<temp->data){
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    }
    return head;
}
int main(){
   struct Node*head;
   struct Node*second;
   struct Node*third;
   struct Node*fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=67;
    head->next=second;

    second->data=56;
    second->next=third;

    third->data=78;
    third->next=fourth;

    fourth->data=99;
    fourth->next=NULL;

    LinkedList(head);
    head=sorting(head,102);
    LinkedList(head);
return 0;
}