#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void ListCtor (List* list)
{
    list->list_elem = (ListNode*)calloc (size, sizeof (ListNode)); // создали массив структур
    list->list_elem[0].data = POISON;
    list->list_elem[0].next = POISON;
    list->list_elem[0].prev = POISON;
    for (int i = 1; i < size; i++)
    {
        list->list_elem[i].next = FREE;
        list->list_elem[i].prev = FREE;
    }
}

void ListDtor (List* list)
{
    free (list->list_elem);
    free (list);
}

void ListDump (List* list)
{
    printf ("ELEM: ");
    for (int i = 0; i < size; i++)
    {
        printf ("%3d ", i);
    }
    printf ("\n");
    printf ("DATA: ");
    for (int i = 0; i < size; i++)
    {
        printf ("%3d ", list->list_elem[i].data);
    }
    printf ("\n");
    printf ("NEXT: ");
    for (int i = 0; i < size; i++)
    {
        printf ("%3d ", list->list_elem[i].next);
    }
    printf ("\n");
    printf ("PREV: ");
    for (int i = 0; i < size; i++)
    {
        printf ("%3d ", list->list_elem[i].prev);
    }
    printf ("\n");
}


void ListInsert (List* list, Elem_list num, size_t place)
{
    int i = 0;
    for (; list->list_elem[i].next != FREE; i++)
        ;
    list->list_elem[i].data = num;
    list->list_elem[i].next = place + 1;
    list->list_elem[place].next = i;
    list->list_elem[place + 1].prev = i;
    list->list_elem[i].prev = place;
}

void ListDel (List* list, size_t place)
{
    list->list_elem[list->list_elem[place - 2].next].data = 0;
    list->list_elem[place - 2].next = list->list_elem[place - 1].next;
    list->list_elem[place - 1].next = FREE;
    list->list_elem[place].prev = list->list_elem[place - 1].prev;
    list->list_elem[place - 1].prev = FREE;
}
