/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:31:45 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/24 16:05:13 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_path_tester(t_game *game, ssize_t p_x, ssize_t p_y)
{
	if (p_x == game->goal.x && p_y == game->goal.y)
	{
		game->check_path_res = 1;
		return ;
	}
	game->map_cpy[p_y][p_x] = 'V';
	if (game->map_cpy[p_y - 1][p_x] && game->map_cpy[p_y - 1][p_x] != '1'
		&& game->map_cpy[p_y - 1][p_x] != 'V')
		check_map_path_tester(game, p_x, p_y - 1);
	if (game->map_cpy[p_y + 1][p_x] && game->map_cpy[p_y + 1][p_x] != '1'
		&& game->map_cpy[p_y + 1][p_x] != 'V')
		check_map_path_tester(game, p_x, p_y + 1);
	if (game->map_cpy[p_y][p_x - 1] && game->map_cpy[p_y][p_x - 1] != '1'
		&& game->map_cpy[p_y][p_x - 1] != 'V')
		check_map_path_tester(game, p_x - 1, p_y);
	if (game->map_cpy[p_y][p_x + 1] && game->map_cpy[p_y][p_x + 1] != '1'
		&& game->map_cpy[p_y][p_x + 1] != 'V')
		check_map_path_tester(game, p_x + 1, p_y);
}

bool	check_map_path(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C' || game->map[y][x] == 'E')
			{
				game->goal.x = x;
				game->goal.y = y;
				game->map_cpy = map_cpy(game->map, game->nb_row, game->nb_col);
				game->check_path_res = 0;
				check_map_path_tester(game, game->p.x, game->p.y);
				free_map(game->map_cpy);
				if (!game->check_path_res)
					return (map_error(9));
			}
			x++;
		}
		y++;
	}
	return (true);
}
