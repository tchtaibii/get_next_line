/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:07 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/26 20:51:52 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//check if new line exist
int	check_new_line(char *s)
{
	int	i;

	if (!s)
		return (0);
		i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// (get line) take the chars (BUFFER_SIZE) and storage it in to s
char	*get_l(int fd, char *s)
{
	char	*tmp;
	int		t;

	t = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	while (t && !check_new_line(s))
	{
		t = read(fd, tmp, BUFFER_SIZE);
		if (t == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[t] = '\0';
		s = ft_strjoin(s, tmp);
	}
	free(tmp);
	return (s);
}

// (befor new line) for allocate and storage in the str to new line
char	*ft_bl(char *s)
{
	int	i;

	if (!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_substr(s, 0, i + 1));
}

// (after new line) for using the values after new line
char	*ft_al(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			tmp = ft_substr(s, i + 1, ft_strlen(s));
			free(s);
			return (tmp);
		}
		i++;
	}
	free(s);
	return (NULL);
}

// get next line
char	*get_next_line(int fd)
{
	static char	*a;
	char		*l;

	l = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	a = get_l(fd, a);
	if (!a)
		return (NULL);
	l = ft_bl(a);
	a = ft_al(a);
	return (l);
}
