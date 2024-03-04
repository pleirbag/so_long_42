/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:19:31 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/03 20:26:47 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pc
{
	int		x;
	int		y;
	int		col_n;
}				t_pc;

typedef struct s_map
{
	int		mpty;
	int		wall;
	int		coll;
	int		exit;
	int		plyr;
	int		enmy;
}				t_map;

typedef struct s_mlxd
{
	void		*window_ptr;
	void		*mlx_ptr;
	void		*map_ptr;
	void		*textures[5];
}				t_mlxd;

// The map can be composed of only these 5 characters:
// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

#endif