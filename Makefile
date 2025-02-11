NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./LIBFT
lib = $(LIB_DIR)/libft.a

sources = \
		fdf.c \
		ft_color.c \
		feed_tab.c \
		keys.c \
		mouse.c \
		window.c \
		draw_shape.c \
		draw_line.c \
		draw_parallel.c \
		rotation.c \
		info.c \
		menu.c \
		rectangle.c

object = $(sources:.c=.o)

all: $(NAME) 

$(lib):
	make all -C $(LIB_DIR)

$(NAME): $(object) $(lib)
	$(CC) $(CFLAGS) $(object) ./LIBFT/libft.a -lmlx -lXext -lX11  -lm -o $(NAME)

clean:
	rm -rf $(object)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

flush: re clean
	make clean -C $(LIB_DIR)
	rm -rf $(object)

f: $(object)
	$(CC) $(CFLAGS) $(object) ./LIBFT/libft.a -lmlx -lXext -lX11 -lm -o $(NAME)
	make clean && clear

.SECONDARY: $(object)
.PHONY: clean fclean re all
