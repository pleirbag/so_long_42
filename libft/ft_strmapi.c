/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:56:13 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/23 22:03:35 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*nstr;

	i = -1;
	nstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	while (s[++i])
		nstr[i] = f(i, s[i]);
	nstr[i] = 0;
	return (nstr);
}
