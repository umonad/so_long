/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:52 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/07 16:57:00 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(char **map, int indexline)
{
	while (map[indexline + 1] && map[indexline + 1][0])
	{
		if (ft_strlen(map[indexline]) != ft_strlen(map[indexline + 1]))
			return (write(2, "Error syntaxe\n", 14), 1);
		indexline++;
	}
	return (0);
}

static int	check_border(char **map, int indexline, int indexcolumn)
{
	size_t	index_l_max;
	size_t	index_c_max;

	index_l_max = 0;
	index_c_max = 0;
	while (map[0][index_c_max])
		index_c_max++;
	index_c_max--;
	while (map[indexline])
	{
		if (map[indexline][0] != '1' || map[indexline][index_c_max] != '1')
			return (write(2, "Error syntaxe\n", 14), 1);
		indexline++;
	}
	while (map[index_l_max])
		index_l_max++;
	index_l_max--;
	while (map[0][indexcolumn])
	{
		if (map[0][indexcolumn] != '1' || map[index_l_max][indexcolumn] != '1')
			return (write(2, "Error syntaxe\n", 14), 1);
		indexcolumn++;
	}
	return (0);
}

static int	check_character(char **map, size_t indexline, size_t indexcolumn)
{
	size_t	check[3];

	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
	while (map[indexline])
	{
		indexcolumn = -1;
		while (map[indexline][++indexcolumn])
		{
			if (map[indexline][indexcolumn] == 'C')
				check[0]++;
			else if (map[indexline][indexcolumn] == 'P')
				check[1]++;
			else if (map[indexline][indexcolumn] == 'E')
				check[2]++;
			else if (map[indexline][indexcolumn] != '0'
					&& map[indexline][indexcolumn] != '1')
				return (write(2, "Error syntaxe\n", 14), 1);
		}
		indexline++;
	}
	if (check[0] < 1 || check[1] != 1 || check[2] != 1)
		return (write(2, "Error syntaxe\n", 14), 1);
	return (0);
}

void	checking_map(char **map)
{
	if (check_rectangle(map, 0) != 0)
	{
		get_next_line(1, 1);
		freeline(map);
		exit(EXIT_FAILURE);
	}
	if (check_border(map, 0, 0) != 0)
	{
		freeline(map);
		exit(EXIT_FAILURE);
	}
	if (check_character(map, 0, 0) != 0)
	{
		freeline(map);
		exit(EXIT_FAILURE);
	}
	if (accesss(map) != 0)
	{
		freeline(map);
		exit(EXIT_FAILURE);
	}
}
