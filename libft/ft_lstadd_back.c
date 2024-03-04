/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:19:09 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/25 21:27:10 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	i = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (i->next)
			i = i->next;
		i->next = new;
	}
}

/*lst: The address of a pointer to the first link of
a list.*/
/*new: The address of a pointer to the node to be
added to the list.*/