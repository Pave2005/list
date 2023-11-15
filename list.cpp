#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "../stack/stack_cd.h"

void ListDtor (List* list)
{
    free (list->list_elem);
    list->head = 0;
    list->tail = 0;
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
    printf ("LIST: ");
    printf ("%3d ", list->list_elem[1].data);
    int counter = 1;
    for (int i = 1; i < list->tail; i++)
    {
        if (list->list_elem[counter].next != 0)
        {
            printf ("%3d ", list->list_elem[list->list_elem[counter].next].data);
            counter = list->list_elem[counter].next;
        }
        else
            break;
    }
    printf ("\n");
}


void InsertBefore (List* list, Elem_list num, size_t place_before)
{
    list->list_elem[list->tail].data = num;

    list->list_elem[list->tail].next = list->list_elem[place_before - 1].next;
    list->list_elem[place_before - 1].next = list->tail;

    list->list_elem[list->tail].prev = list->list_elem[place_before].prev;
    list->list_elem[place_before].prev = list->tail;
    list->tail++;
    list->list_elem[0].prev = list->tail;

    list->returned_place = place_before;
}

void Insert (List* list, Elem_list num, size_t end_place)
{
    list->list_elem[list->tail].data = num;

    list->list_elem[list->tail - 1].next = list->tail;

    list->list_elem[list->tail].prev = list->tail - 1;

    list->tail++;
    list->list_elem[0].prev = list->tail;
}

void Delete (List* list, size_t place_before)
{
    list->list_elem[list->list_elem[place_before].prev].data = 0;

    size_t tmp_next = list->list_elem[place_before - 1].next;
    list->list_elem[place_before - 1].next = list->list_elem[list->list_elem[place_before - 1].next].next;
    list->list_elem[tmp_next].next = 0;

    size_t tmp_prev = list->list_elem[place_before].prev;
    list->list_elem[place_before].prev = list->list_elem[list->list_elem[place_before].prev].prev;
    list->list_elem[tmp_prev].prev = 0;

    list->tail--;
    list->list_elem[0].prev = list->tail;
}

// &
// void DumpListNode(ListNode* list_node)
// {
//      fprintf(FILE*, "node_%p\n", list_node);
// }
//
// node_12512452 [label="10"]
// node_12415234 [label="5"]
// node_12512452[next] -> node_12415234
// node_12415234[prev] -> node_12512452
//

// ptr = "Is this a man?"
// sprintf(buffer, "say \"%s\"", ptr);

// system(buffer)

void ListCtor (List* list)
{
    list->list_elem = (ListNode*)calloc (size, sizeof (ListNode));
    list->list_elem[0].data = NULL_ELEM;
    list->head = 1;
    list->tail = 1;
    list->count_of_calls = 0;
    list->returned_place = 0;

    list->list_elem[0].next = list->head;
    list->list_elem[0].prev = list->tail;
}
