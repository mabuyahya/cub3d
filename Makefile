NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_42 = ./MLX42

LIBFT = ./lib/libft

PRINTF = ./lib/ftprintf

SRC = srcs/main.c

OBJS = $(SRC:.c=.o)

INCLUDES = -I./includes  -I$(MLX_42)/include -I$(LIBFT) -I$(PRINTF)

LIBS = -L$(MLX_42)/build -lmlx42 -ldl -lglfw -pthread -lm -L$(LIBFT) -lft -L$(PRINTF) -lftprintf

all:  $(MLX_42)/build/libmlx42.a $(LIBFT)/libft.a $(PRINTF)/libftprintf.a $(NAME)

$(MLX_42)/build/libmlx42.a:
	@cmake $(MLX_42) -B $(MLX_42)/build && make -C $(MLX_42)/build -j4

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIBS)
$(PRINTF)/libftprintf.a:
	@make -C $(PRINTF)

$(NAME): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@make -C $(MLX_42)/build clean
	@make -C $(LIBFT) clean
	@make -C $(PRINTF) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean
	@rm -f $(NAME)

re: fclean all
	@echo "Rebuilding project..."

.PHONY: all clean fclean re
