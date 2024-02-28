/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:32 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/28 14:50:53 by maraasve         ###   ########.fr       */
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
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*previous;
	struct s_stack	*next;
}
t_stack;

/*input_checker*/
int		input_checker(char *argv[]);
int		is_number(char *str);
int		is_zero(char *str);
int		has_duplicates(char *argv[]);
int		is_sign(char c);

/*parser*/
t_stack	*innit_stack(int argc, char *argv[]);
void	get_index(t_stack **A, int stack_size);

/*utils*/
void	free_stack(t_stack **stack);
void	exit_error(t_stack **B, t_stack **A);

/*stack*/
t_stack *stack_new(int value);
t_stack	*get_bottom(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack **new);

/*sort*/
int		is_sorted(t_stack *A);

/*swap*/
void	swap(t_stack *stack);
void	sa(t_stack *A);
void	sb(t_stack *B);
void	ss(t_stack *A, t_stack *B);

/*push*/
void	push(t_stack **stack_src, t_stack **stack_dst);
void	pa(t_stack **A, t_stack **B);
void	pb(t_stack **A, t_stack **B);

/*rotate*/
#endif