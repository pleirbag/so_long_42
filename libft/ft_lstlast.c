/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:06:34 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/25 20:25:09 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	sz;

	i = 1;
	sz = ft_lstsize(lst);
	if (!lst)
		return (lst);
	while (i < sz)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}
