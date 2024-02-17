/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:35:26 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/03 17:12:23 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbword;
	int		word;
	int		i;

	nbword = ft_countword(s, c);
	tab = (char **)malloc((nbword + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] != '\0' && word < nbword)
	{
		if ((i > 0 && s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
		{
			tab[word] = ft_allocword(s, c, i);
			word++;
		}
		i++;
	}
	tab[word] = NULL;
	return (tab);
}

char	**convert_map(char *filename)
{
	char	**map;
	char	*buffer;
	char	*readed;
	int		fd;

	fd = open(filename, O_RDONLY);
	buffer = malloc(2 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[1] = '\0';
	readed = NULL;
	while (read(fd, buffer, 1) > 0)
	{
		readed = addtoreaded(readed, buffer[0]);
		if (!readed)
			break ;
	}
	close(fd);
	free(buffer);
	map = ft_split(readed, '\n');
	free(readed);
	return (map);
}
