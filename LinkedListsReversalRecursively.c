struct node *recursiveReverseLL(struct node *list)
{
    struct node *revHead;
    if (list == NULL || list->link == NULL)
    {
        return list;
    }

    revHead = recursiveReverseLL(list->link);
    list->link->link = list;
    list->link = NULL; 

    return revHead;
}
