/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:49:13 by ozdemir           #+#    #+#             */
/*   Updated: 2024/02/23 13:52:04 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	up(t_map *map, int x, int y)
{
	if (iswall(map, x, y - 32))
	{
		map->texture_tab[2].img->instances[0].y -= 32;
		map->move_cpt++;
		ft_printf("Nombre de pas : %d\n", map->move_cpt);
	}
}

void	down(t_map *map, int x, int y)
{
	if (iswall(map, x, y + 32))
	{
		map->texture_tab[2].img->instances[0].y += 32;
		map->move_cpt++;
		ft_printf("Nombre de pas : %d\n", map->move_cpt);
	}
}

void	left(t_map *map, int x, int y)
{
	if (iswall(map, x - 32, y))
	{
		map->texture_tab[2].img->instances[0].x -= 32;
		map->move_cpt++;
		ft_printf("Nombre de pas : %d\n", map->move_cpt);
	}
}

void	right(t_map *map, int x, int y)
{
	if (iswall(map, x + 32, y))
	{
		map->texture_tab[2].img->instances[0].x += 32;
		map->move_cpt++;
		ft_printf("Nombre de pas : %d\n", map->move_cpt);
	}
}
