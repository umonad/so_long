/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 02:00:55 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/02 20:37:35 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maknul(t_data *data)
{
	data->perso.reference = NULL;
	data->mur.reference = NULL;
	data->colectible.reference = NULL;
	data->exit.reference = NULL;
	data->sol.reference = NULL;
}

bool	img_init_bis(t_data *data)
{
	maknul(data);
	data->perso.reference = mlx_xpm_file_to_image(data->mlx, "sprite/perso.xpm",
			&data->perso.size.x, &data->perso.size.y);
	if (!data->perso.reference)
		return (write(2, "Error mlx\n", 10), false);
	data->mur.reference = mlx_xpm_file_to_image(data->mlx, "sprite/mur.xpm",
			&data->mur.size.x, &data->mur.size.y);
	if (!data->mur.reference)
		return (write(2, "Error mlx\n", 10), false);
	data->colectible.reference = mlx_xpm_file_to_image(data->mlx,
			"sprite/colectible.xpm", &data->colectible.size.x,
			&data->colectible.size.y);
	if (!data->colectible.reference)
		return (write(2, "Error mlx\n", 10), false);
	data->exit.reference = mlx_xpm_file_to_image(data->mlx, "sprite/exit.xpm",
			&data->exit.size.x, &data->exit.size.y);
	if (!data->exit.reference)
		return (write(2, "Error mlx\n", 10), false);
	data->sol.reference = mlx_xpm_file_to_image(data->mlx, "sprite/sol.xpm",
			&data->sol.size.x, &data->sol.size.y);
	if (!data->sol.reference)
		return (write(2, "Error mlx\n", 10), false);
	return (true);
}

bool	img_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (write(2, "Error mlx\n", 10), false);
	data->win = mlx_new_window(data->mlx, data->nb_column * GAMESIZE,
			data->nb_line * GAMESIZE, "so_long!");
	if (data->win == NULL)
		return (write(2, "Error mlx\n", 10), false);
	return (img_init_bis(data));
}
