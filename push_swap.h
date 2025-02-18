/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:32:18 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/19 02:36:13 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "stdio.h"

typedef struct s_stack
{
    int *arr;
    int size;
} t_stack;

void    ft_swap(int *a, int *b);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
void    ft_push(t_stack *a, t_stack *b, char stack);
void    ft_rotate(t_stack *a, t_stack *b, char stack);
void    ft_reverse_rotate(t_stack *a, t_stack *b, char stack);
void    selection_sort(t_stack *a);
void    radix_sort(t_stack *a, t_stack *b);
int     is_sorted(t_stack *a);
void    print_stack(t_stack *stack);
int     get_min(t_stack *stack);
int     get_max(t_stack *stack);
int     get_next_max(t_stack *stack, int current_max);
void    free_stack(t_stack *stack);

#endif
