#include <stdint.h>
#include <stdbool.h>

typedef struct _node_ Node;
typedef struct _dlist_ List;

struct _dlist_ {
    Node *head;
    Node *tail;
    uint32_t length;
};

struct _node_ {
    uint32_t data;
    Node *next;
    Node *prev;
};

List *dlist_new();

List *dlist_free(List *list);

List *dlist_add_head(List *list, uint32_t data);
List *dlist_add_tail(List *list, uint32_t data);

List *dlist_delete_head(List *list);
List *dlist_delete_tail(List *list);

//void dlist_display(List *list);