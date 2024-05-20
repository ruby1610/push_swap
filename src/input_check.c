/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:22:53 by maraasve          #+#    #+#             */
/*   Updated: 2024/05/20 17:47:49 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	has_duplicates(char *argv[])
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		num1 = ft_atoi(argv[i]);
		while (argv[j])
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	input_checker(char *argv[])
{
	int	i;
	int	zeros;

	zeros = 0;
	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		zeros += is_zero(argv[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (has_duplicates(argv))
		return (0);
	return (1);
}
