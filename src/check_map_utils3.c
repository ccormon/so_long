/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:26:23 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/04 14:56:32 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_wall_vertical(char **map, size_t nb_row, size_t nb_col)
{
	size_t	y;

	y = 0;
	while (y < nb_row)
	{
		if (map[y][0] != '1' || map[y][nb_col - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_map_wall(char **map, size_t nb_row, size_t nb_col)
{
	if (check_map_wall_horizontal(map, nb_row) == 0
		|| check_map_wall_vertical(map, nb_row, nb_col) == 0)
		return (map_error(8));
	return (1);
}

char	**map_cpy(char **map, size_t nb_row, size_t nb_col)
{
	char	**copy;
	size_t	x;
	size_t	y;

	copy = malloc((nb_row + 1) * sizeof(char *));
	if (!copy)
		return (0);
	y = 0;
	while (map[y])
	{
		copy[y] = malloc((nb_col + 1) * sizeof(char));
		if (!copy[y])
			return (NULL);
		x = 0;
		while (map[y][x])
		{
			copy[y][x] = map[y][x];
			x++;
		}
		copy[y][x] = '\0';
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

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

int	check_map_path(t_game *game)
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
	return (1);
}
