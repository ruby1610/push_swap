/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:48:35 by marieke           #+#    #+#             */
/*   Updated: 2024/04/30 18:11:30 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_arguments(int argc, char *argv[])
{
	char	**array;

	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		if (!array)
			return (NULL);
	}
	else
		array = &argv[1];
	return (array);
}

t_stack	*innit_stack(int argc, char *arguments[], int st_sze)
{
	t_stack		*a;
	t_stack		*new;
	long int	nb;
	int			i;

	i = 0;
	while (i < st_sze)
	{
		nb = ft_atoi(arguments[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (NULL);
		if (i == 0)
		{
			a = stack_new((int)nb);
			if (!a)
				exit_error(NULL, NULL, arguments, argc);
		}
		else
		{
			new = stack_new((int)nb);
			stack_add_bottom(&a, &new, arguments, argc);
		}
		i++;
	}
	return (a);
}

void	find_lowest_unindexed(t_stack **a, int *low_val, t_stack **low_ptr)
{
	t_stack	*tmp;

	*tmp = *a;
	*low_val = INT_MAX;
	*low_ptr = NULL;
	while (tmp)
	{
		if (tmp->value == INT_MAX && tmp->index == 0)
			tmp->index = stack_size(*a);
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
	t_stack	*tmp;
	int		index;

	index = 1;
	while (index <= st_sze)
	{
		find_lowest_unindexed(a, low_val, &low_ptr);
		if (low_ptr != NULL)
			low_ptr->index = index;
		index++;
	}
}
