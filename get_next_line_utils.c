/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:03 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/21 03:09:22 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int newline_search(char *s)
{
	int i;
	
	while (s[i])
	{
		if (s[i] == '/n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	i = 0;
	while (i < len && s[i + start])
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (j < i)
		new[j++] = s[start++];
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}