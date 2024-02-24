/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:26:23 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/24 16:05:08 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_map_rectangle(t_game *game)
{
	size_t	y;

	game->nb_row = count_row(game->map);
	game->nb_col = ft_strlen(game->map[0]);
	if (game->nb_row < 3 || game->nb_col < 3)
		return (map_error(6));
	y = 1;
	while (game->map[y])
	{
		if (ft_strlen(game->map[y]) != game->nb_col)
			return (map_error(7));
		y++;
	}
	return (true);
}

bool	check_map_wall_horizontal(char **map, size_t nb_row)
{
	size_t	x;

	x = 0;
	while (map[0][x] && map[nb_row - 1][x])
	{
		if (map[0][x] != '1' || map[nb_row - 1][x] != '1')
			return (false);
		x++;
	}
	return (true);
}

bool	check_map_wall_vertical(char **map, size_t nb_row, size_t nb_col)
{
	size_t	y;

	y = 0;
	while (y < nb_row)
	{
		if (map[y][0] != '1' || map[y][nb_col - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	check_map_wall(char **map, size_t nb_row, size_t nb_col)
{
	if (!check_map_wall_horizontal(map, nb_row)
		|| !check_map_wall_vertical(map, nb_row, nb_col))
		return (map_error(8));
	return (true);
}

char	**map_cpy(char **map, size_t nb_row, size_t nb_col)
{
	char	**copy;
	size_t	x;
	size_t	y;

	copy = malloc((nb_row + 1) * sizeof(char *));
	y = 0;
	while (map[y])
	{
		copy[y] = malloc((nb_col + 1) * sizeof(char));
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
