/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:36:35 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/22 23:46:59 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*nstr;
	size_t	nstart;
	size_t	nend;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1 && ft_strchr(set, s1[i]))
		i++;
	nstart = i;
	i = ft_strlen(s1);
	while (i > nstart && ft_strchr(set, s1[i - 1]))
		i--;
	nend = i;
	nstr = ft_substr(s1, nstart, nend - nstart);
	return (nstr);
}
