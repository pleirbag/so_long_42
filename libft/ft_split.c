/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:00:12 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/20 21:21:52 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_str(char const *s, char c)
{
	int	sz;
	int	i;

	sz = 0;
	i = -1;
	while (s[++i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == 0))
			sz++;
	}
	return (sz);
}

char	*str_mkr(char const *s, char c, char *new_str)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	new_str = malloc(sizeof(char) * i + 1);
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != c)
		new_str[i] = s[i];
	new_str[i] = 0;
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ii;
	char	**matrix;

	i = 0;
	ii = 0;
	matrix = (char **)malloc((nbr_str(s, c) + 1) * sizeof(char *));
	if (matrix == NULL)
	{
		return (NULL);
	}
	while (s[i])
	{
		if (s[i] != c)
		{
			matrix[ii] = str_mkr(&s[i], c, matrix[ii]);
			ii++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	matrix[ii] = NULL;
	return (matrix);
}

// int	main(int ac, char **av)
// {
// 	if (ac >= 3)
// 	{
// 		ft_split(av[1], av[2][0]);
// 	}
// }
