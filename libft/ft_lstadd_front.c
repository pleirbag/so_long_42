/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:52:55 by gabpicci          #+#    #+#             */
/*   Updated: 2023/04/25 20:14:34 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* lst: The address of a pointer to the first link of a list.*/

/*new: The address of a pointer to the node to be added to the list.*/
/*new->next is equivalent to (*new).next, i.e. */
/*it gets the member called next from the struct that new points to.
*/