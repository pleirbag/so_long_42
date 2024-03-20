/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:47:50 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/20 15:34:11 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "so_long.h"

int	valid_char(char c, t_map *map, int x, int y)
{
	if (c == '0' ||  c == '1')
		return (1);
	else if (c == 'C')
	{
		(*map).coll_nbr++;
		return (1);
	}
	else if (c == 'E')
	{
		(*map).exit_nbr++;
		return (1);
	}
	else if (c == 'P')
	{
		(*map).plyr_nbr++;
		(*map).y_start = y;
		(*map).x_start = x;
		return (1);
	}
	return (0);
}

int check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	walls(t_map map)
{
	int i;

	i = 1;

	if (map.mtrx[0][0] == 0)
		return (-1);
	if (check_line(map.mtrx[0]))
		return (-1);
	if (check_line(map.mtrx[map.height - 1]))
		return (-1);
	while (i < map.height)
	{
		if (map.mtrx[i][0] != '1' || map.mtrx[i][map.width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	dimentions(char **av, t_map *map)
{
	int	fd;
	char *temp;
	int	height;
	int	width;

	height = 0;
	width = 0;
	fd = open(av[1], O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
		error_func(1);
	while (temp[width + 1])
		width++;
	while (temp && temp[0] != '\n')
	{
		free(temp);
		temp = get_next_line(fd);
		height++;
	}
	free(temp);
	(*map).width = width;
	(*map).height = height;
	close(fd);
	return(height * width);
}


int	check_map(t_map *map)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	(*map).exit_nbr = 0;
	(*map).coll_nbr = 0;
	(*map).plyr_nbr = 0;
	while (i < (*map).height)
	{
		cmp = 0;
		while (map->mtrx[i][cmp])
		{
			if (!valid_char(map->mtrx[i][cmp], map, cmp, i))
				free_error(map->mtrx, 7);
			cmp++;	
		}
		if (cmp != (*map).width)
			free_error(map->mtrx, 4);
		i++;
	}
	printf("%d\n%d\n", (*map).y_start, (*map).x_start);
	if (walls(*map) < 0)
		free_error(map->mtrx, 4);
	if ((*map).exit_nbr != 1 || (*map).coll_nbr < 1 || (*map).plyr_nbr != 1)
		free_error(map->mtrx, 7);
	test_maze(*map);
	return (0);
}

int	to_null_ter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && !str[i + 1])
			str[i] = 48;
		else if (str[i] == '\n' && str[i + 1])
			return (-1);
		else
			i++;
	}
	return (0);
}

t_map map_into_matrix(char **av)
{
	char	**matrixx;
	int		i;
	int		fd;
	t_map	map;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (!ft_strnstr(av[1], ".ber\0", ft_strlen(av[1])) 
			|| !dimentions(av, &map))
		error_func(1);
	matrixx = (char **)malloc(sizeof(char*) * (map.height + 1));
	if (!matrixx)
		error_func(5);
	while (i < map.height)
	{
		matrixx[i++] = get_next_line(fd);
		matrixx[i - 1][map.width] = 0;
		printf("%s\n", matrixx[i - 1]);
	}
	matrixx[i] = NULL;
	map.mtrx = matrixx;
	check_map(&map);
	return (map);
}

	// static int	i;
	// char		*(*map).height;

	// (*map).height = get_next_line(fd);
	// if ((*map).height)
	// 	i++;
	// if (!map && i != 0)
	// 	map = malloc(sizeof(char *) * (i + 1));

/*int **map_into_matrix(char **av)
{
	int	fd;
	char **matrixx;
	int	i;
	char		*(*map).height;
	char *temp;

	i = 0;
	matrixx = NULL;
	if (!ft_strnstr(av[1], ".ber\0", ft_strlen(av[1])))
		error_func(1);
	fd = open(av[1], O_RDONLY);
	(*map).height = get_next_line(fd);
	temp = get_next_line(fd);
	free(temp);
	free((*map).height);
	while (1)
	{
		(*map).height = str_concat((*map).height, temp);
		temp = get_next_line(fd);
		i++;
		free(temp);
		free((*map).height);
		if (temp == NULL || (*map).height == NULL)
			break ;
	}
	matrixx = ft_split((*map).height, '\n');
	free_matrix(matrixx);
	return (0);
}*/