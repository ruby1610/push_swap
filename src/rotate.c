/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:52:14 by maraasve          #+#    #+#             */
/*   Updated: 2024/05/20 13:29:48 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;

	if (!*stack)
		return ;
	tmp = (*stack)->next;
	bottom = get_bottom(*stack);
	bottom->next = *stack;
	(*stack)->previous = bottom;
	(*stack)->next = NULL;
	tmp->previous = NULL;
	*stack = tmp;
}

void	ra(t_stack **A)
{
	rotate(A);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **B)
{
	rotate(B);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **A, t_stack **B)
{
	rotate(A);
	rotate(B);
	ft_putstr_fd("rr\n", 1);
}
