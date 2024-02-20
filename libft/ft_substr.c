/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:42:32 by marieke           #+#    #+#             */
/*   Updated: 2024/02/16 15:02:28 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	sub_len;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_calloc(1, sizeof(char)));
	else if (s_len < len || s_len - start < len)
		sub_len = s_len - start;
	else
		sub_len = len;
	new_str = ft_calloc(sub_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy_esc(new_str, &s[start], len + 1);
	return (new_str);
}
