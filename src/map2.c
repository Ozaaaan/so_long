/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:05 by ozdemir           #+#    #+#             */
/*   Updated: 2024/02/12 18:25:56 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_rectangle(char **tab)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	while (tab[i][j])
		j++;
	max = j;
	i++;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (j != max)
			exit_error("Map is not rectangle");
		i++;
	}
}

int	path_check(t_map *map, int start_x, int start_y, int **visited)
{
	int	lig;
	int	col;

	lig = count_tab(map->tab);
	col = ft_strlen(map->tab[0]);
	if (start_x < 0 || start_y < 0 || start_x >= lig || start_y >= col
		|| visited[start_x][start_y] == 1 || map->tab[start_x][start_y] == '1')
		return (0);
	visited[start_x][start_y] = 1;
	if (map->tab[start_x][start_y] == 'C')
	{
		map->collectible_count--;
		if (map->collectible_count == 0)
			return (1);
	}
	else if (map->tab[start_x][start_y] == 'E' && map->collectible_count == 0)
		return (1);
	if (path_check(map, start_x - 1, start_y, visited) || path_check(map,
			start_x + 1, start_y, visited) || path_check(map, start_x, start_y
			- 1, visited) || path_check(map, start_x, start_y + 1, visited))
		return (1);
	return (0);
}

int	**malloc_visited(t_map *map, int ligs, int cols)
{
	int	i;

	i = 0;
	map->visited = malloc(sizeof(int *) * ligs);
	if (!map->visited)
		exit_error("malloc failed");
	while (i < ligs)
	{
		map->visited[i] = malloc(sizeof(int *) * cols);
		if (!map->visited[i])
			exit_error("malloc failed");
		i++;
	}
	return (map->visited);
}

int	check_valid_path(t_map *map)
{
	int	lig;
	int	col;
	int	i;
	int	j;

	lig = count_tab(map->tab);
	col = ft_strlen(map->tab[0]);
	malloc_visited(map, lig, col);
	i = 0;
	while (i < lig)
	{
		j = 0;
		while (j < col)
		{
			map->visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (path_check(map, map->player_start[0], map->player_start[1],
			map->visited));
}

void	start_xy(t_map *map, int lig, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < lig)
	{
		j = 0;
		while (j < col)
		{
			if (map->tab[i][j] == 'P')
			{
				map->player_start[0] = i;
				map->player_start[1] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
