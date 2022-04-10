#include <stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int t_size, int u_size){
    a->total_size=t_size;
    a->used_size=u_size;
    a->ptr=(int*)malloc(t_size*sizeof(int));
}

void show(struct myArray*a){
    for(int i=0;i<a->used_size;i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}
    void setVal(struct myArray*a){
        int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("Enter the element %d ",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
int main(){
    
    struct myArray marks;
    createArray(&marks,10,4);
    printf("Running setVal\n");
    setVal(&marks);
    printf("Running show\n");
    show(&marks);
return 0;
}