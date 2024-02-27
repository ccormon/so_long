/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:05:41 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/27 14:18:26 by ccormon          ###   ########.fr       */
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
# include <stdbool.h>
# include <time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define WIDTH 1920
# define HEIGHT 1200
# define GAME_NAME "Tapas' game"
# define COLLECT_PATH "img/collectible_kibble_32x32.png"
# define EXIT_PATH "img/exit_box_32x32.png"
# define FLOOR_PATH "img/floor_concrete_32x32.png"
# define KILLER_PATH "img/killer_roomba_32x32.png"
# define PLAYER_PATH "img/player_tapas_32x32.png"
# define WALL_PATH "img/wall_bricks_32x32.png"

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
	mlx_image_t		*img_nb_move;
	bool			k_exist;
	t_point			k;
	mlx_texture_t	*tex_killer;
	mlx_image_t		*img_killer;
	double			timer;
	int				move_code;
}	t_game;

// ft_printf
int		ft_printf(const char *format, ...);
int		ft_choice(const char *format, size_t i, va_list arg_list);
//  utils1
int		ft_printfchar(int c);
int		ft_printfhex(unsigned long long n, char *basehex);
int		ft_printfnbr(int n);
int		ft_printfpointer(unsigned long long n, char *basehex);
int		ft_printfstr(char *s);
//  utils2
int		ft_printfunbr(unsigned int n);
void	ft_putchar(int c);
void	ft_puthex(unsigned long long n, char *basehex);
void	ft_putnbr(unsigned int n);
void	ft_putstr(char *str);

// init_game
bool	init_game(t_game *game, char *filename);
void	print_error(void);
//  utils1
char	*ft_strcpy(char *s);
size_t	ft_strlen(char *s);
char	*addtoread(char *s, int c);
int		ft_countword(char const *s, char c);
char	*ft_allocword(char const *s, char c, int const i);
//  utils2
char	**ft_split(char const *s, char c);
char	**convert_map(char *filename);

// check_map
bool	check_map(t_game *game);
void	map_error_print1(int code);
void	map_error_print2(int code);
bool	map_error(int code);
//  utils1
bool	check_map_extension(char *filename);
bool	check_map_characters_p(char **map);
bool	check_map_characters_e(char **map);
bool	check_map_characters_other(char **map);
size_t	count_c(char **map);
//  utils2
void	init_p(t_game *game);
bool	check_map_characters_k(t_game *game);
void	init_k(t_game *game);
bool	check_map_characters(t_game *game);
size_t	count_row(char **map);
//  utils3
bool	check_map_rectangle(t_game *game);
bool	check_map_wall_horizontal(char **map, size_t nb_row);
bool	check_map_wall_vertical(char **map, size_t nb_row, size_t nb_col);
bool	check_map_wall(char **map, size_t nb_row, size_t nb_col);
char	**map_cpy(char **map, size_t nb_row, size_t nb_col);
//  utils4
void	check_map_path_tester(t_game *game, ssize_t p_x, ssize_t p_y);
bool	check_map_path(t_game *game);

// start_game
void	start_game(t_game *game);
//  utils1
void	init_texture(t_game *game);
void	display_map_background(t_game *game);
void	display_map_objects(t_game *game);
void	display_map_player_and_killer(t_game *game);
void	display_map(t_game *game);
//  utils2
size_t	find_c_instance(t_game *game);
char	*ft_stoa(size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	print_nb_move(t_game *game);
void	p_up(t_game *game);
//  utils3
void	p_down(t_game *game);
void	p_left(t_game *game);
void	p_right(t_game *game);
void	key_control(mlx_key_data_t keydata, void *param);
//  utils4
void	k_up(t_game *game);
void	k_down(t_game *game);
void	k_left(t_game *game);
void	k_right(t_game *game);
void	patrol_move(void *param);

// close_game
void	free_map(char **map);
void	free_texture(t_game *game);
// void	close_window(t_game *game);
void	close_game(t_game *game);

#endif
