/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:24:15 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/01 02:10:34 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_c(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	compteur(char **map)
{
	int	check;
	int	x;
	int	y;

	check = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				check++;
			x++;
		}
		x = 0;
		y++;
	}
	return (check);
}

void	recursive(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'Z';
		return ;
	}
	map[y][x] = 'X';
	if (map[y][x + 1] != 'X')
		recursive(map, x + 1, y);
	if (map[y][x - 1] != 'X')
		recursive(map, x - 1, y);
	if (map[y + 1][x] != 'X')
		recursive(map, x, y + 1);
	if (map[y - 1][x] != 'X')
		recursive(map, x, y - 1);
}

int	accesss(char **map)
{
	int	check;
	int	x;
	int	y;

	x = -1;
	y = -1;
	check = 0;
	if (check == 0)
	{
		while (map[++y])
		{
			while (map[y][++x])
				if (map[y][x] == 'P')
					break ;
			if (map[y][x] == 'P')
				break ;
			x = 0;
		}
	}
	map[y][x] = 'X';
	recursive(map, x, y);
	if (compteur(map) != 0)
		return (write(STDERR_FILENO, "ERREUR pas de chemin\n", 22));
	return (0);
}

/* void	fill_map(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] != '0')
		return ;
	map[y][x] = 'X';
	fill_map(map, x+1, y);
	fill_map(map, x-1, y);
	fill_map(map, x, y+1);
	fill_map(map, x, y-1);
}

int	ronceY(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (1); // le chemin est trouvé, on retourne 1
	if (map[y][x] == 'C' || map[y][x] == 'X')
		return (0); // chemin impossible, on retourne 0
	// marquer la position actuelle
	map[y][x] = 'X';
	// appel récursif pour les voisins
	if (ronceY(map, x+1, y) == 1)
		return (1);
	if (ronceY(map, x-1, y) == 1)
		return (1);
	if (ronceY(map, x, y+1) == 1)
		return (1);
	if (ronceY(map, x, y-1) == 1)
		return (1);
	// pas de chemin trouvé, on démarque la position
	map[y][x] = '0';
	return (0);
}

// fonction d'interface
int	findPath(char **map)
{
	int	x;
	int	y;
	int	found;

	x = 0;
	y = 0;
	found = 0;
	// trouver la position du personnage
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				found = 1;
				break ;
			}
			x++;
		}
		if (found == 1)
			break ;
		x = 0;
		y++;
	}
	fill_map(map, x, y);
	// appeler la fonction récursive à partir de la position du personnage
	return (ronceY(map, x, y));
}
 */