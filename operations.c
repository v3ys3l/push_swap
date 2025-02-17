
#include "push_swap.h"

void stack_push(t_stack *stack, int value)
{
    if (is_full(stack))
        error_exit();
    stack->array[++stack->top] = value;
}

int stack_pop(t_stack *stack)
{
    if (is_empty(stack))
        error_exit();
    return stack->array[stack->top--];
}

void sa(t_stack *a)
{
    int temp;
    
    if (a->top < 1)  // En az 2 eleman olmalı
        return;
        
    temp = a->array[a->top];
    a->array[a->top] = a->array[a->top - 1];
    a->array[a->top - 1] = temp;
    
    write(1, "sa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    if (is_empty(a) || is_full(b))
        return;
        
    stack_push(b, stack_pop(a));
    write(1, "pb\n", 3);
}

void ra(t_stack *a)
{
    int temp;
    int i;
    
    if (a->top < 1)
        return;
        
    temp = a->array[a->top];
    
    for (i = a->top; i > 0; i--)
        a->array[i] = a->array[i - 1];
    
    a->array[0] = temp;
    write(1, "ra\n", 3);
} 