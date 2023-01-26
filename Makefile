NAME = so_long
SRC = so_long.c
OBJ = $(SRC:.c=.o)
CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
LIBFT_LIB = libft/libft.a



all : $(NAME)

$(LIBFT_LIB) : 
		make -C libft so_long

$(NAME) : $(OBJ) $(LIBFT_LIB) 
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) 

clean :
		make -C libft fclean 
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)