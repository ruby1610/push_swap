/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/28 14:51:29 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*A;
	t_stack	*B;

	if (argc < 2)
		return (1);
	if (!input_checker(argv))
		exit_error(NULL, NULL);
	B = NULL;
	A = innit_stack(argc, argv);
	if (!A)
		exit_error(NULL, NULL);
	get_index(&A, argc - 1);
	pa(&A, &B);
	
	// for (t_stack *tmp = A; tmp != NULL; tmp = tmp->next)
	// 	printf("%i ", tmp->value);
	// printf("\n");
	// for (t_stack *tmp = get_bottom(A); tmp != NULL; tmp = tmp->previous)
	// 	printf("%i ", tmp->value);
	// printf("\n");
	// for (t_stack *tmp = B; tmp != NULL; tmp = tmp->next)
	// 	printf("%i ", tmp->value);
	// printf("\n");
	// for (t_stack *tmp = get_bottom(B); tmp != NULL; tmp = tmp->previous)
	// 	printf("%i ", tmp->value);
	// printf("\n");
}
