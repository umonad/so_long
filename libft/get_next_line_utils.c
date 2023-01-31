/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:44:23 by mudoh             #+#    #+#             */
/*   Updated: 2023/01/31 14:35:16 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchrr(char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlenn(s)]);
	p = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (p);
		i++;
		p++;
	}
	return (0);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	p = malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[++i])
		p[i] = s1[i];
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
}
