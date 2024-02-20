/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:22:11 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/20 11:51:54 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	size_t	y;

	y = 0;
	while (map[y])
		free(map[y++]);
	free(map[y]);
	free(map);
}

void	free_texture(t_game *game)
{
	mlx_delete_texture(game->tex_collect);
	mlx_delete_texture(game->tex_exit);
	mlx_delete_texture(game->tex_floor);
	mlx_delete_texture(game->tex_player);
	mlx_delete_texture(game->tex_wall);
}

// void	close_window(t_game *game)
// {
// 	mlx_close_window(game->mlx);
// 	mlx_terminate(game->mlx);
// }

void	close_game(t_game *game)
{
	free(game->filename);
	free_map(game->map);
	free_texture(game);
}
