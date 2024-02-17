NAME 		= so_long

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1

CFLAGS 		+= -Wall -Wextra -Werror
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

SRC 		=	src/main.c\
				src/ft_printf.c\
				src/ft_printf_utils1.c\
				src/ft_printf_utils2.c\
				src/init_game.c\
				src/init_game_utils1.c\
				src/init_game_utils2.c\
				src/check_map.c\
				src/check_map_utils1.c\
				src/check_map_utils2.c\
				src/check_map_utils3.c\
				src/close_game.c\
				src/start_game.c\
				src/start_game_utils1.c\
				src/start_game_utils2.c\

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	cmake $(MLX) -B $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(RM) $(LIBMLX)
	$(RM) $(NAME)

clear: fclean
	$(RM) -r $(MLX)

re: fclean all

.PHONY:		all bonus clear clean fclean re
