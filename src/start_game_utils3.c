/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:36:31 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/20 15:18:19 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down(t_game *game)
{
	size_t	c_instance;

	if (game->map[game->p.y + 1][game->p.x] == '1')
		return ;
	game->p.y++;
	game->img_player->instances[0].y += 32;
	game->nb_move++;
	print_nb_move(game);
	if (game->map[game->p.y][game->p.x] == 'C')
	{
		c_instance = find_c_instance(game);
		if (game->img_collect->instances[c_instance].enabled == true)
		{
			game->img_collect->instances[c_instance].enabled = false;
			game->nb_c_found++;
		}
	}
	if (game->map[game->p.y][game->p.x] == 'E'
		&& game->nb_c_found == game->nb_c)
		mlx_close_window(game->mlx);
}

void	left(t_game *game)
{
	size_t	c_instance;

	if (game->map[game->p.y][game->p.x - 1] == '1')
		return ;
	game->p.x--;
	game->img_player->instances[0].x -= 32;
	game->nb_move++;
	print_nb_move(game);
	if (game->map[game->p.y][game->p.x] == 'C')
	{
		c_instance = find_c_instance(game);
		if (game->img_collect->instances[c_instance].enabled == true)
		{
			game->img_collect->instances[c_instance].enabled = false;
			game->nb_c_found++;
		}
	}
	if (game->map[game->p.y][game->p.x] == 'E'
		&& game->nb_c_found == game->nb_c)
		mlx_close_window(game->mlx);
}

void	right(t_game *game)
{
	size_t	c_instance;

	if (game->map[game->p.y][game->p.x + 1] == '1')
		return ;
	game->p.x++;
	game->img_player->instances[0].x += 32;
	game->nb_move++;
	print_nb_move(game);
	if (game->map[game->p.y][game->p.x] == 'C')
	{
		c_instance = find_c_instance(game);
		if (game->img_collect->instances[c_instance].enabled == true)
		{
			game->img_collect->instances[c_instance].enabled = false;
			game->nb_c_found++;
		}
	}
	if (game->map[game->p.y][game->p.x] == 'E'
		&& game->nb_c_found == game->nb_c)
		mlx_close_window(game->mlx);
}

void	key_control(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		right(game);
}
