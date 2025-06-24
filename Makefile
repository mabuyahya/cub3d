RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
PURPLE  = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m
RESET   = \033[0m

BOLD    = \033[1m
DIM     = \033[2m
ITALIC  = \033[3m
UNDER   = \033[4m

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_42 = ./lib/MLX42

LIBFT = ./lib/libft

PRINTF = ./lib/ftprintf


VALIDATION_SRC = validate_name_and_argc.c validate_map.c \
				  validate_content.c validate_path.c

PARSING_SRC = read_file.c  read_2d_file.c init_struct.c \
			  parse_content.c parse_map.c


UTILS_SRC = split_utilities.c \

RAY_CASTING_SRC =

VALIDATION = $(addprefix validation/, $(VALIDATION_SRC))
PARSING = $(addprefix parsing/, $(PARSING_SRC))
RAY_CASTING = $(addprefix ray_casting/, $(RAY_CASTING_SRC))
UTILS = $(addprefix utilities/, $(UTILS_SRC))



SRC = $(VALIDATION) \
	  $(PARSING) \
	  $(RAY_CASTING) \
	  $(UTILS) \
	  main.c printing_errors.c  tow_d_array.c freeing.c


SRC_DIR = srcs
OBJ_DIR = objs

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DIR_CREATE = mkdir -p $(OBJ_DIR) $(OBJ_DIR)/validation $(OBJ_DIR)/parsing $(OBJ_DIR)/ray_casting $(OBJ_DIR)/utilities
INCLUDES = -I./includes  -I$(MLX_42)/include -I$(LIBFT) -I$(PRINTF)

LIBS = -L$(MLX_42)/build -lmlx42 -ldl -lglfw -pthread -lm -L$(LIBFT) -lft -L$(PRINTF) -lftprintf

all:  $(MLX_42)/build/libmlx42.a $(LIBFT)/libft.a $(PRINTF)/libftprintf.a $(NAME)
	@printf "$(GREEN)$(BOLD)✅ cub3D is ready!$(RESET)\n"

$(MLX_42)/build/libmlx42.a:
	@printf "$(CYAN)🚀 Building MLX42...$(RESET)\n"
	@cmake $(MLX_42) -B $(MLX_42)/build >/dev/null && make -C $(MLX_42)/build -j4 >/dev/null
	@printf "$(GREEN)✓ MLX42 built successfully$(RESET)\n"

$(LIBFT)/libft.a:
	@printf "$(CYAN)📚 Building libft...$(RESET)\n"
	@make -C $(LIBFT) >/dev/null
	@printf "$(GREEN)✓ Libft built successfully$(RESET)\n"

$(PRINTF)/libftprintf.a:
	@printf "$(CYAN)🖨️  Building ft_printf...$(RESET)\n"
	@make -C $(PRINTF) >/dev/null
	@printf "$(GREEN)✓ Printf built successfully$(RESET)\n"

$(NAME): $(OBJS) includes/cub3d.h includes/cub3d_structs.h
	@printf "$(CYAN)🔨 Linking $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIBS)
	@printf "$(GREEN)✓ Linking complete$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_CREATE)
	@printf "$(CYAN)⚡ Compiling $<...$(RESET)\r"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@printf "$(YELLOW)🧹 Cleaning object files...$(RESET)\n"
	@make -C $(MLX_42)/build clean >/dev/null
	@make -C $(LIBFT) clean >/dev/null
	@make -C $(PRINTF) clean >/dev/null
	@rm -rf $(OBJ_DIR)
	@printf "$(GREEN)✓ Clean complete$(RESET)\n"

fclean: clean
	@printf "$(YELLOW)🗑️  Removing executables...$(RESET)\n"
	@make -C $(LIBFT) fclean >/dev/null
	@make -C $(PRINTF) fclean >/dev/null
	@rm -f $(NAME)
	@printf "$(GREEN)✓ Full clean complete$(RESET)\n"

re: fclean all
	@printf "$(GREEN)♻️  Project rebuilt successfully!$(RESET)\n"

.PHONY: all clean fclean re
