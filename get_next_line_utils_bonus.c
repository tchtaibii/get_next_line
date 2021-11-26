/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:03 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/26 23:10:26 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*new;
	int				lens1;
	int				lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new = malloc((lens1 + lens2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < lens1)
		new[i++] = s1[j++];
	j = 0;
	while (j < lens2)
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
	int		j;

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
