/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:58:42 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/24 18:47:54 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
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
	mlx_key_hook(game->mlx, key_control, game);
	if (game->k_exist)
	{
		srand(1);
		mlx_loop_hook(game->mlx, patrol_move, game);
	}
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
