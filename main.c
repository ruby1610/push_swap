/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/03/07 16:06:44 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**array;
	int		stack_size;

	if (argc == 1)
		return (0);
	array = get_arguments(argc, argv);
	if (!array)
		exit_error(NULL, NULL, NULL, argc);
	if (!input_checker(array))
		exit_error(NULL, NULL, array, argc);
	stack_size = get_stack_size(NULL, array);
	b = NULL;
	a = innit_stack(argc, array, stack_size);
	if (!a)
		exit_error(NULL, NULL, array, argc);
	get_index(&a, stack_size);
	if (stack_size == 2 && !is_sorted(a))
		sa(&a);
	else if (stack_size == 3 && !is_sorted(a))
		sort_three(&a);
	else if (stack_size > 3 && !is_sorted(a))
		sort_bigger_stack(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
}
