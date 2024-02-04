#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main ()
{
    List list = {};
    ListCtor (&list);
    ListPush (&list, 1);
    ListPush (&list, 2);
    ListPush (&list, 3);
    ListPush (&list, 4);
    ListPush (&list, 5);
    InsertBefore (&list, 1, 33);
    Delete (&list, 1);
    InsertBefore (&list, 2, 1);
    ListPush (&list, 6);
    Delete (&list, 2);
    InsertAfter (&list, 1, 22);

    DumpListNode(&list);
    ListDump (&list);
    system ("dot -T png list.dot -o pctr.png");
    ListCtor (&list);
}
