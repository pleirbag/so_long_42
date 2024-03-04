/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:48:16 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/18 18:53:07 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t		i;
	char		*s;

	s = (char *)str;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (str);
}

/*int main(int ac, char **av)
{
	char *string;
	printf("str : %s\n", av[1]);
	string = memset(av[1], 'n', 2);
	printf("str : %s\n", string);
} */