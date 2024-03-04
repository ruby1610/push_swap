/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:27:10 by maraasve          #+#    #+#             */
/*   Updated: 2024/03/04 19:57:21 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_cost(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int size_a;
    int size_b;

    tmp_a = *stack_a;
    tmp_b = *stack_b;
    size_a = get_stack_size(tmp_a);
    size_b = get_stack_size(tmp_b);

    while (tmp_b)
    {
        // Calculate cost_b
        tmp_b->cost_b = tmp_b->pos;
        if (tmp_b->pos > size_b / 2)
            tmp_b->cost_b = (size_b - tmp_b->pos) * -1;

        // Calculate cost_a
        tmp_b->cost_a = tmp_b->target_pos;
        if (tmp_b->target_pos > size_a / 2)
            tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;

        tmp_b = tmp_b->next;
    }
}

void	cheapest_move(t_stack **A, t_stack **B)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;
	int		cheapest;

	cheapest = INT_MAX;
	tmp = *B;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < cheapest)
		{
			cheapest = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(A, B, cost_a, cost_b);
}