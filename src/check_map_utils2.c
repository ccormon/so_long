/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:35:29 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/24 17:37:23 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_p(t_game *game)
{
	size_t	x;
	size_t	y;

	game->p.x = 0;
	game->p.y = 0;
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
			}
			x++;
		}
		y++;
	}
}

bool	check_map_characters_k(t_game *game)
{
	size_t	nb_k;
	size_t	x;
	size_t	y;

	nb_k = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'K')
				nb_k++;
			x++;
		}
		y++;
	}
	if (nb_k > 1)
		return (map_error(10));
	if (nb_k == 1)
		game->k_exist = true;
	else
		game->k_exist = false;
	return (true);
}

void	init_k(t_game *game)
{
	size_t	x;
	size_t	y;

	game->k.x = 0;
	game->k.y = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'K')
			{
				game->k.x = x;
				game->k.y = y;
			}
			x++;
		}
		y++;
	}
}

bool	check_map_characters(t_game *game)
{
	game->nb_c = count_c(game->map);
	if (game->nb_c < 1)
		return (map_error(5));
	if (!check_map_characters_p(game->map)
		|| !check_map_characters_e(game->map)
		|| !check_map_characters_other(game->map))
		return (false);
	init_p(game);
	if (!check_map_characters_k(game))
		return (false);
	init_k(game);
	return (true);
}

size_t	count_row(char **map)
{
	size_t	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}
