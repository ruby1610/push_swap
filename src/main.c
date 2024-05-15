/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/05/15 16:50:15 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

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
	int		stack_size;

	if (argc < 3)
		exit_error(NULL, NULL);
	if (!input_checker(&argv[1]))
		exit_error(NULL, NULL);
	stack_size = get_stack_size(NULL, &argv[1]);
	b = NULL;
	a = init_stack(&argv[1], stack_size);
	if (!a)
		exit_error(NULL, NULL);
	get_index(&a, stack_size, INT_MAX, NULL);
	start_sorting(stack_size, &a, &b);
	free_stack(&a);
	free_stack(&b);
}
