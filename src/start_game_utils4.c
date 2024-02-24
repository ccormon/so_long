/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:19:54 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/24 17:38:15 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	k_up(t_game *game)
{
	if (game->map[game->k.y - 1][game->k.x] == '1')
		return ;
	game->k.y--;
	game->img_killer->instances[0].y -= 32;
	if (game->p.x == game->k.x && game->p.y == game->k.y)
		mlx_close_window(game->mlx);
}

void	k_down(t_game *game)
{
	if (game->map[game->k.y + 1][game->k.x] == '1')
		return ;
	game->k.y++;
	game->img_killer->instances[0].y += 32;
	if (game->p.x == game->k.x && game->p.y == game->k.y)
		mlx_close_window(game->mlx);
}

void	k_left(t_game *game)
{
	if (game->map[game->k.y][game->k.x - 1] == '1')
		return ;
	game->k.x--;
	game->img_killer->instances[0].x -= 32;
	if (game->p.x == game->k.x && game->p.y == game->k.y)
		mlx_close_window(game->mlx);
}

void	k_right(t_game *game)
{
	if (game->map[game->k.y][game->k.x + 1] == '1')
		return ;
	game->k.x++;
	game->img_killer->instances[0].x += 32;
	if (game->p.x == game->k.x && game->p.y == game->k.y)
		mlx_close_window(game->mlx);
}

void	patrol_move(void *param)
{
	t_game	*game;
	int		move;

	game = param;
	srand(1);
	move = rand() % 4;
	if (move == 0)
		k_up(game);
	if (move == 1)
		k_down(game);
	if (move == 2)
		k_left(game);
	if (move == 3)
		k_right(game);
}
