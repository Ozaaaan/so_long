/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:35:25 by ozdemir           #+#    #+#             */
/*   Updated: 2024/03/05 13:21:36 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_is_ber(char *filename)
{
	const char	*extension = ".ber";
	const char	*point = strrchr(filename, '.');

	if (point != NULL && strcmp(point, extension) == 0)
		return (1);
	return (0);
}

void	init_map(t_map *map)
{
	int		i;
	char	*line;
	int		nb_line;

	i = 0;
	line = get_next_line(map->fd);
	nb_line = ft_strlen(line);
	map->tab = malloc(sizeof(char *) * nb_line + 1);
	if (!map->tab)
		exit_error("Malloc error", map);
	while (line != NULL)
	{
		line[ft_strlen(line) - 1] = 0;
		map->tab[i] = line;
		i++;
		line = get_next_line(map->fd);
	}
	map->tab[i] = NULL;
	close(map->fd);
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == 'P')
				map->player_count++;
			else if (map->tab[i][j] == 'E')
				map->exit_count++;
			else if (map->tab[i][j] == 'C')
				map->collectible_count++;
			j++;
		}
		i++;
	}
	map->collectible_max = map->collectible_count;
	map->collectible_count2 = map->collectible_count;
	if (map->player_count != 1 || map->exit_count != 1
		|| map->collectible_count < 1)
		exit_error("Invalid number of player/exit/collectible", map);
}

void	is_rectangle(t_map *map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = ft_strlen(map->tab[i]);
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
			j++;
		if (j != max)
			exit_error("Map is not rectangle", map);
		i++;
	}
}

void	wall_checker(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		if (i == 0 || i == map->lig - 1)
		{
			j = 0;
			while (map->tab[i][j])
			{
				if (map->tab[i][j] != '1')
					exit_error("Incorrect map", map);
				j++;
			}
		}
		else if (map->tab[i][0] != '1' || map->tab[i][ft_strlen(map->tab[i])
			- 1] != '1')
			exit_error("Incorrect map2", map);
		i++;
	}
}
