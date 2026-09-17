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

    printf("\nAll Day 4 tests passed successfully!\n");
}

int main()
{
    test();

    return 0;
}