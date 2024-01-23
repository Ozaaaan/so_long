/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:05 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/23 16:34:40 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_rectangle(char **tab)
{
	int     i;
	int     j;
	int     max;

	i = 0;
	j = 0;
	while(tab[i][j])
		j++;
	max = j;
	i++;
	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
			j++;
		if (j != max)
			exit_error("Map is not rectangle");
		i++;
	}
	return(0);
}
int	path_check(char **tab)
{
	
}

int	check_valid_path(char **tab, int lig, int col)
{
	int	lig_start;
	int	col_start;
	int	i;
	int	j;
	int	**visited;

	i = 0;
	while (i < lig)
	{
		j = 0;
		while (j < col)
		{
			if (tab[i][j] == 'P')
			{
				lig_start = i;
				col_start = j;
				
				break;
			}
			j++;
		}
		i++;
	}
	visited[count_tab(tab)][ft_strlen(tab[0])] = 0;
}

int	start_xy(t_map *map, int lig, int col)
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
			if (map->tab[i][j] == 'P')
			{
				lig_start = i;
				col_start = j;
				map->player_start[0] = lig_start;
				map->player_start[0] = col_start;
				break;
			}
			j++;
		}
		i++;
	}
}

