/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:11:02 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/03 19:51:28 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	if (*find == 0)
		return ((char *)&str[0]);
	while (str[i] && i < len)
	{
		b = 0;
		while (str[i + b] == find[b] && str[i + b] && i + b < len)
		{
			b++;
			if (!find[b])
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
