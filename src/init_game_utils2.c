/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:35:26 by ccormon           #+#    #+#             */
/*   Updated: 2024/03/07 13:21:10 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbword;
	int		word;
	int		i;

	if (!s || !(*s))
		return (NULL);
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
	char	*already_read;
	int		fd;

	buffer = malloc(2 * sizeof(char));
	buffer[1] = '\0';
	fd = open(filename, O_RDONLY);
	if (fd == -1 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		return (NULL);
	}
	already_read = NULL;
	while (read(fd, buffer, 1) > 0)
	{
		already_read = addtoread(already_read, buffer[0]);
		if (!already_read)
			break ;
	}
	close(fd);
	free(buffer);
	map = ft_split(already_read, '\n');
	free(already_read);
	return (map);
}
