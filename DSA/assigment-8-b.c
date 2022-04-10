#include <stdio.h>
typedef struct block
{
    int val;
    int prio;
} block;
void insert(block *q, int size, int *rare)
{
    int val, p;
    if (*rare < size)
    {
        (*rare)++;
        printf("Enter the val and Priority  : ");
        scanf("%d %d", &(q[*rare].val), &q[*rare].prio);
    }
}
void delete (block *q, int size, int *rare)
{
    int min_pri_index = 0;
    for (int i = 0; i <= *rare; i++)
    {
        if (q[min_pri_index].prio > q[i].prio)
            min_pri_index = i;
    }
   for (int i = min_pri_index; i < *rare; i++)
    {
        q[i].val = q[i + 1].val;
        q[i].prio = q[i + 1].prio;
    }
    (*rare)--;
}

void display(block *q, int rare)
{
    printf("Val  in Queue : ");
    for (int i = 0; i <= rare; i++)
    {
        printf("%d ", q[i].val);
    }
    printf("\nPrio in Queue : ");
    for (int i = 0; i <= rare; i++)
    {
        printf("%d ", q[i].prio);
    }
    printf("\n");
}
int main()
{
    printf("Riya Rawat\nSec-E\nStudent ID-20012105\n");
    int n, choice;
    int rare;
    rare = -1;
    printf("Enter the size of the queue  :  ");
    scanf("%d", &n);
    block q[n];
    printf("Press 1 to insert\nPress 2 to Delete\nPress 3 to display\nPress 0 to exit\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            insert(q, n, &rare);
            break;
        case 2:
            delete (q, n, &rare);
            break;
        case 3:
            display(q, rare);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid Choice ");
        }
        printf("\nEnter the choice : ");
        scanf("%d", &choice);
    }

    return 0;
}