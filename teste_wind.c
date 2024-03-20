/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_wind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:12:42 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/20 15:38:37 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_endr(int keypress, t_mlxd *mlxd)
{
	if (keypress == 65307)
		close_everything(mlxd);
	printf("endr: %d\n", keypress);
	return (0);
}

void	img_loader(t_mlxd *mlxd)
{
	int	i;

	i = 64;
	(*mlxd).plyr = mlx_xpm_file_to_image((*mlxd).mlx_ptr, "./texture/player.xpm", &i, &i);
	(*mlxd).wall = mlx_xpm_file_to_image((*mlxd).mlx_ptr, "./texture/wall.xpm", &i, &i);
	(*mlxd).coll = mlx_xpm_file_to_image((*mlxd).mlx_ptr, "./texture/coll.xpm", &i, &i);
	(*mlxd).exit = mlx_xpm_file_to_image((*mlxd).mlx_ptr, "./texture/exit.xpm", &i, &i);
	(*mlxd).mpty = mlx_xpm_file_to_image((*mlxd).mlx_ptr, "./texture/empty.xpm", &i, &i);
}

void	draw_image(int x, int y, t_map map, t_mlxd mlxd)
{
	if (map.mtrx[y][x] == 'C')
		mlx_put_image_to_window(mlxd.mlx_ptr, mlxd.window_ptr, mlxd.coll, (x * 64), (y * 64));
	if (map.mtrx[y][x] == 'E')
		mlx_put_image_to_window(mlxd.mlx_ptr, mlxd.window_ptr, mlxd.exit, (x * 64), (y * 64));
	if (map.mtrx[y][x] == '1')
		mlx_put_image_to_window(mlxd.mlx_ptr, mlxd.window_ptr, mlxd.wall, (x * 64), (y * 64));
	if (map.mtrx[y][x] == '0' || map.mtrx[y][x] == 'P')
		mlx_put_image_to_window(mlxd.mlx_ptr, mlxd.window_ptr, mlxd.mpty, (x * 64), (y * 64));	
}

void	render_screen(t_map map, t_mlxd mlxd)
{
	int	x;
	int	y;

	y = -1;
	while (map.mtrx[++y] != NULL)
	{
		x = -1;
		while (map.mtrx[y][++x] != '\0')
			draw_image(x, y, map, mlxd);
	}
	printf("%d\n%d\n", map.x_start, map.y_start);
	mlx_put_image_to_window(mlxd.mlx_ptr, mlxd.window_ptr, mlxd.plyr, (map.x_start * 64), (map.y_start * 64));
}

int	close_everything(t_mlxd *mlxd)
{
	mlx_destroy_image((*mlxd).mlx_ptr, (*mlxd).plyr);
	mlx_destroy_image((*mlxd).mlx_ptr, (*mlxd).coll);
	mlx_destroy_image((*mlxd).mlx_ptr, (*mlxd).wall);
	mlx_destroy_image((*mlxd).mlx_ptr, (*mlxd).mpty);
	mlx_destroy_image((*mlxd).mlx_ptr, (*mlxd).exit);
	mlx_destroy_window((*mlxd).mlx_ptr, (*mlxd).window_ptr);
	mlx_destroy_display((*mlxd).mlx_ptr);
	mlx_loop_end((*mlxd).mlx_ptr);
	free((*mlxd).mlx_ptr);
	exit(0);
	return (0);
}

int main (int ac, char **av)
{
	t_mlxd	mlxd;
	t_map	map;

	if (ac != 2)
		error_func(0);
	map = map_into_matrix(av);
	mlxd.mlx_ptr = mlx_init();
	if (!mlxd.mlx_ptr)
		return (1);
	mlxd.window_ptr = mlx_new_window(mlxd.mlx_ptr, (map.width * 64), (map.height * 64), "owo");
	if (!mlxd.window_ptr)
	{
		free(mlxd.window_ptr);
		return (-1); 
	}
	printf("coll :: %d\n", map.coll_nbr);
	img_loader(&mlxd);
	render_screen(map, mlxd);
	mlx_key_hook(mlxd.window_ptr, &keyhandler, &map);
	mlx_hook(mlxd.window_ptr, KeyPress, KeyPressMask, &key_endr, &mlxd);
	mlx_hook(mlxd.window_ptr, DestroyNotify, KeyPressMask, &close_everything, &mlxd);
	mlx_loop(mlxd.mlx_ptr);
	free_matrix(map.mtrx);
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