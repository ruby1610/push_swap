/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:31:41 by maraasve          #+#    #+#             */
/*   Updated: 2024/03/01 16:18:03 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_target(t_stack **A, int b_index, int target_index, int target_pos)
{
	t_stack	*tmpA;
	
	tmpA = *A;
	while (tmpA)
	{
		if (tmpA->index > b_index && tmpA->index < target_index)
		{
			target_index = tmpA->index;
			target_pos = tmpA->pos;
		}
		tmpA = tmpA->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	tmpA = *A;
	while (tmpA)
	{
		if (tmpA->index < target_index)
		{
			target_index = tmpA->index;
			target_pos = tmpA->pos;
		}
		tmpA = tmpA->next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **A, t_stack **B)
{
	t_stack	*tmpB;
	int		target_pos;

	tmpB = *B;
	get_position(A);
	get_position(B);
	target_pos = 0;
	while (tmpB)
	{
		target_pos = get_target(A, tmpB->index, INT_MAX, target_pos);
		tmpB->target_pos = target_pos;
		tmpB = tmpB->next;
	}
}
