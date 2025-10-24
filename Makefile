NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./LIBFT
lib = $(LIB_DIR)/libft.a

sources = \
		main.c \
		parsing/ft_color.c \
		parsing/feed_tab.c \
		window/keys.c \
		window/mouse.c \
		window/window.c \
		render/draw_shape.c \
		render/draw_line.c \
		render/draw_parallel.c \
		render/rotation.c \
		render/info.c \
		render/menu.c \
		render/rectangle.c

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

.SECONDARY: $(object)
.PHONY: clean fclean re all
