/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:10:28 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/28 15:31:32 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;

	if (!*stack)
		return ;
	bottom = get_bottom(*stack);
	tmp = bottom->previous;
	bottom->next = *stack;
	bottom->previous = NULL;
	(*stack)->previous = bottom;
	*stack = bottom;
	tmp->next = NULL;
}

void	rra(t_stack **A)
{
	reverse_rotate(A);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **B)
{
	reverse_rotate(B);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **A, t_stack **B)
{
	reverse_rotate(A);
	reverse_rotate(B);
	ft_putstr_fd("rrr\n", 1);
}
