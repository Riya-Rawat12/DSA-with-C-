// #include <stdio.h>
// #include<stdlib.h>

// struct Node{
//     int data;
//     struct Node*next;
// };

// struct Node*createanode(int data){
//     struct Node*temp=malloc(sizeof(struct Node));
//     temp->data=data;
//     temp->next=temp;
//     return temp;
// }
// int main(){
//     struct Node*tail;
//     int data=56;

//     tail=createanode(data);

//     printf("%d\n",tail->data);
//     return 0;
    
// return 0;
// }

#include <stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
};

struct Node*createanode(int data){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->prev=temp;
    temp->next=temp;
    return temp;
}
int main(){
    struct Node*tail;
    int data=56;

    tail=createanode(data);

    printf("%d\n",tail->data);
    return 0;
    
return 0;
}