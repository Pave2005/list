#ifndef MAIN
#define MAIN

#include "../stack/stack_cd.h"

typedef int Elem_list;
const int size = 20;

enum COMMAND
{
    LIST = 1,
    FREE = 0,
};

enum LIST_ERRORS
{
    INCORRECT_PLACE = 0, // realloc, loop, connections
};

enum LIST
{
    NULL_ELEM = -8,

    FREE_ELEM = 0,
    FILLED_ELEM = 1,

    NO_CONNECTION = -1,
};

struct ListNode
{
    Elem_list data;
    Elem_list next;
    Elem_list prev;
};

struct FreeElemsListNode
{
    Elem_list data;
    Elem_list next;
};

struct List
{
    ListNode* list_elem;
    Elem_list head;
    Elem_list tail;

    FreeElemsListNode* list_free_elems;
    Elem_list head_of_free;
};

void InsertAfter (List* list, int place_after, Elem_list number);
void ChangingListOfFree (List* list);
void DumpListNode(List* list_node);
void ListPush (List* list, Elem_list num);
void ListDtor (List* list);
void ListCtor (List* list);
void ListDump (List* list);
void InsertBefore (List* list, int place_before, Elem_list number);
void Delete (List* list, int place);

#endif
