#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "slist.h"

// Helper function to print the current state of the linked list
void print_list_state(const List *list, const char *operation_name)
{
    printf("\n--- After %s ---\n", operation_name);
    if (list == NULL) {
        printf("List reference is NULL.\n");
        return;
    }
    printf("Total Elements (Length): %u\n", slist_length(list));

    // We print nodes manually assuming Node has a structure containing 'data' and 'next'
    // Adjust the internal structure names if your slist.h uses different naming rules
    printf("Current List Path: ");
    Node *current = list->head;
    if (current == NULL) {
        printf("[Empty List]");
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("==========================================\n");
    printf("      RUNNING LINKED LIST TEST SUITE      \n");
    printf("==========================================\n");

    // 1. Initialization
    List *list = slist_new();
    assert(slist_length(list) == 0);
    print_list_state(list, "Initialization (Empty List)");

    // 2. Add to Head Operations
    printf("\n[Action]: Adding 10 then 20 to Head...\n");
    list = slist_add_head(list, 10);
    list = slist_add_head(list, 20);
    assert(slist_length(list) == 2);
    print_list_state(list, "slist_add_head (10, 20)");

    // 3. Lookup Test
    printf("\n[Action]: Searching for value 20...\n");
    uint32_t found = slist_lookup(list, 20);
    printf("Lookup Result for 20: %s\n", found ? "FOUND (1)" : "NOT FOUND (0)");
    assert(found);

    // 4. Add to Tail Operations
    printf("\n[Action]: Adding 30 then 40 to Tail, and 5 to Head...\n");
    list = slist_add_tail(list, 30);
    list = slist_add_tail(list, 40);
    list = slist_add_head(list, 5);
    assert(slist_length(list) == 5);
    print_list_state(list, "Adding 30, 40 to Tail and 5 to Head");

    // 5. Delete Head Operation
    printf("\n[Action]: Deleting Head Element...\n");
    list = slist_delete_head(list);
    assert(slist_length(list) == 4);
    print_list_state(list, "slist_delete_head");

    // 6. Delete Tail Operation
    printf("\n[Action]: Deleting Tail Element...\n");
    list = slist_delete_tail(list);
    assert(slist_length(list) == 3);
    print_list_state(list, "slist_delete_tail");

    // 7. Core Cleanup
    printf("\n[Action]: Freeing up list resources...\n");
    list = slist_free(list);
    printf("Memory cleared successfully.\n");

    // =========================================================================
    // CRITICAL FIX: Your original code tried to access 'list' after freeing it.
    // To cleanly test edge cases on empty/deleted tracking, we reallocate it.
    // =========================================================================
    printf("\n[Edge Case Setup]: Re-initializing clean sandbox list...\n");
    list = slist_new();
    assert(slist_length(list) == 0);
    print_list_state(list, "Sandbox Reset");

    printf("\n[Action]: Testing Delete Operations on an Empty List...\n");
    list = slist_delete_head(list);
    list = slist_delete_tail(list);
    print_list_state(list, "slist_delete_head & tail on empty list");

    // Final Memory Free
    printf("\n[Action]: Running final memory deallocation...\n");
    list = slist_free(list);

    printf("\n==========================================\n");
    printf("      ALL TESTS AND VERIFICATIONS PASSED  \n");
    printf("==========================================\n");
    return 0;
}
