/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:48:35 by marieke           #+#    #+#             */
/*   Updated: 2024/05/20 13:37:57 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

t_stack	*init_stack(char *arguments[], int st_sze)
{
	t_stack		*a;
	t_stack		*new;
	long int	nb;
	int			i;

	a = NULL;
	i = 0;
	while (i < st_sze)
	{
		nb = ft_atoi(arguments[i]);
		if (nb < INT_MIN || nb > INT_MAX)
		{
			free_stack(&a);
			return (NULL);
		}
		new = stack_new((int)nb);
		if (!new)
		{
			free_stack(&a);
			exit_error(NULL, NULL);
		}
		stack_add_bottom(&a, &new);
		i++;
	}
	return (a);
}

void	find_lowest_unindexed(t_stack **a, int *low_val, t_stack **low_ptr)
{
	t_stack	*tmp;

	tmp = *a;
	*low_val = INT_MAX;
	*low_ptr = NULL;
	while (tmp)
	{
		if (tmp->value == INT_MAX && tmp->index == 0)
			tmp->index = get_stack_size(*a, NULL);
		if (tmp->value < *low_val && tmp->index == 0)
		{
			*low_val = tmp->value;
			*low_ptr = tmp;
		}
		tmp = tmp->next;
	}
}

void	get_index(t_stack **a, int st_sze, int low_val, t_stack *low_ptr)
{
	int		index;

	index = 1;
	while (index <= st_sze)
	{
		find_lowest_unindexed(a, &low_val, &low_ptr);
		if (low_ptr != NULL)
			low_ptr->index = index;
		index++;
	}
}
