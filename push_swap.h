/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:32 by maraasve          #+#    #+#             */
/*   Updated: 2024/04/30 17:58:39 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

/*cost*/
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	cheapest_move(t_stack **A, t_stack **B);

/*input_checker*/
int		input_checker(char *argv[]);
int		is_number(char *str);
int		is_zero(char *str);
int		has_duplicates(char *argv[]);
int		is_sign(char c);

/*parser*/
t_stack	*innit_stack(int argc, char *arguments[], int stack_size);
void	get_index(t_stack **a, int st_sze, int low_val, t_stack *low_ptr);
char	**get_arguments(int argc, char *argv[]);

/*utils*/
void	free_stack(t_stack **stack);
void	exit_error(t_stack **B, t_stack **A, char **array, int argc);
int		find_highest_index(t_stack *stack);
int		get_stack_size(t_stack *stack, char **array);
void	free_arr(char **array);

/*stack*/
t_stack	*stack_new(int value);
t_stack	*get_bottom(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack **new, char **args, int argc);

/*sort*/
int		is_sorted(t_stack *A);
void	push_all_but_three(t_stack **A, t_stack **B, int stack_size);
void	sort_bigger_stack(t_stack **A, t_stack **B, int stack_size);
void	sort_three(t_stack **A);

/*swap*/
void	swap(t_stack **stack);
void	sa(t_stack **A);
void	sb(t_stack **B);
void	ss(t_stack **A, t_stack **B);

/*push*/
void	push(t_stack **stack_src, t_stack **stack_dst);
void	pa(t_stack **A, t_stack **B);
void	pb(t_stack **A, t_stack **B);

/*position*/
void	get_target_position(t_stack **A, t_stack **B);
void	get_position(t_stack **stack);
int		get_target(t_stack **A, int b_index, int target_index, int target_pos);

/*move*/
void	execute_move(t_stack **A, t_stack **B, int cost_a, int cost_b);
void	rotate_b(t_stack **B, int *cost_b);
void	rotate_a(t_stack **A, int *cost_a);
void	rotate_both(t_stack **A, t_stack **B, int *cost_a, int *cost_b);
void	rev_rotate_both(t_stack **A, t_stack **B, int *cost_a, int *cost_b);

/*rotate*/
void	rotate(t_stack **stack);
void	ra(t_stack **A);
void	rb(t_stack **B);
void	rr(t_stack **A, t_stack **B);

/*reverse_rotate*/
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **A);
void	rrb(t_stack **B);
void	rrr(t_stack **A, t_stack **B);

#endif