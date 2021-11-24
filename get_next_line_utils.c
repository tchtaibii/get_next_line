/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:03 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/24 03:05:43 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s2) + ft_strlen((char *)s1);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}