#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"

void test_dlist()
{
    List *list = dlist_new();

    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(list->length == 0);

    //dlist_display(list);

    // add_head

    dlist_add_head(list, 67);
    dlist_add_head(list, 29);
    dlist_add_head(list, 25);
    dlist_add_head(list, 1);

    assert(list->head->data == 1);
    assert(list->tail->data == 67);
    assert(list->length == 4);

    //dlist_display(list);

    // add_tail

    dlist_add_tail(list, 420);
    dlist_add_tail(list, 747);
    dlist_add_tail(list, 911);

    assert(list->tail->data == 911);
    assert(list->tail->prev->data == 747);
    assert(list->length == 7);

    //dlist_display(list);

    // delete_head

    dlist_delete_head(list);

    assert(list->head->data == 25);
    assert(list->length == 6);

    //dlist_display(list);

    // delete_tail

    dlist_delete_tail(list);

    assert(list->tail->data == 747);
    assert(list->length == 5);

    //dlist_display(list);
}

int main()
{
    test_dlist();
    printf("All tests passed!\n");

    return 0;
}