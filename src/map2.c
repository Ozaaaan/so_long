/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:05 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/29 12:36:26 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_rectangle(char **tab)
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
	return (0);
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
	show_tab(visited, lig, col);
	if (map->tab[start_x][start_y] == 'C')
	{
		map->collectible_count--;
		if (map->collectible_count == 0)
			return (1);
	}
	else if (map->tab[start_x][start_y] == 'E' && map->collectible_count == 0)
		return (1);
	if (path_check(map, start_x - 1, start_y, visited)
		|| path_check(map, start_x + 1, start_y, visited)
		|| path_check(map, start_x, start_y - 1, visited)
		|| path_check(map, start_x, start_y + 1, visited))
		return (1);
	return (0);
}

int	**malloc_visited(int ligs, int cols)
{
	int	**visited;
	int	i;

	i = 0;
	visited = malloc(sizeof(int *) * ligs);
	if (!visited)
		exit_error("malloc failed");
	while (i < ligs)
	{
		visited[i] = malloc(sizeof(int *) * cols);
		if (!visited[i])
			exit_error("malloc failed");
		i++;
	}
	return (visited);
}

int	check_valid_path(t_map *map)
{
	int	**visited;
	int	lig;
	int	col;
	int	i;
	int	j;

	lig = count_tab(map->tab);
	col = ft_strlen(map->tab[0]);
	visited = malloc_visited(lig, col);
	i = 0;
	while (i < lig)
	{
		j = 0;
		while (j < col)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (path_check(map, map->player_start[0], map->player_start[1],
			visited));
}

t_map	*start_xy(t_map *map, int lig, int col)
{
	int	lig_start;
	int	col_start;
	int	i;
	int	j;

	i = 0;
	while (i < lig)
	{
		j = 0;
		while (j < col)
		{
			select_img(map, i, j);
			if (map->tab[i][j] == 'P')
			{
				lig_start = i;
				col_start = j;
				map->player_start[0] = lig_start;
				map->player_start[1] = col_start;
			}
			j++;
		}
		i++;
	}
	return (map);
}
