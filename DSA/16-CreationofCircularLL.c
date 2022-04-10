#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node*next;
};

struct Node*addtoempty(struct Node*tail,int data){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct Node*addatend(struct Node*tail,int data){
    struct Node*temp;
    temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
   temp->next=tail->next;
   tail->next=temp;
   tail=tail->next;
   return tail;
}

struct Node*creatlist(struct Node*tail){
    int n, data, i;

    printf("Enter the no. of nodes\n");
    scanf("%d",&n);

    if(n==0)
    return tail;

    printf("Enter the element of node 1\n");
    scanf("%d",&data);

    for(int i=1;i<n;i++){
        printf("Enter the element for %d \n",i+1);
        scanf("%d",&data);
        tail=addatend(tail,data);
    }
    return tail;
}

void print(struct Node*tail){
    if (tail==NULL)
    printf("No node in the list");
    else{
        struct Node*p=tail->next;
        do{
            printf("%d",p->data);
            p=p->next;
        }while(p!=tail->next);
    }
    printf("\n");
}
int main(){
    struct Node*tail=NULL;
    tail=creatlist(tail);
    print(tail);
    
return 0;
}