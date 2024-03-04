/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:26:03 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/23 23:38:32 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	str_size(int n)
{
	int	str_sz;

	str_sz = 0;
	if (n == -2147483648)
	{
		n = 2147483647;
		str_sz++;
	}
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n *= -1;
		str_sz++;
	}
	while (n > 0)
	{
		n /= 10;
		str_sz++;
	}
	return (str_sz);
}

void	nbr_putr(int n, char *str, int str_sz)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	if (n == -2147483648)
	{
		str[i++] = 50;
		n = 147483648;
		i++;
	}
	i = str_sz - 1;
	if (n == 0)
		str[0] = 48;
	while (n > 0)
	{
		str[i--] = (n % 10) + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		str_sz;

	str_sz = str_size(n);
	str = (char *)malloc(sizeof(char) * (str_sz + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = 48;
		str[1] = 0;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	nbr_putr(n, str, str_sz);
	str[str_sz] = 0;
	return (str);
}

// int main()
// {
// 	printf("%s\n", ft_itoa(-8));
// }