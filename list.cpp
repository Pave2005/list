#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void ListCtor (List* list)
{
    list->data = (Elem_list*)calloc (size, sizeof (Elem_list));
    list->data[0] = POISON;
    list->next = (Elem_list*)calloc (size, sizeof (Elem_list));
    list->next[0] = POISON;
    for (int i = 1; i < size; i++)
    {
        list->next[i] = FREE;
    }
}

void ListDtor (List* list)
{
    free (list->data);
    free (list->next);
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
        printf ("%3d ", list->data[i]);
    }
    printf ("\n");
    printf ("NEXT: ");
    for (int i = 0; i < size; i++)
    {
        printf ("%3d ", list->next[i]);
    }
    printf ("\n");
}


void ListPush (List* list, Elem_list num, size_t place)
{
    int i = 0;
    for (; list->next[i] != FREE; i++)
        ;
    list->data[i] = num;
    list->next[i] = place + 1;
    list->next[place] = i;
}
