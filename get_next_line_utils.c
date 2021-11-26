/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:03 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/25 22:37:42 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	new = malloc (ft_strlen(s2) + ft_strlen(s1) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*x;
	int		i;
	int	 	j;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	i = 0;
	j = 0;
	while (i < len && s[i])
		i++;
	x = malloc(i + 1);
	if (!x)
		return (NULL);
	while (j < i)
		x[j++] = s[start++];
	x[i] = '\0';
	return (x);
}
