/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:54 by marieke           #+#    #+#             */
/*   Updated: 2024/03/28 17:02:37 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_both(t_stack **A, t_stack **B, int *cost_a, int *cost_b)
{
	while ((*cost_a) < 0 && (*cost_b) < 0)
	{
		rrr(A, B);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	rotate_both(t_stack **A, t_stack **B, int *cost_a, int *cost_b)
{
	while ((*cost_a) > 0 && (*cost_b) > 0)
	{
		rr(A, B);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rotate_a(t_stack **A, int *cost_a)
{
	while ((*cost_a) != 0)
	{
		if ((*cost_a) > 0)
		{
			ra(A);
			(*cost_a)--;
		}
		if ((*cost_a) < 0)
		{
			rra(A);
			(*cost_a)++;
		}
	}
}

void	rotate_b(t_stack **B, int *cost_b)
{
	while ((*cost_b) != 0)
	{
		if ((*cost_b) > 0)
		{
			rb(B);
			(*cost_b)--;
		}
		if ((*cost_b) < 0)
		{
			rrb(B);
			(*cost_b)++;
		}
	}
}

void	execute_move(t_stack **A, t_stack **B, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(A, B, &cost_a, &cost_b);
	if (cost_a > 0 && cost_b > 0)
		rotate_both(A, B, &cost_a, &cost_b);
	rotate_a(A, &cost_a);
	rotate_b(B, &cost_b);
	pa(A, B);
}
