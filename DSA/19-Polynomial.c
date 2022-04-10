#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coeff;
    int expo;
    struct Node *next;
};


struct Node *insert(struct Node *head, float coe, int exp)
{
    struct Node *ptr = head;
    struct Node *poly = malloc(sizeof(struct Node));
    poly->coeff = coe;
    poly->expo = exp;
    poly->next = NULL;

    if (head == NULL || exp >= head->expo)
    {
        poly->next = head;
        head = poly;
    }
    else
    {
        while (ptr->next != NULL && ptr->next->expo >= exp){
            ptr = ptr->next;}
        poly->next = ptr->next;
        ptr->next = poly;
    }
    return head;
}

struct Node *create(struct Node *head)
{
    int n, i;
    float coeff;
    int expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coffecient for term %d: ", i + 1);
        scanf("%f", &coeff);

        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
}

void print(struct Node *head)
{
    if (head == NULL)
        printf("No polynomial exist");
        
    else
    {
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            printf("(%0.1fx^%d)", ptr->coeff, ptr->expo);
            ptr = ptr->next;
            if (ptr != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

int main()
{

    struct Node *head = NULL;
    printf("Enter the polynomial\n");
    head = create(head);
    print(head);

    return 0;
}