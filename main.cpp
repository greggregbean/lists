#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>

#include "lists.h"
#include "listfunctions.cpp"

int main()
{
    list lst = {};

    listConstructor(&lst);

    listInsert(&lst, 0, 10);
    listInsert(&lst, 1, 20);
    listInsert(&lst, 2, 30);
    listInsert(&lst, 4, 50);


    return 0;
}
