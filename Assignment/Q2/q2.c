
#include <stdio.h>
#include <assert.h>
#include "q2.h"

static void _set_stack_result_(
    StackResult *stack_result,
    float data,
    uint32_t status
)
{
    stack_result->data = data;
    stack_result->status = status;
}

Stack stack_new(uint32_t size)
{
    size = (size > 0 && size <= MAX_DEPTH)
           ? size : MAX_DEPTH;

    Stack stack = {size, -1, {0}};
    return stack;
}

Stack *stack_push(
    Stack *stack,
    float data,
    StackResult *stack_result
)
{
    assert(stack != NULL);
    assert(stack_result != NULL);

    if (stack->top + 1 < stack->size)
    {
        stack->stk[++stack->top] = data;
        _set_stack_result_(stack_result, data, STACK_OK);
    }
    else
    {
        _set_stack_result_(stack_result, data, STACK_FULL);
    }

    return stack;
}

Stack *stack_pop(Stack *stack, StackResult *stack_result)
{
    assert(stack != NULL);
    assert(stack_result != NULL);

    if (stack->top > -1)
    {
        _set_stack_result_(
            stack_result,
            stack->stk[stack->top],
            STACK_OK
        );

        --stack->top;
    }
    else
    {
        _set_stack_result_(
            stack_result,
            RESULT_INVALID,
            STACK_EMPTY
        );
    }

    return stack;
}

Stack *stack_peek(
    const Stack *stack,
    StackResult *stack_result
)
{
    assert(stack != NULL);
    assert(stack_result != NULL);

    if (stack->top > -1)
    {
        _set_stack_result_(
            stack_result,
            stack->stk[stack->top],
            STACK_OK
        );
    }
    else
    {
        _set_stack_result_(
            stack_result,
            RESULT_INVALID,
            STACK_EMPTY
        );
    }

    return (Stack *)stack;
}

void stack_display(
    const Stack *stack,
    StackResult *stackResult
)
{
    assert(stack != NULL);
    assert(stackResult != NULL);

    if (stack->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    for (int32_t i = stack->top; i >= 0; i--)
    {
        printf("%.0f", stack->stk[i]);

        if (i == stack->top)
        {
            printf(" <-- TOP");
        }

        printf("\n");
    }
}

Stack *stack_display_key(
    Stack *stack,
    uint32_t key,
    StackResult *StackResult
)
{
    assert(stack != NULL);
    assert(StackResult != NULL);

    for (int32_t i = stack->top; i >= 0; i--)
    {
        if (stack->stk[i] == (float)key)
        {
            printf("Found key: %.0f\n", stack->stk[i]);

            StackResult->data = stack->stk[i];
            StackResult->status = STACK_OK;

            return stack;
        }
    }

    printf("Key %u not found\n", key);

    StackResult->data = 0;
    StackResult->status = RESULT_INVALID;

    return stack;
}

Stack *stack_clear(Stack *stack, StackResult *StackResult)
{
    assert(stack != NULL);
    assert(StackResult != NULL);

    stack->top = -1;

    StackResult->data = 0;
    StackResult->status = STACK_OK;

    return stack;
}
