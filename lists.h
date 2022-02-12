// --- LISTS ---

#define LISTSIZE 10
#define ERROR 1
#define NOERROR 0

typedef struct
{
    int prev;
    int next;
    int num;
}listEl;

typedef struct
{
    listEl* data;
    int numOfEl;
    int free;
    int head;
    int tail;
}list;

void listConstructor(list* lst);
void listDump(list* lst);
int listInsert(list* lst, int cell, int val);
void listDelete(list* lst, int cell);

