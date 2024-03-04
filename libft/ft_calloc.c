/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:49:33 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/18 18:32:25 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	int		total;
	int		i;

	i = 0;
	total = nitems * size;
	ptr = malloc(total);
	if (ptr)
	{
		while (i < total)
		{
			ptr[i] = 0;
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
