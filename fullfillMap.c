/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullfillMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:08:51 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/07 17:01:50 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countline(char **argv, size_t nbline)
{
	int		fd;
	char	*line;
	char	*lol;

	nbline = 1;
	lol = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (!lol || ft_strlen(lol) != 4)
		return (write(2, "Error syntaxe\n", 14), -1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error oppen\n", 12), -1);
	line = get_next_line(fd, 0);
	if (!line)
		return (write(2, "Error syntaxe\n", 14), free(line), close(fd), -1);
	while (line)
	{
		(free(line), line = get_next_line(fd, 0));
		if (line)
			nbline++;
	}
	if (close(fd) == -1)
		return (free(line), write(2, "Error close\n", 12), -1);
	return (free(line), nbline);
}

int	fullfillmap(char **map, char **argv, int nb_line)
{
	int		fd;
	int		indexline;
	int		indexcolumn;

	indexline = 0;
	indexcolumn = 0;
	if (nb_line < 3)
		return (write(1, "Error syntaxe\n", 14), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(1, "Error open\n", 12), 1);
	while (indexline < nb_line)
	{
		map[indexline] = get_next_line(fd, 0);
		indexcolumn = 0;
		while (map[indexline] && map[indexline][indexcolumn])
		{
			indexcolumn++;
			if (map[indexline][indexcolumn] == '\n')
				map[indexline][indexcolumn] = '\0';
		}
		indexline++;
	}
	close(fd);
	return (map[indexline] = NULL, indexcolumn);
}

/* int	fullfillMap(char **map, char **argv, int nb_line)
{
	int fd;
	size_t indexline;
	size_t indexcolumn;

	indexline = 0;
	indexcolumn = 0;
	if (nb_line < 3)
		return (write(STDERR_FILENO, "Error syntax\n", 6), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(STDERR_FILENO, "Error\n", 6), 0);
	while (indexline < nb_line)
	{
		map[indexline] = get_next_line(fd);
		if (!map[indexline])
			return (0);
		indexcolumn = 0;
		while (map[indexline] && map[indexline][indexcolumn])
			(map[indexline][indexcolumn++] == '\n') ? map[indexline][indexcolumn
			- 1] = '\0' : 0;
		indexline++;
	}

	return (map[indexline] = NULL, close(fd), indexcolumn);
} */
