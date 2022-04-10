#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node*prev;
    int data;
    struct Node*next;
};

struct Node*addtoempty(struct Node*head,int data){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

struct Node*addatend(struct Node*head,int data){
    struct Node*temp,*tp;
    temp=malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    tp=head;
    while(tp!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
}

struct Node*creatlist(struct Node*head){
    int n, data, i;

    printf("Enter the no. of nodes\n");
    scanf("%d",&n);

    if(n==0)
    return head;

    printf("Enter the element of node 1\n");
    scanf("%d",&data);

    for(int i=1;i<n;i++){
        printf("Enter the element for %d \n",i+1);
        scanf("%d",&data);
        head=addatend(head,data);
    }
    return head;
}
int main(){
    struct Node*head=NULL;
    struct Node*ptr;
    head=creatlist(head);

    ptr=head;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    
return 0;
}