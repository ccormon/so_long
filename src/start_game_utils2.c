/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:26:34 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/04 17:28:40 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	find_c_instance(t_game *game)
{
	size_t	c_instance;
	size_t	x;
	size_t	y;

	c_instance = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				if ((ssize_t)x == game->p.x && (ssize_t)y == game->p.y)
					return (c_instance);
				c_instance++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	up(t_game *game)
{
	size_t	c_instance;

	if (game->map[game->p.y - 1][game->p.x] == '1'
		|| (game->map[game->p.y - 1][game->p.x] == 'E'
		&& game->nb_c_found < game->nb_c))
		return ;
	game->p.y--;
	game->img_player->instances[0].y -= 32;
	game->nb_move++;
	ft_printf("number of movements = %u\n", game->nb_move);
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

void	down(t_game *game)
{
	size_t	c_instance;

	if (game->map[game->p.y + 1][game->p.x] == '1')
		return ;
	if (game->map[game->p.y + 1][game->p.x] == 'E'
		&& game->nb_c_found < game->nb_c)
		return ;
	game->p.y++;
	game->img_player->instances[0].y += 32;
	game->nb_move++;
	ft_printf("number of movements = %u\n", game->nb_move);
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
	if (game->map[game->p.y][game->p.x - 1] == 'E'
		&& game->nb_c_found < game->nb_c)
		return ;
	game->p.x--;
	game->img_player->instances[0].x -= 32;
	game->nb_move++;
	ft_printf("number of movements = %u\n", game->nb_move);
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
	if (game->map[game->p.y][game->p.x + 1] == 'E'
		&& game->nb_c_found < game->nb_c)
		return ;
	game->p.x++;
	game->img_player->instances[0].x += 32;
	game->nb_move++;
	ft_printf("number of movements = %u\n", game->nb_move);
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
