/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/05/01 17:49:27 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sorting(int stack_size, t_stack **a, t_stack **b)
{
	if (stack_size == 2 && !is_sorted(*a))
		sa(a);
	else if (stack_size == 3 && !is_sorted(*a))
		sort_three(a);
	else if (stack_size > 3 && !is_sorted(*a))
		sort_bigger_stack(a, b, stack_size);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**array;
	int		stack_size;

	if (argc < 3)
		return (0);
	array = &argv[1];
	if (!array || !input_checker(array))
		exit_error(NULL, NULL, array, argc);
	stack_size = get_stack_size(NULL, array);
	b = NULL;
	a = innit_stack(argc, array, stack_size);
	if (!a)
		exit_error(NULL, NULL, array, argc);
	get_index(&a, stack_size, INT_MAX, NULL);
	start_sorting(stack_size, &a, &b);
	free_stack(&a);
	free_stack(&b);
}
