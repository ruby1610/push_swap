/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:10:08 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/28 14:26:48 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	sa(t_stack *A)
{
	swap(A);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *B)
{
	swap(B);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *A, t_stack *B)
{
	swap(A);
	swap(B);
	ft_putstr_fd("ss\n", 1);	
}