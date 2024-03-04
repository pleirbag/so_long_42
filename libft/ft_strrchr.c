/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:42:11 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/19 22:25:51 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if ((char)c == str[i])
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

// int main () {
//    const char str[] = "teste........teste.";
//    const char ch = '.';
//    char *ret;
//    ret = ft_strrchr(str, ch);
//    printf("String after |%c| is - |%s|\n", ch, ret);
//    return(0);
// }