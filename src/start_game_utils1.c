/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:25:35 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/27 10:45:51 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture(t_game *game)
{
	game->tex_collect = mlx_load_png(COLLECT_PATH);
	game->tex_exit = mlx_load_png(EXIT_PATH);
	game->tex_floor = mlx_load_png(FLOOR_PATH);
	game->tex_player = mlx_load_png(PLAYER_PATH);
	game->tex_wall = mlx_load_png(WALL_PATH);
	if (!game->tex_collect || !game->tex_exit || !game->tex_floor
		|| !game->tex_player || !game->tex_wall)
		return ;
	game->img_collect = mlx_texture_to_image(game->mlx, game->tex_collect);
	game->img_exit = mlx_texture_to_image(game->mlx, game->tex_exit);
	game->img_floor = mlx_texture_to_image(game->mlx, game->tex_floor);
	game->img_player = mlx_texture_to_image(game->mlx, game->tex_player);
	game->img_wall = mlx_texture_to_image(game->mlx, game->tex_wall);
	if (game->k_exist)
	{
		game->tex_killer = mlx_load_png(KILLER_PATH);
		if (!game->tex_killer)
			return ;
		game->img_killer = mlx_texture_to_image(game->mlx, game->tex_killer);
	}
}

void	display_map_background(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img_wall, x * 32, y * 32);
			else
				mlx_image_to_window(game->mlx, game->img_floor, x * 32,
					y * 32);
			x++;
		}
		y++;
	}
}

void	display_map_objects(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img_collect, x * 32,
					y * 32);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img_exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	display_map_player_and_killer(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img_player, x * 32,
					y * 32);
			if (game->k_exist && game->map[y][x] == 'K')
				mlx_image_to_window(game->mlx, game->img_killer, x * 32,
					y * 32);
			x++;
		}
		y++;
	}
}

void	display_map(t_game *game)
{
	display_map_background(game);
	display_map_objects(game);
	display_map_player_and_killer(game);
}
