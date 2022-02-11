void listConstructor(list* lst)
{
    assert(lst != NULL);

    lst -> data = (int*) calloc(LENOFDATA, sizeof(int));
    lst -> next = (int*) calloc(LENOFDATA, sizeof(int));
    lst -> prev = (int*) calloc(LENOFDATA, sizeof(int));
}

void listInsert(list* )
