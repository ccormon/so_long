/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:04:51 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/17 19:09:15 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!init_game(&game, argv[1]))
			return (EXIT_FAILURE);
		ft_printf("map OK ;)\n");
		start_game(&game);
		close_game(&game);
	}
	return (EXIT_SUCCESS);
}
