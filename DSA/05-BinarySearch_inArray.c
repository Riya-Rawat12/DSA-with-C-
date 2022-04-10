#include <stdio.h>

int binarySearch(int arr[], int size, int element){
    int low,mid,high;
    low=0;
    high=size-1;
    mid=(low+high)/2;
    while(low<=high){
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,56,147,201,346,427,458,545,568,3647};
    int size=sizeof(arr)/sizeof(int);
    int element=56;
    int binaryIndex=binarySearch(arr,size,element);
    printf("Element %d is at index %d \n",element,binaryIndex);
return 0;
}