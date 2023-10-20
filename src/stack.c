#include <stdlib.h>
#include <stdio.h>

#include "../headers/stack.h"

stk_list STK_createEmptyStack()
{
    stk_list newStack;

    newStack.values = (float*) malloc(STACK_MAX_SIZE * sizeof(float));
    newStack.numberOfElements = 0;
    
    return newStack;
}

int STK_isEmptyStack(stk_list stack)
{
    return stack.numberOfElements == 0;
}

int STK_isFullStack(stk_list stack)
{
    return stack.numberOfElements == STACK_MAX_SIZE;
}

void STK_stack(stk_list *stack, float value)
{
    if (STK_isFullStack(*stack))
    {
        printf("cannot stack on a full stack\n");
        return;
    }

    printf("stacking %f\n", value);

    stack->values[stack->numberOfElements] = value;
    stack->numberOfElements++;
}

float STK_unstack(stk_list *stack)
{
    if (STK_isEmptyStack(*stack))
    {
        printf("cannot unstack on an empty stack\n");
        return 0;
    }

    float toDelete = stack->values[stack->numberOfElements-1];
    printf("unstacking %f\n", toDelete);

    stack->values[stack->numberOfElements-1] = 0;
    stack->numberOfElements--;

    return toDelete;
}

void STK_displayList(stk_list stk)
{
    if (stk.numberOfElements == 0)
    {
        printf("stack [empty]\n");
        return;
    }

    printf("stack [");
    for (int i = 0; i < stk.numberOfElements; i++)
    {
        if (i != 0) printf(" : ");
        printf("%f", stk.values[i]);
    }
    printf("]\n");

}