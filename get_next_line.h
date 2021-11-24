/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:09 by tchtaibi          #+#    #+#             */
/*   Updated: 2021/11/24 02:59:55 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int		newline_search(char *s);
char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *str);

#endif