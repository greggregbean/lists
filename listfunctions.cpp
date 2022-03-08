void listSorter(list* lst)
{
    printf("LISTSORTER: \n");

    list sortedlst = {};

    listConstructor(&sortedlst);

    int cell = lst -> head;

    for(int i = 1; i <= lst -> numOfEl; i++)
    {
        (sortedlst.data[i]).num = (lst -> data[cell]).num;

        (sortedlst.data[i]).next = i + 1;

        if(i == lst -> numOfEl)
        {
            (sortedlst.data[i]).next = 0;
        }

        (sortedlst.data[i]).prev = i - 1;

        cell = (lst -> data[cell]).next;
    }

    sortedlst.head = 1;
    sortedlst.tail = lst -> numOfEl;

    *lst = sortedlst;

    listDump(lst);

    printf("\n");
}

void listGraph(FILE* graph, list* lst)
{
    printf("LISTGRAPH: \n");

    fprintf(graph, "digraph \n{\n");

    int next = lst -> head;

    int i = 1;

    while (i <= lst -> numOfEl)
    {
        fprintf(graph, " %d [shape=record, label = \" %d | {Addr: %d| Num: %d| Next: %d| Prev: %d} \" ] \n",
                        i, i, next, (lst -> data[next]).num, (lst -> data[next]).next, (lst -> data[next]).prev);
        next = (lst -> data[next]).next;
        i++;
    }

    i = 1;

    while (i < lst -> numOfEl)
    {
        fprintf(graph," %d -> %d; \n", i, i + 1);
        i++;
    }

    fprintf(graph, "}");

    printf("Graph has been created. Graph in graph.png.\n\n");
}

void listDump(list* lst)
{
    printf("LIST DUMP: \n");

    printf("Free = %d; NumOfEl = %d \nHead = %d; Tail    = %d \n", lst -> free, lst -> numOfEl, lst -> head, lst -> tail);

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
    printf("\n+++ CONSTRUCTION +++\n\n");

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

    printf("\n");
}

int listInsert(list* lst, int afterEl, int val)
{
    printf("LISTINSERT: \n");
    printf("afterEl = %d; Value   = %d \n", afterEl, val);

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
        //Next & Prev for the first inserted cell
        (lst -> data[lst -> free]).next = 0;
        (lst -> data[lst -> free]).prev = 0;
    }

    else
    {
        //Prev for inserted cell
        (lst -> data[lst -> free]).prev = afterEl;
        //Next for inserted cell
        (lst -> data[lst -> free]).next = (lst -> data[afterEl]).next;
        //Next for afterEl
        (lst -> data[afterEl]).next = lst -> free;
        //Case when the elementd is inserted in the end of the list
        if (afterEl + 1 != lst -> free)
            (lst -> data[(lst -> data[lst -> free]).next]).prev = lst -> free;
    }

    if((lst -> data[lst -> free]).next == 0)
        lst -> tail = lst -> free;
    else if((lst -> data[lst -> free]).prev == 0)
        lst -> head = lst -> free;

    lst -> free = newfree;
    (lst -> numOfEl)++;

    listDump(lst);

    printf("\n");

    return NOERROR;
}

int listDelete(list* lst, int afterEl)
{
    printf("LISTDELETE: \n");
    printf("afterEl = %d \n", afterEl);

    assert(lst != NULL);

    if(lst -> numOfEl == 1)
    {
        printf("Now there will be no elements in list. \n");
    }

    else if (lst -> numOfEl == 0)
    {
        printf("There no elements in list! \n\n");
        return ERROR;
    }

    else if ((lst -> data[afterEl]).next < 0)
    {
        printf("You can't delete the element after %d, because it's free! \n\n", afterEl);
        return ERROR;
    }

    // 0 val in free cell
    (lst -> data[(lst -> data[afterEl]).next]).num = 0;
    // Newfree
    int newfree = (lst -> data[afterEl]).next;
    // Prev for cell after deleted
    (lst -> data[(lst -> data[newfree]).next]).prev = (lst -> data[newfree]).prev;
    // Next for afterEl
    (lst -> data[afterEl]).next = (lst -> data[newfree]).next;
    // Next for deleted cell
    (lst -> data[newfree]).next = -(lst -> free);
    // Changing free
    lst -> free = newfree;
    // Prev for free cell
    (lst -> data[newfree]).prev = 0;

    (lst -> numOfEl)--;

    listDump(lst);

    printf("\n");

    return NOERROR;
}

void listDistructor(list* lst)
{
    assert(lst != NULL);

    free(lst -> data);

    lst = nullptr;

    printf("--- DISTRUCTION ---\n\n");
}



