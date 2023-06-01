/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 00:11:55 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/02 18:38:34 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

int	freeline(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		ft_free(map[i]);
		i++;
	}
	ft_free(map);
	return (0);
}

void	cleaning_up(t_data *data)
{
	freeline(data->jeux);
	if (data->colectible.reference)
		mlx_destroy_image(data->mlx, data->colectible.reference);
	if (data->mur.reference)
		mlx_destroy_image(data->mlx, data->mur.reference);
	if (data->perso.reference)
		mlx_destroy_image(data->mlx, data->perso.reference);
	if (data->sol.reference)
		mlx_destroy_image(data->mlx, data->sol.reference);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	ft_free(data->mlx);
}

int	freemlx(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->perso.reference);
	mlx_destroy_image(data->mlx, data->mur.reference);
	mlx_destroy_image(data->mlx, data->sol.reference);
	mlx_destroy_image(data->mlx, data->colectible.reference);
	mlx_destroy_image(data->mlx, data->exit.reference);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	freeline(data->jeux);
	get_next_line(1, 1);
	exit(1);
	return (0);
}
