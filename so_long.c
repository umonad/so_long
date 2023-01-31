/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:36 by mudoh             #+#    #+#             */
/*   Updated: 2023/01/31 22:29:22 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int main(int argc, char **argv)
{
	int		chekC;
	int		chekP;
	int		chekE;
	int		fd;
	size_t	count;
	size_t	indexmay;
	size_t	indexmax;
	size_t	index;
	size_t	index2;
	char	*line;
	char	**string;
	
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
	string = malloc(sizeof (char*) * (count + 1));
	if (!string)
		return(0);
	index = 0;
	string[0] = get_next_line(fd);
	while (string[0][index2])
	{
		if (string[0][index2] == '\n')
			string[0][index2] = '\0';
		index2++;
	}
	while (string[index])
	{
		index2 = 0;
		index++;
		string[index] = get_next_line(fd);
		while (string[index] && string[index][index2])
		{
			if (string[index][index2] == '\n')
				string[index][index2] = '\0';	
			index2++;
			indexmay = index2 - 1;
		}
	}
	index = 0;
	while(string[index + 1])
	{
		if(ft_strlen(string[index]) != ft_strlen(string[index + 1]))
			return(write(2,"Error\n", 7));
		index++;
	}
	index = 0;
	while(string[index])
	{
		if(string[index][0] != '1' || string[index][indexmay] != '1')	
			return(write(2,"Error\n", 7));
		index++;
	}
	index = 0;
	indexmax = count - 2;
	while(string[0][index])
	{
		if(string[0][index] != '1' || string[indexmax][index] != '1')
			return(write(2,"Error\n", 7));
		index++;
	}
	index = 0;
	chekC = 0;
	chekE = 0;
	chekP = 0;
	while(string[index])
	{
		index2 = 0;
		while(string[index][index2])
		{
			if(string[index][index2] == 'C')
				chekC++;
			else if(string[index][index2] == 'P')
				chekP++;
			else if(string[index][index2] == 'E')
				chekE++;
			else if (string[index][index2] != '0' && string[index][index2] != '1')
				return(write(2,"Error\n", 7));
			index2++;
		}
		index++;
	}
	if(chekP != 1 || chekC < 1 || chekE != 1)
		return(write(2,"Error\n", 7));
	index = 0;
	return(write(1,"OK",2));
	ft_printf("%s", string[2]);
	ft_printf("%d", index);
}
