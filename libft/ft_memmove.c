/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:39:49 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/23 23:27:28 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	char		*s;
	size_t		i;

	d = (char *)dest;
	s = (char *)src;
	i = -1;
	if (d == s)
	{
		return (dest);
	}
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (++i < n)
			d[i] = s[i];
	}
	return (dest);
}
