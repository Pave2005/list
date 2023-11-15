#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main ()
{
    List list = {};
    ListCtor (&list);

    Insert (&list, 1, 1);
    Insert (&list, 2, 2);
    Insert (&list, 3, 3);
    Insert (&list, 4, 4);
    Insert (&list, 5, 5);
    InsertBefore (&list, 10, 3);
    InsertBefore (&list, 11, 3);
    Delete (&list, 3);

    ListDump (&list);
    ListCtor (&list);
}
