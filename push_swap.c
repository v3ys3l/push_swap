/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:09:36 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/27 17:16:40 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	creat_stack(char **tmp, t_stack *stacks)
{
	int	i;

	i = 0;
	stacks->size_a = ft_arrsize(tmp);
	if (stacks->size_a < 1)
		ft_error("Error\n", stacks, stacks->flag);
	stacks->a = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!stacks->a)
		ft_error("Error\nMalloc failed", stacks, stacks->flag);
	stacks->b = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!stacks->b)
		ft_error("Error\nMalloc failed", stacks, stacks->flag);
	while (tmp[i])
	{
		stacks->a[i] = ps_atoi(tmp[i], stacks);
		i++;
	}
	repeate_number(stacks);
}

static void	init_data(t_stack *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->tmp = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	stacks->flag = 0;
}

void	ft_sorts(t_stack *stacks, int size)
{
	if (ft_sorted(stacks->a, stacks->size_a) == 0)
	{
		if (size == 2)
			sa(stacks, 0);
		else if (size == 3)
			ft_sort_three(stacks);
		else if (stacks->size_a <= 32)
			selection_sort(stacks);
		else
		{
			index_stack(stacks->a, stacks->size_a, stacks);
			radix_sort(stacks);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		return (0);
	av++;
	init_data(&stack);
	if (ac == 2)
	{
		stack.tmp = ft_split(av[0], ' ');
		if (!stack.tmp)
			ft_error("Error\nMalloc failed", &stack, 0);
		stack.flag = 1;
		creat_stack(stack.tmp, &stack);
	}
	else
		creat_stack(av, &stack);
	if (stack.flag == 1)
		ft_free(stack.tmp);
	ft_sorts(&stack, stack.size_a);
	free(stack.a);
	free(stack.b);
}
