/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/03/06 16:01:51 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char *argv[])
{
	t_stack	*A;
	t_stack	*B;
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
	B = NULL;
	A = innit_stack(argc, array, stack_size);
	if (!A)
		exit_error(NULL, NULL, array, argc);
	get_index(&A, stack_size);
	if (stack_size == 2 && !is_sorted(A))
		sa(&A);
	else if (stack_size == 3 && !is_sorted(A))
		sort_three(&A);
	else if (stack_size > 3 && !is_sorted(A))
		sort_bigger_stack(&A, &B, stack_size);
	free_stack(&A);
	free_stack(&B);
}
