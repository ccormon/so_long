/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:26:34 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/20 15:18:22 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	find_c_instance(t_game *game)
{
	size_t	c_instance;
	size_t	x;
	size_t	y;

	c_instance = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				if ((ssize_t)x == game->p.x && (ssize_t)y == game->p.y)
					return (c_instance);
				c_instance++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	*ft_stoa(size_t n)
{
	char	*number;
	ssize_t	n_len;
	size_t	n_test;

	n_test = n;
	n_len = 1;
	while (n_test > 9)
	{
		n_test /= 10;
		n_len++;
	}
	number = malloc((n_len + 1) * sizeof(char));
	number[n_len--] = '\0';
	while (n_len >= 0)
	{
		number[n_len--] = '0' + n % 10;
		n /= 10;
	}
	return (number);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	print_nb_move(t_game *game)
{
	char	*nb_move_str;
	size_t	nb;
	size_t	nb_len;

	game->nb_move++;
	if (game->img_nb_move)
		game->img_nb_move->enabled = false;
	nb = game->nb_move;
	nb_len = 1;
	while (nb > 9)
	{
		nb /= 10;
		nb_len++;
	}
	nb_move_str = ft_strjoin("Number of movements : ", ft_stoa(game->nb_move));
	game->img_nb_move = mlx_put_string(game->mlx, nb_move_str, 0, 0);
	free(nb_move_str);
}

void	up(t_game *game)
{
	size_t	c_instance;

	if (game->map[game->p.y - 1][game->p.x] == '1')
		return ;
	game->p.y--;
	game->img_player->instances[0].y -= 32;
	print_nb_move(game);
	if (game->map[game->p.y][game->p.x] == 'C')
	{
		c_instance = find_c_instance(game);
		if (game->img_collect->instances[c_instance].enabled == true)
		{
			game->img_collect->instances[c_instance].enabled = false;
			game->nb_c_found++;
		}
	}
	if (game->map[game->p.y][game->p.x] == 'E'
		&& game->nb_c_found == game->nb_c)
		mlx_close_window(game->mlx);
}
