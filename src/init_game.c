/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:12:24 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/27 15:00:38 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	write(2, "Error\nSomething bad happened ! Something very bad...\n",
		ft_strlen("Error\nSomething bad happened ! Something very bad...\n"));
}

bool	init_game(t_game *game, char *filename)
{
	game->filename = ft_strcpy(filename);
	if (!game->filename)
	{
		free(game->filename);
		print_error();
		return (false);
	}
	game->map = convert_map(game->filename);
	if (!game->map)
	{
		free(game->filename);
		free_map(game->map);
		print_error();
		return (false);
	}
	if (!check_map(game))
	{
		free(game->filename);
		free_map(game->map);
		return (false);
	}
	free(game->filename);
	game->timer = 0;
	return (true);
}
