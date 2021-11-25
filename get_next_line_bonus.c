/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:02:57 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/25 03:41:49 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

//check if new line exist
int	check_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// (get line) take the chars (BUFFER_SIZE) and storage it in to s
char	*get_l_bonus(int fd, char *s)
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
char	*ft_bl_bonus(char *s)
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
char	*ft_al_bonus(char *s)
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
char	*get_next_line_bonus(int fd)
{
	static char	*a[10240];
	char		*l;

	l = NULL;
	if (fd < 0 && BUFFER_SIZE == 0)
		return (NULL);
	a[fd] = get_l_bonus(fd, a[fd]);
	if (!a[fd])
		return (NULL);
	l = ft_bl_bonus(a[fd]);
	a[fd] = ft_al_bonus(a[fd]);
	return (l);
}
