#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*push(struct Node*head,int val){
    struct Node*new=malloc(sizeof(struct Node));
    new->data=val;
    new->next=head;
    head=new;
    return head;
}

struct Node*add(struct Node*head1,struct Node*head2){

    if(head1->data==0)
    return head2;
    if(head2->data==0)
    return head1;

    struct Node*ptr1=head1;
    struct Node*ptr2=head2;
    struct Node*head3=NULL;
    int carry=0,sum=0;

    while(ptr1!=NULL || ptr2!=NULL){
        sum=0;
        if(ptr1!=NULL)
        sum+=ptr1->data;
        if(ptr2!=NULL)
        sum+=ptr2->data;
        sum+=carry;
        carry=sum/10;
        sum=sum%10;

        head3=push(head3,sum);

        if(ptr1!=NULL)
        ptr1=ptr1->next;
        if(ptr2!=NULL)
        ptr2=ptr2->next;
    }
    if(carry!=0)
    head3=push(head3,carry);
    return head3;
}
struct Node*reversedLL(struct Node*head){
    if(head==NULL)
    return head;

    struct Node*current=NULL;
    struct Node*agla=head->next;
    head->next=NULL;

    while(agla!=NULL){
        current=agla;
        agla=agla->next;
        current->next=head;
        head=current;
    }
    return head;
}
struct Node*add_node(struct Node*head,int val){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=NULL;

    temp->next=head;
    head=temp;
    return head;
}

struct Node*create(struct Node*head,int n){
    while (n!=0)
    {
        head=add_node(head,n%10);
        n=n/10;
    }
    return head;
}

void print(struct Node*head){
    struct Node*ptr=head;
    if(head==NULL){
    printf("No num");
    }
    else{
        while(ptr->next!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
}

void backtonum(struct Node*head){
    struct Node*temp=head;
    printf("\nResult= ");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    return;
}

int main(){
    int a,b;
    printf("Enter the two numbers: ");
    scanf("%d%d",&a,&b);

    struct Node*head1=NULL;
    printf("Linked list representation of first number\n");
    head1=create(head1,a);
    print(head1);

    struct Node*head2=NULL;
    printf("\nLinked list representation of second number\n");
    head2=create(head2,b);
    print(head2);

    printf("\nReversal of first linked lists\n");
    head1=reversedLL(head1);
    print(head1);
    printf("\nReversal of second linked list\n");
    head2=reversedLL(head2);
    print(head2);

    struct Node*head3=NULL;
    head3=add(head1,head2);
    printf("\nResultant linked list is\n");
    print(head3);

    backtonum(head3);

return 0;
}