/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:36 by mudoh             #+#    #+#             */
/*   Updated: 2023/02/02 17:03:03 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int		fd;
	size_t	count;
	size_t	indexmay;
	size_t	indexmax;
	size_t	index;
	size_t	index2;
	char	*line;
	char	**map;

	count = 0;
	index = 0;
	index2 = 0;
	if(argc != 2)
		return(write(2, "Error\n vous n'avez pas rentrez le bon nombre d'argument!", 57));

	fd = open(argv[1], O_RDONLY);
	while (argv[1][index])
		index++;
	if (argv[1][index - 1] != 'r' || argv[1][index - 2] != 'e' ||
		argv[1][index - 3] != 'b' || argv[1][index - 4] != '.')
		return(write(2,"Error\n", 7));
	index = 0;
	line = get_next_line(fd);
	if (!line)
		return(write(2,"Error\n", 7));
	count++;
	while (line)
	{
		line = get_next_line(fd);
		free (line);
		count++;
	}
 	if (count < 3)
		return(write(2,"Error\n", 7));
	if(close(fd) == -1)
		return(write(2,"Error\n", 7));
 	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		return(write(2,"Error\n", 7));
	map = malloc(sizeof (char*) * (count + 1));
	if (!map)
		return(0);
	index = 0;
	map[0] = get_next_line(fd);
	while (map[0][index2])
	{
		if (map[0][index2] == '\n')
			map[0][index2] = '\0';
		index2++;
	}
	while (map[index])
	{
		index2 = 0;
		index++;
		map[index] = get_next_line(fd);
		while (map[index] && map[index][index2])
		{
			if (map[index][index2] == '\n')
				map[index][index2] = '\0';
			index2++;
			indexmay = index2 - 1;
		}
	}

	checkingMap(map);
	return(write(1,"OK",2));
	ft_printf("%s", map[2]);
	ft_printf("%d", index);
}
