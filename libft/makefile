NAME = libft.a

SRCS = ft_isalnum.c    ft_isprint.c    ft_memcmp.c  ft_putchar_fd.c  ft_split.c    \
					ft_strlcat.c    ft_strncmp.c    ft_substr.c  ft_atoi.c           ft_isalpha.c  \
					ft_itoa.c       ft_memcpy.c     ft_putendl_fd.c ft_strchr.c ft_strlcpy.c  \
					ft_strnstr.c    ft_tolower.c    ft_bzero.c   ft_isascii.c       ft_strrchr.c  \
					ft_memmove.c    ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c       ft_memset.c   \
					ft_toupper.c    ft_calloc.c      ft_isdigit.c ft_memchr.c       ft_striteri.c \
					ft_putstr_fd.c  ft_strjoin.c     ft_strmapi.c ft_strtrim.c  
                    


PRINTF = ft_printf.c ft_put_thing2.c ft_put_things.c 
GNL = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o) 
OBJPRINTF = $(PRINTF:.c=.o)
OBJSGNL = $(GNL:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I. -g

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 
               
so_long: $(OBJS) $(OBJPRINTF) $(OBJSGNL)
	ar rcs $(NAME) $(OBJS) $(OBJPRINTF) $(OBJSGNL)

clean:
	$(RM) $(OBJS) $(OBJPRINTF) $(OBJSGNL)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean so_long re
