/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/03/04 19:35:11 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char *argv[])
{
	t_stack	*A;
	t_stack	*B;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!input_checker(argv))
		exit_error(NULL, NULL);
	B = NULL;
	A = innit_stack(argc, argv);
	if (!A)
		exit_error(NULL, NULL);
	stack_size = argc - 1;
	get_index(&A, stack_size);


	printf("stack A:");
	for (t_stack *tmp = A; tmp != NULL; tmp = tmp->next)
	{
		printf ("%i ", tmp->value);
	}
	printf("\n");
	printf("stack A index:");
	for (t_stack *tmp = A; tmp != NULL; tmp = tmp->next)
	{
		printf ("%i ", tmp->index);
	}
	printf("\n");


	
	if (stack_size == 2 && !is_sorted(A))
		sa(&A);
	else if (stack_size == 3 && !is_sorted(A))
		sort_three(&A);
	else if (stack_size > 3 && !is_sorted(A))
		sort_bigger_stack(&A, &B, stack_size);



	
	printf("stack A:");
	for (t_stack *tmp = A; tmp != NULL; tmp = tmp->next)
	{
		printf ("%i ", tmp->value);
	}
	printf("\n");	
	printf("stack B:");
	for (t_stack *tmp = B; tmp != NULL; tmp = tmp->next)
	{
		printf ("%i ", tmp->value);
	}
	printf("\n");
	printf("stack B pos:");
	for (t_stack *tmp = B; tmp != NULL; tmp = tmp->next)
	{
		printf ("%i ", tmp->pos);
	}
	printf("\n");
	printf("stack B target_pos:");
	for (t_stack *tmp = B; tmp != NULL; tmp = tmp->next)
	{
		printf ("%i ", tmp->target_pos);
	}
	printf("\n");



	free_stack(&A);
	free_stack(&B);
}
