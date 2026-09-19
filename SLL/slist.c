#ifndef SLIST_C_INCLUDED
#define SLIST_C_INCLUDED

#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<assert.h>
#include "slist.h"

List* slist_new()
    {
        List *list;
        list=(List*)malloc(sizeof(List));
        list->head = NULL;
        list->tail=NULL;
        list->length=0;
        return list;
    }

List* slist_free(List *list)
{
    Node *cur,*p;
    if(slist_length(list)>0)
    {
        assert(list->head && list->tail);
        cur = list->head;
        list->head=NULL;
        list->tail=NULL;
    while(cur!=NULL)
    {
        p=cur;
        cur=cur->next;
        free(p);
        --list->length;
    }
    }
    return list;
}
static Node * _list_node_new(int32_t data)
{
    Node*node = (Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

List* slist_add_head(List *list,int32_t data)
{
    Node *node = _list_node_new(data);
    node->next = list->head;
    list->head = node;

    if(list->tail == NULL)
    {
        list->tail=node;
    }
    ++list->length;

    assert((list->length==1 && list->head == list->tail)||(list->length>0 && list->head!=list->tail));
               return list;
           }
    uint32_t slist_length(const List *list)
    {
        return list->length;
    }
    uint32_t slist_lookup(const List*list,int32_t key)
    {

        Node *node = list->head;
        for(node = list->head;node!=NULL;node=node->next)
        {
            if(node->data==key)break;
        }
        return(node!=NULL);
    }

List* slist_add_tail(List *list,int32_t data)
{
    Node *node = _list_node_new(data);
    if(list->tail!=NULL)
    {
        list->tail->next=node;
        list->tail=node;
    }
    else
    {
        list->head=list->tail=node;
    }
    ++list->length;
    return list;
    }
List* slist_delete_head(List *list)
{
    Node *node;
    if(list->head !=NULL)
    {
        assert(list->length>0);
        node = list->head;
        list->head = list->head->next;
        --list->length;

        if(list->head == NULL)
        {
            list->tail=NULL;
            assert(list->length==0);
        }
        free(node);
    }
    return list;
}




List* slist_delete_tail(List *list)
{
    assert(list!=NULL);
    Node *tail = list->tail;
    Node *node;

    if(list->tail!=NULL)
    {
        assert(list->length>0);
    if(list->tail==list->head)
    {
        list->head=list->tail=NULL;
    }
    else
    {
        for(node=list->head;node->next!=list->tail;node=node->next);

        list->tail=node;
        list->tail->next=NULL;
        free(tail);
    }
    --list->length;
    }
    return list;
}

int32_t slist_smallest(const List *list)
{
    Node *cur = list->head;
    int32_t smallest = cur->data;

    while(cur != NULL)
    {
        if(cur->data < smallest)
        {
            smallest = cur->data;
        }
        cur = cur->next;
    }
    return smallest;
}

int32_t slist_largest(const List *list)
{
    Node *cur = list->head;
    int32_t largest = cur->data;

    while(cur != NULL)
    {
        if(cur->data > largest)
        {
            largest = cur->data;
        }
        cur = cur->next;
    }
    return largest;
}



Node *slist_nth_from_end(List *list, uint32_t n)
{
   Node *fast = list->head;
   Node *slow = list->head;
   uint32_t i;

   if(n==0)
   {
    return NULL;
   }

   for(i=0; i<n; i++)
   {
    if(fast == NULL)
    {
        return NULL;
    }
    fast = fast->next;
   }

   while(fast != NULL)
   {
    fast = fast->next;
    slow = slow->next;
   }
   return slow;
}

//detect cycle

int slist_detect_cycle(List *list)
{
    Node *slow = list->head;
    Node *fast = list->head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return 1; // Cycle detected
        }
    }
    return 0; // No cycle
}

#endif // SLIST_C_INCLUDED
