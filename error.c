/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:44:07 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/06 23:45:53 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	error_func(int e)
{
	if (e == 0)
		print_str("Invalid Number of Aguments");
	else if (e == 1)
		print_str("Shitty map");
	else if (e == 4)
		print_str("your map is probably a circle");
	else if (e == 7)
		print_str("your map contains the wrong amount of players/collectables/exit");
	else if (e == 9)
		print_str("invalid path");
	exit(EXIT_FAILURE);
	return (0);
}

void	free_error(char **matrix, int e)
{
	free_matrix(matrix);
	error_func(e);
}
