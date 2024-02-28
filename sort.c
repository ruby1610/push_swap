/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:03:26 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/28 16:57:18 by maraasve         ###   ########.fr       */
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

// void	sort(t_stack **A, t_stack **B, int stack_size)
// {
// 	return ;
// }

// void	sort_three(t_stack **A, int stack_size)
// {
// 	return ;
// }