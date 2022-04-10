void_sorting)struct Node*head)
{
    struct Node*ptr=head;
    struct Node*cpt;
    while(ptr->next!=NULL)
    {
        cpt=ptr->next;
        while(cpt!=null)
        {
            if(ptr->data>cpt->data)
            temp=ptr->data;
            ptr->data=cpt->data;
            cpt->data=temp;
        }
        cpt=cpt->next;
    }
    ptr=ptr->next;
}