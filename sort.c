/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:03:26 by maraasve          #+#    #+#             */
/*   Updated: 2024/03/01 16:09:03 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *A)
{
	while (A->next != NULL)
	{
		if (A->value > A->next->value)
			return (0);
		A = A->next;
	}
	return (1);
}

// void	rotate_stack(t_stack **A)
// {
// 	while ()
// }

void	push_all_but_three(t_stack **A, t_stack **B, int stack_size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (i < stack_size && stack_size > 6 && pushed < stack_size / 2)
	{
		if ((*A)->index < stack_size / 2)
		{
			pb(A, B);
			pushed++;
		}
		else
			ra(A);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(A, B);
		pushed++;
	}
}

void	sort_three(t_stack **stack)
{	
	int	highest;

	if (stack == NULL || *stack == NULL)
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_bigger_stack(t_stack **A, t_stack **B, int stack_size)
{
	push_all_but_three(A, B, stack_size);
	sort_three(A);
	//while (*B)
	//{
		get_target_position(A, B);
		//get_cost(A, B);
		//cheapest_move(A, B);
	//}
	// if (!is_sorted(*A))
		//rotate_stack(A);
}
