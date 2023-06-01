/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:36 by mudoh             #+#    #+#             */
/*   Updated: 2023/06/01 19:09:18 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_maxou(t_data *data, int choice)
{
	int						a;
	int						b;
	static const t_verif	funcs[4] = {&verifright, &verifleft, &verifdown, &verifup};
	a = ((choice == 3) * 1) + ((choice == 4) * -1);
	b = ((choice == 1) * 1) + ((choice == 2) * -1);
	if (funcs[choice - 1](data->jeux) == 2 && check_c(data->jeux) == 0)
		freemlx(data);
	if (funcs[choice - 1](data->jeux) == 0)
	{
		data->jeux[data->perso.perso_position.y
			/ 64][(data->perso.perso_position.x / 64)] = '0';
		data->jeux[(data->perso.perso_position.y / 64)
			+ a][(data->perso.perso_position.x / 64) + b] = 'P';
	}
	ft_displaymap(data->jeux, data);
}

int	ft_input(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 65307)
		freemlx(data);
	if (key == 100 || key == 113 || key == 115 || key == 122)
		data->coup += (ft_printf("%d\n", data->coup) > 0);
	if (key == 100 && (verifright(data->jeux) == 0
			|| verifright(data->jeux) == 2))
		input_maxou(data, 1);
	else if (key == 113 && (verifleft(data->jeux) == 0
			|| verifleft(data->jeux) == 2))
		input_maxou(data, 2);
	else if (key == 115 && (verifdown(data->jeux) == 2
			|| verifdown(data->jeux) == 0))
		input_maxou(data, 3);
	else if (key == 122 && (verifup(data->jeux) == 0
			|| verifup(data->jeux) == 2))
		input_maxou(data, 4);
	return (0);
}
//mlx_string_put()

bool	parsing(t_data *data, int argc, char **argv)
{
	(void)argc;
	data->nb_line = countline(argv, data->nb_column);
	if (data->nb_line < 3)
		return (false);
	data->jeux = malloc(sizeof(char *) * (data->nb_line + 1));
	if (!data->jeux)
		return (write(1, "Error malloc\n", 12), false);
	data->nb_column = fullfillmap(data->jeux, argv, data->nb_line);
	if (!data->nb_column)
		return (false);
	checking_map(data->jeux);
	freeline(data->jeux);
	data->jeux = malloc(sizeof(char *) * (data->nb_line + 1));
	if (!data->jeux)
		return (false);
	data->nb_column = fullfillmap(data->jeux, argv, data->nb_line);
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.coup = 1;
	if (argc != 2)
		return (ft_printf("Error METS UNE MAP\n"), 1);
	if (!parsing(&data, argc, argv))
		return (cleaning_up(&data),
			EXIT_FAILURE);
	if (!img_init(&data))
		return (cleaning_up(&data), EXIT_FAILURE);
	ft_displaymap(data.jeux, &data);
	mlx_hook(data.win, 17, 0, freemlx, &data);
	mlx_key_hook(data.win, *ft_input, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
