#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>

#include "lists.h"
#include "listfunctions.cpp"

FILE* graph = fopen("graph.dot", "w");

int main()
{
    list lst = {};

    listConstructor(&lst);

    listInsert(&lst, 0, 10);
    listInsert(&lst, 1, 20);
    listInsert(&lst, 2, 30);
    listInsert(&lst, 1, 40);
    listDelete(&lst, 5);

    listGraph(graph, &lst);

    listSorter(&lst);

    //listDistructor(&lst);

    return 0;
}
