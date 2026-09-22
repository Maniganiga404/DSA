#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "slist.h"


void test()
{
    // Create a new empty list
    List *list = slist_new();

  
    // Add elements at Head
    

    slist_add_head(list, 67);
    slist_add_head(list, 33);
    slist_add_head(list, 54);
    slist_add_head(list, 90);
    slist_add_head(list, 21);

    // List should contain 5 elements
    assert(slist_length(list) == 5);

    // Test lookup
    assert(slist_lookup(list, 67) == 1);
    assert(slist_lookup(list, 100) == 0);

    
    // Add elements at Tail
    
    slist_add_tail(list, 5);
    slist_add_tail(list, 1);
    slist_add_tail(list, 8);

    
    assert(slist_length(list) == 8);

    
    // Find Smallest Element
    

    int32_t smallest = slist_smallest(list);

    printf("Smallest element: %d\n", smallest);

    assert(smallest == 1);

    
    // Find Largest Element
    

    int32_t largest = slist_largest(list);

    printf("Largest element: %d\n", largest);

    assert(largest == 90);

    
    // Delete Head
    

    slist_delete_head(list);
    slist_delete_head(list);

    // 8 - 2 = 6
    assert(slist_length(list) == 6);

    // Delete Tail
    

    slist_delete_tail(list);
    slist_delete_tail(list);

    // 6 - 2 = 4
    assert(slist_length(list) == 4);

    
    // Free List
   

    list = slist_free(list);

    printf("\nAll tests passed successfully!\n");


    // Test nth node from end
    // Test nth node from end
    List *nth_list = slist_new();

    slist_add_head(nth_list, 10);
    slist_add_head(nth_list, 20);
    slist_add_head(nth_list, 30);

    Node *result = slist_nth_from_end(nth_list, 3);

    if (result != NULL)
        printf("3rd node from end: %d\n", result->data);

    slist_free(nth_list);



    //Detect a cycle
    List *cycle_list = slist_new();
    slist_add_head(cycle_list, 1);
    slist_add_head(cycle_list, 2);
    slist_add_head(cycle_list, 3);

    // Test cycle detection
    assert(slist_detect_cycle(cycle_list) == 0); // No cycle detected
    printf("No cycle detected in the list.\n");

    // Reverse a list
    List *reverse_list = slist_new();

    slist_add_head(reverse_list, 10);
    slist_add_head(reverse_list, 20);
    slist_add_head(reverse_list, 30);

    slist_reverse(reverse_list);

    // Check reversed head and tail
    assert(reverse_list->head->data == 10);
    assert(reverse_list->tail->data == 30);

    printf("List reversed successfully.\n");

    reverse_list = slist_free(reverse_list);



    //Delete Duplicates

    // Delete duplicates
{
    List *list = slist_new();

    slist_add_tail(list, 10);
    slist_add_tail(list, 20);
    slist_add_tail(list, 30);
    slist_add_tail(list, 20);
    slist_add_tail(list, 40);
    slist_add_tail(list, 10);

    slist_delete_duplicates(list);

    // Check the remaining nodes
    assert(list->length == 4);
    assert(list->head->data == 10);
    assert(list->tail->data == 40);

    // Display the list
    Node *temp = list->head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\nDuplicates deleted successfully.\n");

    list = slist_free(list);
}

}


int main()
{
    test();

    return 0;
}