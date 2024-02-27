/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:22:11 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/27 14:06:31 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	size_t	y;

	if (!map || !(*map))
	{
		free(map);
		return ;
	}
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
	if (game->k_exist)
		mlx_delete_texture(game->tex_killer);
}

void	close_game(t_game *game)
{
	free_map(game->map);
	free_texture(game);
}
