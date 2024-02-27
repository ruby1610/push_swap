/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:04:43 by marieke           #+#    #+#             */
/*   Updated: 2024/02/27 16:56:13 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_new(int value)
{
	t_stack *new;
	
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->position = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}
void	stack_add_bottom(t_stack **stack, t_stack **new)
{
	t_stack	*bottom;

	if (!*new)
		exit_error(stack, NULL);
	if (!*stack)
	{
		*stack = *new;
		return ;
	}
	bottom = get_bottom(*stack);
	bottom->next = *new;
	(*new)->previous = bottom;
}

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}