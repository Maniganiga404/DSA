#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include<stdio.h>
#include<stddef.h>
#include<stdint.h>

typedef struct _node_ Node;
typedef struct _slist_ List;
struct _slist_{
                Node *head;
                Node *tail;
                uint32_t length;
};

struct _node_{
                int32_t data;
                Node *next;
};

/* The public interface of the ADT */

List *slist_new();
List *slist_free(List*);

uint32_t slist_length(const List *list);
uint32_t slist_lookup(const List *list, int32_t key);

List* slist_add_head(List *list,int32_t data);
List* slist_add_tail(List *list,int32_t key);

List* slist_delete_head(List *list);
List* slist_delete_tail(List *list);

//smallest and largest
int32_t slist_smallest(const List *list);
int32_t slist_largest(const List *list);

//nth node from end
Node *slist_nth_from_end(List *list, uint32_t n);

//Detect a cycle
int slist_detect_cycle(List *list);

#endif // SLIST_H_INCLUDED
