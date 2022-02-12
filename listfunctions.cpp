void listDump(list* lst)
{
    printf("LIST DUMP: \n");

    printf("Free = %d \n", lst -> free);

    printf("     ");

    for(int i = 0; i < LISTSIZE; i++)
    {
        printf("[%03d] ", i);
    }

    printf("\nNum  ");

    for(int i = 0; i < LISTSIZE; i++)
    {
        printf("[%03d] ", (lst -> data[i]).num);
    }

    printf("\nNext ");

    for(int i = 0; i < LISTSIZE; i++)
    {
        printf("[%03d] ", (lst -> data[i]).next);
    }

    printf("\nPrev ");

    for(int i = 0; i < LISTSIZE; i++)
    {
        printf("[%03d] ", (lst -> data[i]).prev);
    }

    printf("\n");
}

void listConstructor(list* lst)
{
    printf("--- CONSTRUCTION STARTED  ---\n");

    assert(lst != NULL);

    lst -> data = (listEl*) calloc(LISTSIZE, sizeof(listEl));

    (lst -> data[0]).next = 0;
    for(int i = 1; i < LISTSIZE - 1; i++)
    {
        (lst -> data[i]).next = -(i+1);
    }
    (lst -> data[LISTSIZE - 1]).next = 0;

    lst -> free = 1;
    lst -> head = 1;
    lst -> tail = 1;
    lst -> numOfEl = 0;

    listDump(lst);

    printf("--- CONSTRUCTION FINISHED ---\n\n");
}

int listInsert(list* lst, int afterEl, int val)
{
    printf("LISTINSERT: \n");
    printf("afterEl = %d; Val = %d \n", afterEl, val);

    assert(lst != NULL);

    if(afterEl > (lst -> numOfEl))
    {
        printf("You can't put %d after %d position, because last poistion in list is %d! \n", val, afterEl, lst -> numOfEl);
        return ERROR;
    }

    printf("OldFree = %d; ", lst -> free);

    int newfree = abs(lst -> data[lst -> free].next);
    printf("NewFree = %d \n", newfree);

    (lst -> data[lst -> free]).num = val;

    if(lst -> numOfEl == 0)
    {
        (lst -> data[lst -> free]).next = 0;
        (lst -> data[lst -> free]).prev = 0;
    }

    else
    {
        (lst -> data[lst -> free]).prev = afterEl;
        (lst -> data[lst -> free]).next = (lst -> data[afterEl]).next;
        (lst -> data[afterEl]).next = lst -> free;
        if (afterEl + 1 != lst -> free)
            (lst -> data[(lst -> data[lst -> free]).next]).prev = lst -> free;
    }

    lst -> free = newfree;
    (lst -> numOfEl)++;

    listDump(lst);

    printf("\n");

    return NOERROR;
}

int ListDelete(list* lst, int afterEl)
{
    printf("LISTDELETE: \n");
    printf("afterEl = %d \n", afterEl);

    assert(lst != NULL);

    if(lst -> numOfEl == 1)
    {
        printf("Now there will be no elements in list. \n");
    }

    else(lst -> numOfEl == 0)
    {
        printf("There no elements in list! \n");
        return ERROR;
    }

    lst -> data[(lst -> data[afterEl]).next] = 0;

    (lst -> data[lst -> free]).next = -(lst -> data[afterEl]).next;

    (lst -> data[afterEl]).next = (lst -> data[(lst -> data[afterEl]).next]).next;
    (lst -> data[(lst -> data[(lst -> data[afterEl]).next]).next]).prev = (lst -> data[(lst -> data[afterEl]).next]).prev;

    (lst -> data[(lst -> data[afterEl]).next]).prev = 0;
    (lst -> data[(lst -> data[afterEl]).next]).next = 0;







    (lst -> numOfEl)--;
}

/*void listDelete(list* lst, int afterEl)
{}*/
