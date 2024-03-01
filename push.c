/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:30:13 by maraasve          #+#    #+#             */
/*   Updated: 2024/03/01 15:24:05 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;
	
	if (*stack_src == NULL)
		return ;
	tmp = (*stack_src)->next;
	if (*stack_dst != NULL)
		(*stack_dst)->previous = *stack_src;
	(*stack_src)->next = *stack_dst;
	*stack_dst = *stack_src;
	*stack_src = tmp;
	(*stack_src)->previous = NULL;
}

void	pa(t_stack **A, t_stack **B)
{
	push(B, A);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **A, t_stack **B)
{
	push(A, B);
	ft_putstr_fd("pb\n", 1);
}
