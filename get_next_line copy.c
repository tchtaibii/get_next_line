/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:07 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/21 19:38:35 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *get_line(char *a)
{
	char *l;
	int i;

	i = newline_search(a);
	l = ft_substr(a, 0,i);
	
	return (l);
}
char *get_buff(int fd)
{
	char *a;
	a = malloc(BUFFER_SIZE + 1);
	read(fd,a,BUFFER_SIZE);
	return (a);
}
char *get_next_line(int fd)
{
    static char *a;
	char *l;
	
	if (fd < 0 && BUFFER_SIZE == 0)
		return (NULL);
	a = malloc(BUFFER_SIZE + 1);
	a = get_buff(fd);
	l = get_line(a);
}