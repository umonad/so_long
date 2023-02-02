/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:52 by mudoh             #+#    #+#             */
/*   Updated: 2023/02/02 16:53:19 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	checkRectangle(char **map, int indexLine)
{
	while(map[indexLine + 1])
	{
		if(ft_strlen(map[indexLine]) != ft_strlen(map[indexLine + 1]))
			return(write(2,"Error\n", 7));
		indexLine++;
	}
	return (0);
}

static int	checkBorder(char **map, int indexLine, int indexColumn)
{
	size_t	indexLineMax;
	size_t	indexColumnMax;

	indexLineMax = 0;
	indexColumnMax = 0;
	while(map[0][indexColumnMax])
		indexColumnMax++;
	indexColumnMax--;
	while(map[indexLine])
	{
		if(map[indexLine][0] != '1' || map[indexLine][indexColumnMax] != '1')
			return(write(2,"Error\n", 7));
		indexLine++;
	}
	while (map[indexLineMax])
		indexLineMax++;
	indexLineMax--;
	while(map[0][indexColumn])
	{
		if(map[0][indexColumn] != '1' || map[indexLineMax][indexColumn] != '1')
			return(write(2,"Error\n", 7));
		indexColumn++;
	}
	return (0);
}

static int	checkCharacter(char **map, size_t indexLine, size_t indexColumn)
{
	size_t	check[3];

	check[0] = 0; //check for Coin
	check[1] = 0; //check for Player
	check[2] = 0; //check for Exit
	while(map[indexLine])
	{
		indexColumn = 0;
		while(map[indexLine][indexColumn])
		{
			if(map[indexLine][indexColumn] == 'C')
				check[0]++;
			else if(map[indexLine][indexColumn] == 'P')
				check[1]++;
			else if(map[indexLine][indexColumn] == 'E')
				check[2]++;
			else if (map[indexLine][indexColumn] != '0' && map[indexLine][indexColumn] != '1')
				return(write(2,"Error\n", 7));
			indexColumn++;
		}
		indexLine++;
	}
	if(check[0] < 1 || check[1] != 1 || check[2] != 1)
		return(write(2,"Error\n", 7));
	return (0);
}

void	checkingMap(char **map)
{
	size_t	indexLine;
	size_t	indexColumn;

	indexLine = 0;
	indexColumn = 0;
	if (checkRectangle(map, indexLine) != 0)
		exit (EXIT_FAILURE);
	if (checkBorder(map, indexLine, indexColumn) != 0)
		exit (EXIT_FAILURE);
	if (checkCharacter(map, indexLine, indexColumn) != 0)
		exit (EXIT_FAILURE);
}
