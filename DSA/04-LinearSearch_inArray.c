#include <stdio.h>

int linearSearch(int arr[], int size, int element){
for(int i=0;i<size;i++){
   if(arr[i]==element){
    return i;}
}
return -1;
}
int main(){
    int arr[]={1,56,47,2,46,27,58,245,68,3647};
    int size=sizeof(arr)/sizeof(int);
    int element=46;
    int searchIndex=linearSearch(arr,size,element);
    printf("Element %d is at index %d \n",element,searchIndex);
return 0;
}