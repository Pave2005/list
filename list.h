#ifndef MAIN
#define MAIN

typedef int Elem_list;
const int size = 20;

enum LIST
{
    POISON = -2,
    END = 0,
    FREE = -1,
};

struct List
{
    Elem_list* data;
    Elem_list* next;
    Elem_list* prev;
};

void ListDtor (List* list);
void ListCtor (List* list);
void ListDump (List* list);
void ListPush (List* list, Elem_list num, size_t place);
void ListDel (List* list, size_t place);

#endif
