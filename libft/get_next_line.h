/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:59:51 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/02 18:10:39 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd, int val);
char	*ft_strchrr(char *s, int c);
char	*ft_strjoinn(char *s1, char *s2);
char	*collect_andaddtotmp(char *tmp);
char	*extract_and_addtores(char *tmp);
char	*read_and_addtotmp(char *tmp, int fd);
int		ft_strlenn(char *str);

#endif
