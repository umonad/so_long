/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:50:26 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/01 01:51:06 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}

void	ft_displaymap(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				display_player(data, x, y);
			if (map[y][x] == '0')
				display_floor(data, x, y);
			if (map[y][x] == '1')
				display_wall(data, x, y);
			if (map[y][x] == 'C')
				display_collectible(data, x, y);
			if (map[y][x] == 'E')
				display_exit(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
