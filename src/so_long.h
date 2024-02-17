/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:05:41 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/05 12:31:06 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define WIDTH 1920
# define HEIGHT 1200
# define GAME_NAME "Tapas' game"
# define PLAYER_PATH "img/player_tapas_32x32.png"
# define COLLECT_PATH "img/collectible_kibble_32x32.png"
# define EXIT_PATH "img/exit_box_32x32.png"
# define WALL_PATH "img/wall_bricks_32x32.png"
# define FLOOR_PATH "img/floor_concrete_32x32.png"

typedef struct s_point
{
	ssize_t	x;
	ssize_t	y;
}	t_point;

typedef struct s_game
{
	char			*filename;
	char			**map;
	char			**map_cpy;
	size_t			nb_row;
	size_t			nb_col;
	size_t			nb_c;
	t_point			goal;
	int				check_path_res;
	t_point			p;
	mlx_t			*mlx;
	mlx_texture_t	*tex_collect;
	mlx_texture_t	*tex_exit;
	mlx_texture_t	*tex_floor;
	mlx_texture_t	*tex_player;
	mlx_texture_t	*tex_wall;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_player;
	mlx_image_t		*img_wall;
	size_t			nb_move;
	size_t			nb_c_found;
}	t_game;

// ft_printf
int		ft_printf(const char *format, ...);
int		ft_choice(const char *format, size_t i, va_list arg_list);
int		ft_printfchar(int c);
int		ft_printfhex(unsigned long long n, char *basehex);
int		ft_printfnbr(int n);
int		ft_printfpointer(unsigned long long n, char *basehex);
int		ft_printfstr(char *s);
int		ft_printfunbr(unsigned int n);
void	ft_putchar(int c);
void	ft_puthex(unsigned long long n, char *basehex);
void	ft_putnbr(unsigned int n);
void	ft_putstr(char *str);
// init_game
int		init_game(t_game *game, char *filename);
char	*ft_strcpy(char *s);
size_t	ft_strlen(char *s);
char	*addtoreaded(char *s, int c);
int		ft_countword(char const *s, char c);
char	*ft_allocword(char const *s, char c, int const i);
char	**ft_split(char const *s, char c);
char	**convert_map(char *filename);
// check_map
int		check_map(t_game *game);
void	map_error_print1(int code);
void	map_error_print2(int code);
int		map_error(int code);
int		check_map_extension(char *filename);
int		check_map_characters_p(char **map);
int		check_map_characters_e(char **map);
int		check_map_characters_other(char **map);
size_t	count_c(char **map);
int		check_map_characters(t_game *game);
size_t	count_row(char **map);
int		check_map_rectangle(t_game *game);
int		check_map_wall_horizontal(char **map, size_t nb_row);
int		check_map_wall_vertical(char **map, size_t nb_row, size_t nb_col);
int		check_map_wall(char **map, size_t nb_row, size_t nb_col);
char	**map_cpy(char **map, size_t nb_row, size_t nb_col);
void	check_map_path_tester(t_game *game, ssize_t p_x, ssize_t p_y);
int		check_map_path(t_game *game);
// start_game
void	start_game(t_game *game);
void	init_texture(t_game *game);
void	display_map_background(t_game *game);
void	display_map_objects(t_game *game);
void	display_map_player(t_game *game);
void	display_map(t_game *game);
void	up(t_game *game);
void	key_control(mlx_key_data_t keydata, void *param);
// close_game
void	free_map(char **map);
void	free_texture(t_game *game);
void	close_window(t_game *game);
void	close_game(t_game *game);

#endif
