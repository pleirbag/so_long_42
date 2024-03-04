/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:56:24 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/19 19:23:02 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)s;
	while (n > 0)
	{
		temp[i] = 0;
		i++;
		n--;
	}
}

/* int main(int ac, char **av)
{
	char *str = av[1];

	printf("str : %s\n", av[1]);
	ft_bzero(str, 2);
	printf("str : %s\n", str);
}
*/