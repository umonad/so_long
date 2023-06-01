NAME = so_long
SRC = so_long.c\
	checkMap.c\
	fullfillMap.c\
	walk.c\
	free.c\
	display.c\
	display_next.c\
	verif.c\
	init.c
OBJ = $(SRC:.c=.o)
CC = gcc -g3
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror 
LIBFT_LIB = libft/libft.a
MLX = mlx_linux/libmlx.a
MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz



all : $(NAME)

$(LIBFT_LIB) : 
		make -C libft so_long

$(MLX):
		make -C mlx_linux

$(NAME) : $(OBJ) $(LIBFT_LIB) $(MLX)
		make -C libft so_long
		make -C mlx_linux
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(MLX) $(MLX_FLAGS)

clean :
		make -C libft clean
		make -C mlx_linux clean
		$(RM) $(OBJ)

fclean:		clean
		make -C libft fclean
		$(RM) $(NAME)

re:		fclean $(NAME)
