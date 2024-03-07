/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:19:31 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/06 23:46:46 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include ".minilibx-linux/mlx.h"
# include ".minilibx-linux/mlx_int.h"
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
	char	**mtrx;
	int		mpty;
	int		wall;
	int		coll;
	int		exit;
	int		plyr;
	int		x_start;
	int		y_start;
	int		height;
	int		width;
	int		err;
}				t_map;

typedef struct s_mlxd
{
	void		*window_ptr;
	void		*mlx_ptr;
	void		*map_ptr;
	void		*textures[5];
}				t_mlxd;

void	print_str(char *str);
char	*str_concat(char *s1, char *s2);

//err
void	free_error(char **matrix, int e);
int	error_func(int e);
void	free_matrix(char **matrix);

//-------------------MAP----------------//
t_map map_into_matrix(char **av);
int	dimentions(char **av, t_map *map);
void	free_matrix(char **matrix);

//algo
char **map_cpy(t_map map);
int	maze_solver(int map_coll, int x, int y, char **matrix_cpy);
void	test_maze(t_map map);

// The map can be composed of only these 5 characters:
// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

#endif