/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:59:47 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/19 21:58:27 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = ft_strlen(dest);
	a = 0;
	if (size <= i || size == 0)
		return (ft_strlen(src) + size);
	while (i + 1 < size && src[a])
		dest[i++] = src[a++];
	dest[i] = 0;
	return (i + ft_strlen(&src[a]));
}
