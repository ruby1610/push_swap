/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:59:13 by marieke           #+#    #+#             */
/*   Updated: 2024/03/28 14:56:21 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_arr(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_error(t_stack **B, t_stack **A, char **array, int argc)
{
	int	i;

	if (A != NULL && (*A) != NULL)
		free_stack(A);
	if (B != NULL && (*B) != NULL)
		free_stack(B);
	if (argc == 2 && array != NULL)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	find_highest_index(t_stack *stack)
{
	int	highest;

	highest = INT_MIN;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

int	get_stack_size(t_stack *stack, char **array)
{
	int	stack_size;

	stack_size = 0;
	if (array)
	{
		while (array[stack_size])
			stack_size++;
		return (stack_size);
	}
	while (stack)
	{
		stack_size++;
		stack = stack->next;
	}
	return (stack_size);
}
