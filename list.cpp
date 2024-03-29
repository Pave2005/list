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
    printf("%3d ", list->list_elem[list->head].data);
    for (int i = list->list_elem[list->head].next; i != 0; i = list->list_elem[i].next)
    {
        printf ("%3d ", list->list_elem[i].data);
    }
    printf ("\n");
}

void ChangingListOfFree (List* list)
{
    list->list_free_elems[list->head_of_free].data = FILLED_ELEM;
    Elem_list pre_head_of_free = list->head_of_free;
    list->head_of_free = list->list_free_elems[list->head_of_free].next;
    list->list_free_elems[pre_head_of_free].next = NO_CONNECTION;
}

void InsertBefore (List* list, int place_before, Elem_list number)
{
    if (place_before < 1 || list->list_elem[place_before].prev == NO_CONNECTION)
    {
        printf ("The element cannot be inserted into this place!\n");
        return;
    }
    // случай, когда вставляется перед первым элементом
    if (place_before == 1)
    {
        list->list_elem[list->head_of_free].data = number;
        list->list_elem[list->head_of_free].next = list->head;
        list->list_elem[list->head_of_free].prev = 0;

        list->list_elem[list->head].prev = list->head_of_free;

        list->head = list->head_of_free;

        list->list_elem[0].next = list->head;

        ChangingListOfFree (list);
        return;
    }
    // случай, когда вставляется перед элемпентом из середины
    list->list_elem[list->head_of_free].data = number;
    list->list_elem[list->head_of_free].next = place_before;
    // prev от того перед которым вставили
    list->list_elem[list->head_of_free].prev = list->list_elem[place_before].prev;

    // меняем next ячейки перед которой вставили
    list->list_elem[list->list_elem[place_before].prev].next = list->head_of_free;
    // меняем prev от места до которого вставили
    list->list_elem[place_before].prev = list->head_of_free;

    // элеменнт в который вставили становится занят
    ChangingListOfFree (list);
}

void InsertAfter (List* list, int place_after, Elem_list number)
{
    if (place_after < 1 || list->list_elem[place_after].prev == NO_CONNECTION)
    {
        printf ("The element cannot be inserted into this place!\n");
        return;
    }

    list->list_elem[list->head_of_free].data = number;
    list->list_elem[list->head_of_free].next = list->list_elem[place_after].next;
    list->list_elem[list->head_of_free].prev = place_after;

    list->list_elem[list->list_elem[place_after].next].prev = list->head_of_free;
    list->list_elem[place_after].next = list->head_of_free;

    ChangingListOfFree (list);
}

void ListPush (List* list, Elem_list number)
{
    list->list_elem[list->head_of_free].data = number;
    list->list_elem[list->head_of_free].next = 0; // так как последний элемент то next 0
    list->list_elem[list->head_of_free].prev = list->tail;
    list->list_elem[list->tail].next = list->head_of_free;
    list->tail = list->head_of_free;

    list->list_elem[0].prev = list->tail;
    if (list->head == 0)
    {
        list->head = 1;
    }

    ChangingListOfFree (list);
}

void Delete (List* list, int place)
{
    if (place < 1 || list->list_elem[place].prev == NO_CONNECTION)
    {
        printf ("There is no such element!\n");
        return;
    }

    list->list_elem[place].data = 0; // изначально все нулями заполняет, то есть пустая ячейка
    // меняется next того после которого удалили
    list->list_elem[list->list_elem[place].prev].next = list->list_elem[place].next;
    // меняется prev того перед которым удалили
    list->list_elem[list->list_elem[place].next].prev = list->list_elem[place].prev;
    list->list_elem[place].next = NO_CONNECTION;
    list->list_elem[place].prev = NO_CONNECTION;

    if (list->list_elem[place].prev == 0)
    {
        list->head = list->list_elem[place].next;
    }

    if (list->list_elem[place].next == 0)
    {
        list->tail = list->list_elem[list->tail].prev;
    }

    list->list_free_elems[place].data = FREE_ELEM;
    list->list_free_elems[place].next = list->head_of_free;
    list->head_of_free = place;
}

void DumpListNode (List* list_node)
{
    FILE* dot = fopen ( "list.dot", "w" );

    fprintf ( dot, "digraph G { \n"
                   "rankdir = LR;\n"
                   "node [shape = record];\n"
                   " 0 " );
    for (int i = 0; i <= list_node->list_elem[0].prev; i++)
    {
        fprintf ( dot, "-> %d", i );
    }
    fprintf ( dot, "[arrowsize = 0.0, weight = 10000, color = \"#FFFFFF\"];\n" );
    for (int i = 0; i <= list_node->list_elem[0].prev; i++)
    {
        fprintf (dot, "%d [shape = Mrecord, style = filled, fillcolor = lightpink "
                      " label = \"%d | data: %d | next: %d | prev: %d\"];\n", i, i, list_node->list_elem[i].data,
                                                                                    list_node->list_elem[i].next,
                                                                                    list_node->list_elem[i].prev);
    }

    for (int i = 0; i <= list_node->list_elem[0].prev; i++)
    {
        fprintf (dot, "%d -> %d;\n", i, list_node->list_elem[i].next);
    }
    fprintf (dot, "}\n");
    fclose (dot);
}

void ListCtor (List* list)
{
    list->list_elem = (ListNode*)calloc (size, sizeof (ListNode));
    list->list_elem[0].data = NULL_ELEM;
    list->head = 0;
    list->tail = 0;

    list->list_elem[0].next = list->head;
    list->list_elem[0].prev = list->tail;
    for (int i = 1; i < size; i++)
    {
        list->list_elem[i].next = NO_CONNECTION;
        list->list_elem[i].prev = NO_CONNECTION;
    }

    list->list_free_elems = (FreeElemsListNode*)calloc (size, sizeof (FreeElemsListNode));
    list->list_free_elems[0].data = NULL_ELEM;
    list->list_free_elems[0].next = 1;
    list->head_of_free = 1;
    for (int i = 1; i < size; i++)
    {
        list->list_free_elems[i].data = FREE_ELEM;
        if (i != size - 1)
        {
            list->list_free_elems[i].next = i + 1;
        }
    }
}

