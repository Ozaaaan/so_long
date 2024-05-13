/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:33:30 by ozdemir           #+#    #+#             */
/*   Updated: 2024/03/07 10:46:35 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	path_check(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->lig || y >= map->col
		|| map->visited[x][y] == 1 || map->tab[x][y] == '1')
		return (0);
	map->visited[x][y] = 1;
	if (map->tab[x][y] == 'E')
		map->found = 1;
	if (map->tab[x][y] == 'C')
		map->collectible_count--;
	if (map->collectible_count == 0)
	{
		if (map->found == 1)
			return (1);
	}
	if (path_check(map, x - 1, y) || path_check(map, x + 1, y)
		|| path_check(map, x, y - 1) || path_check(map, x, y + 1))
		return (1);
	return (0);
}

void	malloc_visited(t_map *map)
{
	int	i;

	i = 0;
	map->visited = malloc(sizeof(int *) * (map->lig + 1));
	if (!map->visited)
		exit_error("malloc failed", NULL);
	while (i < map->lig)
	{
		map->visited[i] = malloc(sizeof(int) * map->col);
		if (!map->visited[i])
			exit_error("malloc failed", NULL);
		i++;
	}
	map->visited[i] = NULL;
}

int	check_valid_path(t_map *map)
{
	int	valid;
	int	i;
	int	j;

	malloc_visited(map);
	i = 0;
	while (i < map->lig)
	{
		j = 0;
		while (j < map->col)
		{
			map->visited[i][j] = 0;
			j++;
		}
		i++;
	}
	valid = path_check(map, map->player_start[0], map->player_start[1]);
	free_visited(map->visited);
	return (valid);
}

void	start_xy(t_map *map)
{
	int	i;
	int	j;

	map->lig = count_tab(map->tab);
	map->col = ft_strlen(map->tab[0]);
	i = 0;
	while (i < map->lig)
	{
		j = 0;
		while (j < map->col)
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
