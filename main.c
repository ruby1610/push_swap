/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/20 17:22:41 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	innit_stack_B(t_stack **B)
{
	*B = (t_stack *)malloc(sizeof(t_stack));
	if (!*B)
		return (0);
	(*B)->previous = NULL;
	(*B)->next = NULL;
	return (1);
}

int	innit_stack_A(t_stack **A, int argc, char *argv[])
{
	t_stack *flag;
	int		i;

	*A = (t_stack *)malloc(sizeof(t_stack))
	i = 1;
	while (i < argc - 1)
	{
		
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*A;
	t_stack	*B;

	if (argc < 2)
		return (1);
	//check input for: things that aren't integers, min/max int
	A = NULL;
	B = NULL;
	if (!innit_stack_A(&A, argc, argv))
		return (1);
	if (!innit_stack_B(&B))
		return (1);
}