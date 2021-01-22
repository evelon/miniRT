/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <jolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:50:04 by jolim             #+#    #+#             */
/*   Updated: 2021/01/03 21:18:15 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
int		ft_reader(int fd, char **backup, char **line);
int		exception(int rd_size, char **backup, char **line);

int		put_line(char *s, char **line, int len);
char	*str_cut(char *s, int len);
char	*str_cat(char *s1, char *s2, int len2);
int		nl_finder(char *str);

#endif
