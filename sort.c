/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:03:26 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/28 14:05:03 by maraasve         ###   ########.fr       */
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