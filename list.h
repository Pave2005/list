#ifndef MAIN
#define MAIN

typedef int Elem_list;
const int size = 20;

enum LIST
{
    NULL_ELEM = -8,
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
    Elem_list head;
    Elem_list tail;
};

void Insert (List* list, Elem_list num, size_t end_place);
void ListDtor (List* list);
void ListCtor (List* list);
void ListDump (List* list);
void InsertBefore (List* list, Elem_list num, size_t place_before);
void Delete (List* list, size_t place);

#endif
