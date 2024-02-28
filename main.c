/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/28 16:57:06 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*A;
	t_stack	*B;
	int		stack_size;

	if (argc < 2)
		return (1);
	if (!input_checker(argv))
		exit_error(NULL, NULL);
	B = NULL;
	A = innit_stack(argc, argv);
	if (!A)
		exit_error(NULL, NULL);
	stack_size = argc - 1;
	get_index(&A, stack_size);
	if (stack_size == 2 && !is_sorted(A))
		sa(&A);
	// else if (stack_size == 3 && !is_sorted(A))
	// 	sort_three(&A, stack_size);
	// else if (stack_size > 3 && !is_sorted(A))
	// 	sort(&A, &B, stack_size);
	free_stack(&A);
	free_stack(&B);
}
