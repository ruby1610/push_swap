/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:59:13 by marieke           #+#    #+#             */
/*   Updated: 2024/03/01 15:34:21 by maraasve         ###   ########.fr       */
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

void	exit_error(t_stack **B, t_stack **A)
{
	if (A != NULL && (*A) != NULL)
		free_stack(A);	
	if (B != NULL && (*B) != NULL)
		free_stack(B);
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

int	get_stack_size(t_stack *stack)
{
	int	stack_size;

	stack_size = 0;
	while (stack)
	{
		stack_size++;
		stack = stack->next;
	}
	return (stack_size);
}