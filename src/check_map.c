/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:38:04 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/24 17:36:49 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error_print1(int code)
{
	if (code == 1)
		ft_printf("Error\nDude ! The map don't have the right extension !\n\
How do you think I can read it ? Bruuuh !\n");
	if (code == 2)
		ft_printf("Error\nDude ! You must have only one player on your \
map !\nCome on !\n");
	if (code == 3)
		ft_printf("Error\nDude ! You must have only one exit on your map !\n\
Wake up !\n");
	if (code == 4)
		ft_printf("Error\nDude ! There is an unknown character that I don't \
understand !\nAnd don't say I am too dumb ! You might regret it...\n");
	if (code == 5)
		ft_printf("Error\nDude ! You must have at least one collectible !\n\
Otherwise the game might be so boring... Think !\n");
}

void	map_error_print2(int code)
{
	if (code == 6)
		ft_printf("Error\nDude ! Your map is too small !\n How can you play \
if you can't move ? Duuuh...\n");
	if (code == 7)
		ft_printf("Error\nDude ! You don't have a rectangular map !\n\
Did you read the instructions ?\n");
	if (code == 8)
		ft_printf("Error\nDude ! You must have wall all around the map !\n\
I hope you're not claustrophobic...\n");
	if (code == 9)
		ft_printf("Error\nDude ! You must have at least one valid \
path ! You're not really sharp-minded hm ?\n");
	if (code == 10)
		ft_printf("Error\nDude ! You must have one or less killer on your \
map !\nDon't you think one killer is enough ? C'mon ! Don't be cliche...\n");
}

bool	map_error(int code)
{
	map_error_print1(code);
	map_error_print2(code);
	return (false);
}

bool	check_map(t_game *game)
{
	if (!check_map_extension(game->filename)
		|| !check_map_characters(game)
		|| !check_map_rectangle(game)
		|| !check_map_wall(game->map, game->nb_row, game->nb_col)
		|| !check_map_path(game))
	{
		ft_printf("I hope you fixe this soon because I can come here to take \
care of you !\n");
		return (false);
	}
	return (true);
}
