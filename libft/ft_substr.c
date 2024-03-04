/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:28:29 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/22 22:58:17 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_len(char const *s, unsigned int start, size_t len)
{
	size_t	sz;

	sz = 0;
	while (s[start++] && sz < len)
		sz++;
	return (sz);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*nstr;

	i = 0;
	if (s[0] == 0 || start > ft_strlen(s))
	{
		nstr = ft_calloc(1, 1);
		return (nstr);
	}
	nstr = malloc(sizeof(char) * (new_len(s, start, len) + 1));
	if (!nstr)
	{
		return (NULL);
	}
	while (i < len && s[start])
		nstr[i++] = s[start++];
	nstr[i] = 0;
	return (nstr);
}
