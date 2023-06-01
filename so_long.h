/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:36 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/01 18:54:43 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
# include <X11/XKBlib.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/extensions/XShm.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/ipc.h>
# include <sys/mman.h>
# include <sys/shm.h>
# define GAMESIZE 64

typedef struct s_yx
{
	int		x;
	int		y;
}			t_yx;

typedef struct s_ig
{
	void	*reference;
	void	*image;
	t_yx	colectible_position;
	t_yx	mur_position;
	t_yx	perso_position;
	t_yx	persog_position;
	t_yx	exit_position;
	t_yx	size;
	t_yx	sol_position;
}			t_ig;

typedef struct s_data
{
	int		coup;
	char	**jeux;
	void	*mlx;
	void	*win;
	int		nb_line;
	int		nb_column;
	t_ig	perso;
	t_ig	persog;
	t_ig	mur;
	t_ig	colectible;
	t_ig	exit;
	t_ig	sol;
}			t_data;

typedef int	(*t_verif)(char **map);

/* size_t	findP(char **map); */
void		checking_map(char **map);
int			fullfillmap(char **map, char **argv, int nb_line);
int			countline(char **argv, size_t indexColumn);
int			accesss(char **map);
int			compteur(char **map);
int			ft_input(int key, void *program);
int			check_c(char **map);

// free
void		cleaning_up(t_data *data);
int			freeline(char **map);
int			freemlx(t_data *data);

// verif
int			verifcol(char **map);
int			verifup(char **map);
int			verifdown(char **map);
int			verifleft(char **map);
int			verifright(char **map);

// display
void		display_player(t_data *data, int x, int y);
void		display_floor(t_data *data, int x, int y);
void		display_wall(t_data *data, int x, int y);
void		display_collectible(t_data *data, int x, int y);
void		display_exit(t_data *data, int x, int y);
void		printmap(char **map);
void		ft_displaymap(char **map, t_data *data);

//
bool		img_init(t_data *data);

#endif
