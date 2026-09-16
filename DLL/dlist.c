#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

static Node *_new_node_(uint32_t data)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

List *dlist_new()
{
    List *list = (List *)malloc(sizeof(List));

    if (list == NULL)
    {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

List *dlist_free(List *list)
{
    if (list == NULL)
    {
        return NULL;
    }

    Node *temp;

    while (list->head != NULL)
    {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }

    list->tail = NULL;
    list->length = 0;

    return list;
}

List *dlist_add_head(List *list, uint32_t data)
{
    if (list == NULL)
    {
        return NULL;
    }

    Node *node = _new_node_(data);

    if (node == NULL)
    {
        return NULL;
    }

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    ++list->length;

    return list;
}

List *dlist_add_tail(List *list, uint32_t data)
{
    if (list == NULL)
    {
        return NULL;
    }

    Node *node = _new_node_(data);

    if (node == NULL)
    {
        return NULL;
    }

    if (list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }

    ++list->length;

    return list;
}

List *dlist_delete_head(List *list)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (list->head == NULL)
    {
        return list;
    }

    Node *temp = list->head;

    list->head = list->head->next;

    if (list->head != NULL)
    {
        list->head->prev = NULL;
    }
    else
    {
        list->tail = NULL;
    }

    free(temp);

    --list->length;

    return list;
}

List *dlist_delete_tail(List *list)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (list->tail == NULL)
    {
        return list;
    }

    Node *temp = list->tail;

    list->tail = list->tail->prev;

    if (list->tail != NULL)
    {
        list->tail->next = NULL;
    }
    else
    {
        list->head = NULL;
    }

    free(temp);

    --list->length;

    return list;
}