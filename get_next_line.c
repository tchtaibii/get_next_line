/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:07 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/21 19:55:46 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int check_new_line(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char *get_l(int fd, char tmp)
{
	char *str;
	int t;

	t = 1;
	str = malloc(BUFFER_SIZE + 1);
	while (t && !check_new_line(str))
	{
		t = read(fd, str,BUFFER_SIZE);
		if (t = -1)
		{
			free(str);
			return (NULL);
		}
		str[t] = '\0';
		tmp = ft_strjoin(tmp, str);
	}
	free(str);
	return (tmp); 
	
}
char *get_next_line(int fd)
{
    static char *a;
	char *l;
	
	if (fd < 0 && BUFFER_SIZE == 0)
		return (NULL);
	
}