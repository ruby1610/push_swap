/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:48:35 by marieke           #+#    #+#             */
/*   Updated: 2024/03/06 16:05:57 by marieke          ###   ########.fr       */
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

t_stack	*innit_stack(int argc, char *arguments[], int stack_size)
{
	t_stack		*A;
	t_stack		*new;
	long int	nb;
	int			i;

	i = 0;
	while(i < stack_size)
	{
		nb = ft_atoi(arguments[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (NULL);
		if (i == 0)
		{
			A = stack_new((int)nb);
			if (!A)
				exit_error(NULL, NULL, arguments, argc);
		}
		else
		{
			new = stack_new((int)nb);
			stack_add_bottom(&A, &new, arguments, argc);
		}
		i++;
	}
	return (A);
}

void	get_index(t_stack **A, int stack_size)
{
	t_stack *tmp;
	t_stack	*lowest_ptr;
	int		lowest_value;
	int		index;

	index = 1;
	while (index <= stack_size)
	{
		tmp = *A;
		lowest_value = INT_MAX;
		lowest_ptr = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MAX && tmp->index == 0)
				tmp->index = stack_size;
			if (tmp->value < lowest_value && tmp->index == 0)
			{
				lowest_value = tmp->value;
				lowest_ptr = tmp;
				tmp = *A;
			}
			else
				tmp = tmp->next;
		}
		if (lowest_ptr != NULL)
			lowest_ptr->index = index;
		index++;
	}
}
