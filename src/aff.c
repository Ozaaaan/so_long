/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:09:08 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/29 14:55:13 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initialize_img(t_map *map)
{
	int	i;
	map->texture_array[0].texture = mlx_load_png("img/arbre.png");
	map->texture_array[1].texture = mlx_load_png("img/sol1.png");
	map->texture_array[2].texture = mlx_load_png("img/sol2.png");
	map->texture_array[3].texture = mlx_load_png("img/mc1.png");
	map->texture_array[4].texture = mlx_load_png("img/potion.png");
	map->texture_array[5].texture = mlx_load_png("img/coffrefin1.png");
	i = 0;
	while (i < 6)
	{
		map->texture_array[i].img = mlx_texture_to_image(map->mlx, map->texture_array[i].texture);
		if (!map->texture_array[i].img)
			exit_error("Erreur img");
		mlx_delete_texture(map->texture_array[i].texture);
		i++;
	}
}

void	select_img(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	if (map->tab[x][y] == '1')
		mlx_image_to_window(map->mlx, map->texture_array[0].img, x * TILE_SIZE, y * TILE_SIZE);
	if (map->tab[x][y] == '0' || map->tab[x][y] == 'P' || map->tab[x][y] == 'C')
	{
		if (i % 2 == 0)
			mlx_image_to_window(map->mlx, map->texture_array[1].img, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_image_to_window(map->mlx, map->texture_array[2].img, x * TILE_SIZE, y * TILE_SIZE);
	}
	if (map->tab[x][y] == 'P')
		mlx_image_to_window(map->mlx, map->texture_array[3].img, x * TILE_SIZE, y * TILE_SIZE);
	if (map->tab[x][y] == 'C')
		mlx_image_to_window(map->mlx, map->texture_array[4].img, x * TILE_SIZE, y * TILE_SIZE);
	if (map->tab[x][y] == 'E')
		mlx_image_to_window(map->mlx, map->texture_array[5].img, x * TILE_SIZE, y * TILE_SIZE);
}