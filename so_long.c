/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:36 by mudoh             #+#    #+#             */
/*   Updated: 2023/01/30 17:48:20 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	int		chekC;
	int		chekP;
	int		chekE;
	int		fd;
	size_t	indexmay;
	size_t	indexmax;
	size_t	index;
	size_t	index2;
	char	*line;
	char	**string;
	

	if(argc != 2)
		return(write(2, "Error\n vous n'avez pas rentrez le bon nombre d'argument!", 57));
	fd = open(argv[1], O_RDONLY);
	index = 1;
	line = get_next_line(fd);
	if (!line)
		return(write(2,"Error\n", 7));
	while (line)
	{
		line = get_next_line(fd);
		free (line);
		index++;	
	}
	if (index < 3)
		return(write(2,"Error\n", 7));
	if(close(fd) == -1)
		return(write(2,"Error\n", 7));
	fd = open(argv[1], O_RDONLY);
	
	string = malloc(sizeof (char*) * (index + 1));
	if (!string)
		return(0);
	string[index] = NULL;
	index = 1;
	string[0] = get_next_line(fd);
	while (string[index])
	{
		string[index] = get_next_line(fd);
		index++;
	}
	index = 0;
	while(string[index + 1])
	{
		if(ft_strlen(string[index]) != ft_strlen(string[index + 1]))
			return(write(2,"Error\n", 7));
		index++;
	}
	indexmay = index + 1;
	index = 0;
	while(string[index])
	{
		if(string[index][0] != '1' || string[index][indexmay])	
			return(write(2,"Error\n", 7));
		index++;
	}
	index = 0;
	indexmax = ft_strlen(string[0]);
	while(string[0][index] && string[indexmax][index])
	{
		if(string[0][index] != '1' || string[indexmax][index] != '1')
			return(write(2,"Error\n", 7));
		index++;
	}
	index = 0;
	index2 = 0;
	while(string[index][index2] != string[indexmax][indexmay])
	{
		while(string[index][index2] != string[index][indexmay])
		{
			if(string[index][index2] == 'C')
				chekC = 1;
			if(string[index][index2] == 'P')
				chekP = 1;
			if(string[index][index2] == 'E')
				chekE = 1;
			index2++;
		}
		index++;
	}
	
}
