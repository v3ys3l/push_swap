/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:57:33 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/27 17:19:36 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	char	**tmp;
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		flag;
}			t_stack;

void		index_stack(int *stack, int size, t_stack *s);

void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		rra(t_stack *stack, int print);
void		rrb(t_stack *stack, int print);
void		rrr(t_stack *stack);
void		ra(t_stack *stack, int print);
void		rb(t_stack *stack, int print);
void		rr(t_stack *stack);
void		sa(t_stack *stack, int print);
void		sb(t_stack *stack, int print);
void		ss(t_stack *stack);

void		ft_free(char **str);
void		ft_error(char *str, t_stack *stack, int flag);

void		radix_sort(t_stack *stack);
void		ft_sort_three(t_stack *s);
void		ft_sorts(t_stack *stack, int size);
void		selection_sort(t_stack *stack);

void		repeate_number(t_stack *stack);
int			ft_arrsize(char **ptr);
int			ps_atoi(char *str, t_stack *stack);
int			ft_sorted(int *stack, int size);

#endif
