#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main ()
{
    List list = {};
    ListCtor (&list);

    for (int i = 1; i <= 8; i++)
        list.list_elem[i].data = i * 10;

    for (int i = 1; list.list_elem[i].data != 0; i++)
    {
        if (list.list_elem[i + 1].data != 0)
        {
            list.list_elem[i].next = i + 1;
        }
        else
            list.list_elem[i].next = END;
        list.list_elem[i].prev = i - 1;
    }

    ListInsert (&list, 22, 3);
    ListDel (&list, 4);
    ListDump (&list);
    ListCtor (&list);
}
