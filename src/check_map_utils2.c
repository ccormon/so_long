/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:35:29 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/20 15:37:49 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_p(t_game *game)
{
	size_t	x;
	size_t	y;

	game->p.x = -1;
	game->p.y = -1;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->p.x = x;
				game->p.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	check_map_characters(t_game *game)
{
	game->nb_c = count_c(game->map);
	if (game->nb_c < 1)
		return (map_error(5));
	if (check_map_characters_p(game->map) == 0
		|| check_map_characters_e(game->map) == 0
		|| check_map_characters_other(game->map) == 0)
		return (0);
	init_p(game);
	return (1);
}

size_t	count_row(char **map)
{
	size_t	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	check_map_rectangle(t_game *game)
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
	return (1);
}

int	check_map_wall_horizontal(char **map, size_t nb_row)
{
	size_t	x;

	x = 0;
	while (map[0][x] && map[nb_row - 1][x])
	{
		if (map[0][x] != '1' || map[nb_row - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}
