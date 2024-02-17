/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:42:01 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/04 16:03:28 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_extension(char *filename)
{
	size_t	i;

	i = ft_strlen(filename);
	if (i < 5)
		return (map_error(1));
	if (filename[i - 4] == '.'
		&& filename[i - 3] == 'b'
		&& filename[i - 2] == 'e'
		&& filename[i - 1] == 'r')
		return (1);
	return (map_error(1));
}

int	check_map_characters_p(char **map)
{
	size_t	nb_p;
	size_t	x;
	size_t	y;

	nb_p = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				nb_p++;
			if (nb_p > 1)
				return (map_error(2));
			x++;
		}
		y++;
	}
	if (nb_p != 1)
		return (map_error(2));
	return (1);
}

int	check_map_characters_e(char **map)
{
	size_t	nb_e;
	size_t	x;
	size_t	y;

	nb_e = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				nb_e++;
			if (nb_e > 1)
				return (map_error(3));
			x++;
		}
		y++;
	}
	if (nb_e != 1)
		return (map_error(3));
	return (1);
}

int	check_map_characters_other(char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C'
				&& map[y][x] != 'P' && map[y][x] != 'E' )
				return (map_error(4));
			x++;
		}
		y++;
	}
	return (1);
}

size_t	count_c(char **map)
{
	size_t	nb_c;
	size_t	x;
	size_t	y;

	nb_c = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				nb_c++;
			x++;
		}
		y++;
	}
	return (nb_c);
}
