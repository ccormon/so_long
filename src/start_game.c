/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:58:42 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/24 17:29:16 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	double	timer;

	game->mlx = mlx_init(WIDTH, HEIGHT, GAME_NAME, true);
	if (!game->mlx)
		return ;
	init_texture(game);
	if (!game->tex_collect || !game->tex_exit || !game->tex_floor
		|| !game->tex_player || !game->tex_wall)
		return ;
	display_map(game);
	game->nb_move = 0;
	game->img_nb_move = NULL;
	game->nb_c_found = 0;
	timer = mlx_get_time();
	mlx_key_hook(game->mlx, key_control, game);
	if (game->k_exist)
	{
		if (mlx_get_time() - timer > 2)
		{
			mlx_loop_hook(game->mlx, patrol_move, game);
			timer = mlx_get_time();
		}
	}
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
