/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_wind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:12:42 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/07 00:03:15 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keyhandler(int keypress, t_mlxd mlxd)
{
	(void)mlxd;
	if (keypress == 65307)
		exit(0);
	printf("Pressed key: %d\n", keypress);
	return (0);
}

int	destroy_window(t_mlxd mlxd)
{
	mlx_destroy_window(mlxd.mlx_ptr, mlxd.window_ptr);
	mlx_destroy_display(mlxd.mlx_ptr);
	free(mlxd.mlx_ptr);
	return (0);
}

int main (int ac, char **av)
{
	t_mlxd	mlxd;
	t_map	map;
	int		fd = ac;

	if (ac != 2)
		error_func(0);
	map = map_into_matrix(av);
	mlxd.mlx_ptr = mlx_init();
	if (!mlxd.mlx_ptr)
		return (1);
	mlxd.window_ptr = mlx_new_window(mlxd.mlx_ptr, 600, 600, "owo");
	if (!mlxd.window_ptr)
	{
		free(mlxd.window_ptr);
		return (-1); 
	}
	fd = open(av[1], O_RDONLY);
	mlx_key_hook(mlxd.window_ptr, &keyhandler, &mlxd);
	mlx_hook(mlxd.window_ptr, DestroyNotify, StructureNotifyMask, &destroy_window, &mlxd);
	mlx_loop(mlxd.mlx_ptr);
	mlx_destroy_window(mlxd.mlx_ptr, mlxd.window_ptr);
	mlx_loop_end(mlxd.mlx_ptr);
	free(mlxd.mlx_ptr);
	close(fd);
	return (0);
}
/* Clients select event reporting of most events relative to a window. 
To do this, pass an event mask to an Xlib event-handling function that takes an event_mask argument. 
The bits of the event mask are defined in <X11/X.h>. Each bit in the event mask maps to an event mask name, 
which describes the event or events you want the X server to return to a client application.

Unless the client has specifically asked for them, most events are not reported to clients when they are generated. 
Unless the client suppresses them by setting graphics-exposures in the GC to False, 
GraphicsExpose and NoExpose are reported by default as a result of XCopyPlane and XCopyArea. 
SelectionClear, SelectionRequest, SelectionNotify, or ClientMessage cannot be masked. 
Selection-related events are only sent to clients cooperating with selections (see section 4.5). 
When the keyboard or pointer mapping is changed, MappingNotify is always sent to clients. */