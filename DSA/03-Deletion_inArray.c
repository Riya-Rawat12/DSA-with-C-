#include <stdio.h>

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr[], int size, int index){
   
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }
}


int main(){
    int arr[100]={1,2,3,4,5};
    int size=5, element=25, index=2;
    display(arr,size);
    indDeletion(arr,size,index);
    size-=1;
    display(arr,size);
return 0;
}