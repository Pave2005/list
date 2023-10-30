#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main ()
{
    List list = {};
    ListCtor (&list);

    for (int i = 1; i <= 8; i++)
        list.data[i] = i*10;

    for (int i = 1; list.data[i] != 0; i++)
    {
        if (list.data[i + 1] != 0)
        {
            list.next[i] = i + 1;
        }
        else
            list.next[i] = END;
        list.prev[i] = i - 1;
    }

    ListPush (&list, 22, 3);
    ListDel (&list, 4);
    ListDump (&list);
    ListCtor (&list);
}
