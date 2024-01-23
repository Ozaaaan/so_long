/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:20:42 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/23 16:24:21 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_is_ber(char *filename)
{
	const char *extension = ".ber";
	const char *point = strrchr(filename, '.');
	
	if (point !=NULL && strcmp(point, extension) == 0)
		return(1);
	return(0);
}

int	count_line_map(char *argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if(fd == -1)
		exit_error("fd error");
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}


void	counter(t_map *map)
{
	int	i;
	int	j;

	map->player_count = 0;
	map->exit_count = 0;
	map ->collectible_count = 0;

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
}

t_map	*check_map(char **tab)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("Malloc error");
	map->tab = tab;
	counter(map);
	if (map->player_count != 1 || map->exit_count != 1 ||
		map->collectible_count < 1)
		exit_error("Invalid number of player/exit/collectible");
	return(map);
}
char	**tab_map(char *argv)
{
	char **tab;
	char *line;
	int	i;
	int fd;
	int	nb_line;

	i = 0;
	nb_line = count_line_map(argv);
	tab = malloc(sizeof(char **) * count_line_map(argv) + 1);
	fd = open(argv, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if(i < nb_line)
			line[ft_strlen(line) - 1] = 0;
		tab[i] = line;
		i++;
	}
	tab[i] = NULL;
	close(fd);
	return(tab);
}

void	wall_checker(char **tab)
{
	int	i;
	int	j;
	int	nb_line;
	int	length;

	i = 0;
	nb_line = count_tab(tab);
	while (tab[i])
	{
		if (i == 0 || i == nb_line)
		{
			j = 0;
			while (tab[i][j])
			{
				if(tab[i][j] != '1')
				{
					printf("%d %d", i, j);
					exit_error("Incorrect map");
				}
				j++;
			}
		}
		else
		{
			length = ft_strlen(tab[i]);
			if(tab[i][0] != '1' || tab[i][length - 1] != '1')
				exit_error("Incorrect map2");
		}
		i++;
	}
}
