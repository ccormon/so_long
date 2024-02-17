/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:17:28 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/03 17:05:55 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *s)
{
	char	*cpy;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (i == 0)
		return (NULL);
	cpy = malloc((i + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*addtoreaded(char *s, int c)
{
	char	*new_s;
	size_t	i;

	i = 0;
	if (!s)
	{
		new_s = malloc(2 * sizeof(char));
		if (!new_s)
			return (NULL);
	}
	else
	{
		new_s = malloc((ft_strlen(s) + 2) * sizeof(char));
		if (!new_s)
			return (NULL);
		while (s[i])
		{
			new_s[i] = s[i];
			i++;
		}
	}
	new_s[i] = c;
	new_s[i + 1] = '\0';
	free(s);
	return (new_s);
}

int	ft_countword(char const *s, char c)
{
	int	nbword;
	int	i;

	if (s[0] == '\0')
		return (0);
	nbword = 0;
	i = 0;
	if (s[i] != c)
	{
		nbword++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			nbword++;
		i++;
	}
	return (nbword);
}

char	*ft_allocword(char const *s, char c, int const i)
{
	char	*word;
	int		j;

	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
		j++;
	word = malloc((j + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}
