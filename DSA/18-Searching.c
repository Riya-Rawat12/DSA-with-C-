#include <stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node*next;
};

void LinkedList(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node*searching(struct Node*head,int element){
    int index=0;
    struct Node*ptr=head;
    while(ptr->data!=element){
        ptr=ptr->next;
        index++;
    }
    printf("Element is at %d index\n",index);
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

    head->data=56;
    head->next=second;

    second->data=67;
    second->next=third;

    third->data=76;
    third->next=fourth;

    fourth->data=88;
    fourth->next=NULL;

    LinkedList(head);
    head=searching(head,67);
    return 0;
}