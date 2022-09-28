NAME = bsq

SRCS = srcs/ft_build_map.c \
       srcs/ft_display_map.c \
       srcs/ft_fill_map.c \
       srcs/ft_free_return.c \
       srcs/ft_init_struct.c \
       srcs/ft_neighbours.c \
       srcs/ft_putstr.c \
       srcs/ft_strjoin.c \
       srcs/ft_strlen.c \
       srcs/main.c

OBJS = $(SRCS:.c=.o)

HDDR = -I includes/

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(HDDR) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(HDDR) -c $< -o $(<:.c=.o)   

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
