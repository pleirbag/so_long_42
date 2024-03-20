/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:48:25 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/20 16:52:55 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	whats_there(t_map *map, t_mlxd *mlxd)
{
	if ((*map).mtrx[(*map).y_start][(*map).x_start] == 'C')
	{
		(*map).coll_nbr--;
		(*map).mtrx[(*map).y_start][(*map).x_start] = '0';
	}
	if ((*map).mtrx[(*map).y_start][(*map).x_start] == 'E' && (*map).coll_nbr == 0)
	{
		print_str("You have escaped this dimention");
		close_everything(mlxd);
	}
}

int keyhandler(int keypress, t_mlxd *mlxd)
{
	int	player_x;
	int	player_y;

	printf("Pressed key: %d\n", keypress);
	

	return (0);
}