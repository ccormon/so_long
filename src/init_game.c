/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:12:24 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/24 18:36:48 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *filename)
{
	game->filename = ft_strcpy(filename);
	if (!game->filename)
	{
		free(game->filename);
		return (0);
	}
	game->map = convert_map(game->filename);
	if (!game->map)
	{
		free_map(game->map);
		return (0);
	}
	if (!check_map(game))
	{
		free_map(game->map);
		return (0);
	}
	game->timer = 0;
	return (1);
}
