typedef struct
{
    listEl* data
    int free;
    int head;
    int tail;
}list;

typedef struct
{
    int prevEl;
    int nextEl;
    int element;
}listEL;
