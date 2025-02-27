/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:30:51 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 17:54:39 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return a copy of a string until n char is reached */
char	*gc_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	i;

	copy = gc_malloc((n + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i] && n--)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
