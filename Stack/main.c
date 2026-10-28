#include <assert.h>
#include <stdio.h>
#include "stack.h"

void test_capacity_one_stack()
{
    Stack stk_instance = stack_new(1);
    Stack* stk = &stk_instance;
    StackResult result;

    printf("Testing capacity 1 stack...\n");

    // Initially stack should be empty
    assert(stack_empty(stk));
    assert(!stack_full(stk));

    // Peek empty stack
    stack_peek(stk, &result);
    assert(result.status == STACK_EMPTY);
    printf("Peek empty: STACK_EMPTY\n");

    // Pop empty stack
    stack_pop(stk, &result);
    assert(result.status == STACK_EMPTY);
    printf("Pop empty: STACK_EMPTY\n");

    // Push 99
    stack_push(stk, 99, &result);
    assert(result.status == STACK_OK);
    assert(result.data == 99);
    printf("Push 99: STACK_OK\n");

    assert(!stack_empty(stk));
    assert(stack_full(stk));

    // Try pushing when stack is full
    stack_push(stk, 111, &result);
    assert(result.status == STACK_FULL);
    printf("Push 111: STACK_FULL\n");

    // Peek should still return 99
    stack_peek(stk, &result);
    assert(result.data == 99);
    assert(result.status == STACK_OK);
    printf("Peek: %.2f\n", result.data);

    // Pop 99
    stack_pop(stk, &result);
    assert(result.data == 99);
    assert(result.status == STACK_OK);
    printf("Pop: %.2f\n", result.data);

    assert(stack_empty(stk));

    printf("Capacity 1 test PASSED!\n\n");
}


void test_arbitrary_capacity_stack()
{
    // Passing 0 means use MAX_DEPTH
    Stack stk_instance = stack_new(0);
    Stack* stk = &stk_instance;

    StackResult result = {0, RESULT_INVALID};

    int i;

    printf("Testing MAX_DEPTH stack...\n");

    // Push MAX_DEPTH elements
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_push(stk, i, &result);

        assert(result.status == STACK_OK);
        assert(result.data == i);

        printf("Push: %.2f\n", result.data);

        result.status = RESULT_INVALID;
    }

    // Stack should now be full
    assert(stack_full(stk));

    // Try pushing one more element
    stack_push(stk, i, &result);

    assert(result.status == STACK_FULL);

    printf("Push extra element: STACK_FULL\n");


    // Pop everything
    // Stack follows LIFO:
    // Last In -> First Out
    for (i = MAX_DEPTH - 1; i >= 0; i--)
    {
        stack_pop(stk, &result);

        assert(result.status == STACK_OK);
        assert(result.data == i);

        printf("Pop: %.2f\n", result.data);
    }

    // Stack should now be empty
    assert(stack_empty(stk));

    // Try popping from empty stack
    stack_pop(stk, &result);

    assert(result.status == STACK_EMPTY);

    printf("Pop empty: STACK_EMPTY\n");

    printf("MAX_DEPTH test PASSED!\n\n");
}


int main()
{
    test_capacity_one_stack();

    test_arbitrary_capacity_stack();

    printf("ALL TESTS PASSED!\n");

    return 0;
}