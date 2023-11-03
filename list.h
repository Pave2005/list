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

struct ListNode
{
    Elem_list data;
    Elem_list next;
    Elem_list prev;
};

struct List
{
    ListNode* list_elem;
};

void ListDtor (List* list);
void ListCtor (List* list);
void ListDump (List* list);
void ListInsert (List* list, Elem_list num, size_t place);
void ListDel (List* list, size_t place);

#endif
