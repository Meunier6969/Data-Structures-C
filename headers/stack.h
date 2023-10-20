#pragma once

// LAST IN FIRST OUT
#define STACK_MAX_SIZE 50

typedef struct stk_list
{
    float* values;
    int numberOfElements;
} stk_list;

stk_list STK_createEmptyStack();

int STK_isEmptyStack(stk_list stack);
int STK_isFullStack(stk_list stack);
void STK_stack(stk_list *stack, float value);
float STK_unstack(stk_list *stack);

void STK_displayList(stk_list stack);