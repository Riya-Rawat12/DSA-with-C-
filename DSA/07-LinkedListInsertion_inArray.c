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

struct Node* insertAtFirst(struct Node*first, int data){
    struct Node*ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->next=first;
    ptr->data=data;
    return ptr;
}

struct Node*insertAtIndex(struct Node*first, int data, int index){
    struct Node*ptr= (struct Node*)malloc(sizeof(struct Node));
    int i=0;
    struct Node * p=first;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next = ptr;
    return first;
}

struct Node*insertAtEnd(struct Node*first, int data){
    struct Node*ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p=first;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return first;
}

struct Node*insertAfterNode(struct Node*first, struct Node*prevNode ,int data){
    struct Node*ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return first;
}

// struct Node*sorting(struct Node*head)
// {
//     struct Node*ptr=head;
//     struct Node*cpt;
//     int temp;
//     while(ptr->next!=NULL)
//     {
//         cpt=ptr->next;
//         while(cpt!=NULL)
//         {
//             if(ptr->data>cpt->data)
//             temp=ptr->data;
//             ptr->data=cpt->data;
//             cpt->data=temp;
//         }
//         cpt=cpt->next;
//     }
//     ptr=ptr->next;
// }
// int count(struct Node*head)
// {
//     int count=0;
//     while(head!=NULL)
//     {
//         count++;
//         head=head->next;
//     }
//     return count;
// }

// void reverse(struct Node*head)
// {
//     if(head!=NULL)
//     {
//         reverse(head->next);
//         printf("%d ",head->data);
//     }
// }

// int Add(struct Node*head)
// {
//     if(head==NULL)
//     return 0;
//     else 
//     {
//         return Add(head->next)+head->data;
//     }
// }

// int max(struct Node*head)
// {
//     int x=0;
//     if(head==NULL)
//     return 0;
//     x=max(head->next);
//     return x>head->data?x:head->data;
// }

// int min(struct Node*head)
// {
//     int x;
//     if(head==NULL)
//     return 0;
//     x=min(head->next);
    
//         if(x<head->data)
//         return x;
//         else
//         return head->data;
    
// }

// int isSorted(struct Node*head)
// {
//     int x=INT_MIN;
//     while(head!=NULL)
//     {
//         if(head->data<x)
//         return 0;
//         x=head->data;
//         head=head->next;
//     }
//     return 1;
// }

struct Node* Reverse(struct Node*head)
{
    struct Node*current=head;
    struct Node*prev=NULL;
    struct Node*next=NULL;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
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

    first->data=12;
    first->next=second;

    second->data=18;
    second->next=third;

    third->data=67;
    third->next=fourth;

    fourth->data=77;
    fourth->next=NULL;

    printf("Linked list before insertion\n");
    linkedList(first);

    printf("Linked list after insertion at the begining\n");
    first=insertAtFirst(first, 22);
    linkedList(first);

    printf("Linked list after insertion at the middle \n");
    first= insertAtIndex(first,56,2);
    linkedList(first);

    printf("Linked list after insertion at the end\n");
    first = insertAtEnd(first,45);
    linkedList(first);
    
    printf("Linked list insertion after a node\n");
    first = insertAfterNode(first,second,92);
    linkedList(first);

    // printf("linkedlist after sorting\n");0
    // first=sorting(first);
    // linkedList(first);
    // printf("Total no. od nodes are\n");
    // printf("%d\n",count(first));

    // reverse(first);
    // printf("\nsum of the node are %d",Add(first));

    // printf("\nMax element is %d ",max(first));
    // printf("\nMin element is %d ",min(first));

    // printf("\n%d\n",isSorted(first));

    
    struct Node*q;
    printf("Reverse of linkedlist \n");
    Reverse(first);
    linkedList(first);

return 0;
}