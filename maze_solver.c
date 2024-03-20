/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:17:55 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/20 15:19:16 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **map_cpy(t_map map)
{
	int	i;
	int	ii;
	char **matrix;

	i = 0;
	matrix = (char **)malloc(sizeof(char *) * (map.height + 1));
	if (!matrix)
		return (NULL);
	while (i < map.height)
	{
		ii = 0;
		matrix[i] = (char *)malloc(sizeof(char) * map.width);
		if (!matrix[i])
			return (NULL);
		while (map.mtrx[i][ii])
		{
			matrix[i][ii] = map.mtrx[i][ii];
			ii++;
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

//counts if you have touched a map_collectiable, and reduces it from total if you have
int	count_map_collectibles( int map_coll, int x, int y, char **matrix_cpy, t_map map)
{
	if (matrix_cpy[y][x] != '1' && matrix_cpy[y][x] != 'b' && matrix_cpy[y][x] == 'E')
	{
		if (matrix_cpy[y][x] == 'C')
		{
			matrix_cpy[y][x] = '0';
			map_coll--;
		}
		return (maze_solver(map_coll, x, y, matrix_cpy, map));
	}
	return (1);
}

void print_mtrx(char **matrx)
{
	int i = 0;
	while (matrx[i])
	{
		printf("%s\n", matrx[i]);
		i++;
	}
	printf("\n");
}

int	maze_solver(int map_coll, int x, int y, char **matrix_cpy, t_map map)
{
	// if (y > map.height || x > map.width)
	// 	return (1);
	if (!map_coll && matrix_cpy[y][x] == 'E')
		return (0);
	if (matrix_cpy[y][x] == 'C')
		map_coll--;	
	if (matrix_cpy[y][x] == '1')
	{
		matrix_cpy[y][x] = 'b';
		return (1);
	}
	else
		matrix_cpy[y][x] = 'b';
	// printf("x == %d y == %d\n", x, y);
	// print_mtrx(matrix_cpy);
	if (!maze_solver(map_coll, x + 1, y, matrix_cpy, map))
		return (0);
	if (!maze_solver(map_coll, x - 1, y, matrix_cpy, map))
		return (0);
	if (!maze_solver(map_coll, x, y + 1, matrix_cpy, map))
		return (0);
	if (!maze_solver(map_coll, x, y - 1, matrix_cpy, map))
		return (0);
	return (1);
}

void	initialize_visits(t_map *map, char **matrix_cpy)
{
	int		x;
	int		y;

	y = 0;
	while (y < (*map).height)
	{
		x = 0;
		while (x < (*map).width)
			matrix_cpy[y][x++] = 0;
		y++;
	}
}

int	allocate_visits(t_map *map, char **matrix_cpy)
{
	int		count;

	matrix_cpy = malloc (sizeof(int *) * (map->height + 2));
	if (matrix_cpy == NULL)
		return (0);
	matrix_cpy[map->height + 1] = NULL;
	count = map->height + 1;
	while (count--)
	{
		matrix_cpy[count] = malloc (sizeof(int) * map->width + 1);
		if (matrix_cpy[count] == NULL)
		{
			while (count < map->width + 1)
				free(matrix_cpy[count++]);
			free(matrix_cpy);
			free_matrix(matrix_cpy);
			error_func(9);
		}
	}
	initialize_visits(map, matrix_cpy);
	return (1);
}

int	flood_fill(t_map *map, int x, int y, char **matrix_cpy)
{
	if ((*map).mtrx[y][x] == '1' || (*map).mtrx[y][x] == 'E' 
			|| matrix_cpy[y][x] == 1)
	{
		if ((*map).mtrx[y][x] == 'E' && matrix_cpy[y][x] == 0)
		{
			(*map).exit_nbr--;
			matrix_cpy[y][x] = 1;
		}
		return (0);
	}
	else
		matrix_cpy[y][x] = 1;
	if ((*map).mtrx[y][x] == 'C')
		(*map).coll_nbr--;
	flood_fill(map, x + 1, y, matrix_cpy);
	flood_fill(map, x - 1, y, matrix_cpy);
	flood_fill(map, x, y + 1, matrix_cpy);
	flood_fill(map, x, y - 1, matrix_cpy);
	return (1);
}

void	test_maze(t_map map)
{
	char **matrix_cpy;

	matrix_cpy = malloc(sizeof(char **) * map.height);
	matrix_cpy = map_cpy(map);
	if (!matrix_cpy)
	{
		free_matrix(matrix_cpy);
		error_func(4);
	}
	flood_fill(&map,map.x_start, map.y_start, matrix_cpy);
	printf("%d", map.coll_nbr);
	if (map.coll_nbr != 0)
	{
		free_matrix(matrix_cpy);
		error_func(9);
	}
	free_matrix(matrix_cpy);
}