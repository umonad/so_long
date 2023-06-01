/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:47:39 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/01 02:14:57 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_player(t_data *data, int x, int y)
{
	data->perso.perso_position.x = x * GAMESIZE;
	data->perso.perso_position.y = y * GAMESIZE;
	mlx_put_image_to_window(data->mlx, data->win, data->perso.reference,
		data->perso.perso_position.x, data->perso.perso_position.y);
}

void	display_floor(t_data *data, int x, int y)
{
	data->sol.sol_position.x = x * GAMESIZE;
	data->sol.sol_position.y = y * GAMESIZE;
	mlx_put_image_to_window(data->mlx, data->win, data->sol.reference,
		data->sol.sol_position.x, data->sol.sol_position.y);
}

void	display_wall(t_data *data, int x, int y)
{
	data->mur.mur_position.x = x * GAMESIZE;
	data->mur.mur_position.y = y * GAMESIZE;
	mlx_put_image_to_window(data->mlx, data->win, data->mur.reference,
		data->mur.mur_position.x, data->mur.mur_position.y);
}

void	display_collectible(t_data *data, int x, int y)
{
	data->colectible.colectible_position.x = x * GAMESIZE;
	data->colectible.colectible_position.y = y * GAMESIZE;
	mlx_put_image_to_window(data->mlx, data->win, data->colectible.reference,
		data->colectible.colectible_position.x,
		data->colectible.colectible_position.y);
}

void	display_exit(t_data *data, int x, int y)
{
	data->exit.exit_position.x = x * GAMESIZE;
	data->exit.exit_position.y = y * GAMESIZE;
	mlx_put_image_to_window(data->mlx, data->win, data->exit.reference,
		data->exit.exit_position.x, data->exit.exit_position.y);
}
