/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:33:16 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/19 21:26:31 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupe;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	dupe = malloc(sizeof(char) * (size + 1));
	if (dupe == NULL)
		return (0);
	ft_memcpy(dupe, s, ft_strlen(s) + 1);
	return (dupe);
}
