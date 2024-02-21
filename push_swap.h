/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:32 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/21 17:33:32 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				position;
	struct s_stack	*previous;
	struct s_stack	*next;
}
t_stack;

int	input_checker(char *argv[]);
int	is_number(char *str);
int	is_zero(char *str);
int	has_duplicates(char *argv[]);
int	is_sign(char c);

#endif