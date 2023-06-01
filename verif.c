/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:45:28 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/01 02:48:20 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verifcol(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				if (map[y - 1][x] == '1')
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	verifup(char **map)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (map[y + 1])
	{
		while (map[y][x + 1])
		{
			if (map[y][x] == 'P')
			{
				if (map[y - 1][x] == '1')
					return (1);
				if (map[y - 1][x] == 'E')
					return (2);
			}
			x++;
		}
		x = 1;
		y++;
	}
	return (0);
}

int	verifdown(char **map)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (map[y + 1])
	{
		while (map[y][x + 1])
		{
			if (map[y][x] == 'P')
			{
				if (map[y + 1][x] == '1')
					return (1);
				if (map[y + 1][x] == 'E')
					return (2);
			}
			x++;
		}
		x = 1;
		y++;
	}
	return (0);
}

int	verifleft(char **map)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (map[y + 1])
	{
		while (map[y][x + 1])
		{
			if (map[y][x] == 'P')
			{
				if (map[y][x - 1] == '1')
					return (1);
				if (map[y][x - 1] == 'E')
					return (2);
			}
			x++;
		}
		x = 1;
		y++;
	}
	return (0);
}

int	verifright(char **map)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (map[y + 1])
	{
		while (map[y][x + 1])
		{
			if (map[y][x] == 'P')
			{
				if (map[y][x + 1] == '1')
					return (1);
				if (map[y][x + 1] == 'E')
					return (2);
			}
			x++;
		}
		x = 1;
		y++;
	}
	return (0);
}
