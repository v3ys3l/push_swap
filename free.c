/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:55:52 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/27 17:09:50 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error(char *str, t_stack *stack, int flag)
{
	if (flag == 1)
		ft_free(stack->tmp);
	if (stack->a != NULL)
		free(stack->a);
	if (stack->b != NULL)
		free(stack->b);
	ft_putstr_fd(str, 2);
	exit(1);
}
