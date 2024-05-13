/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:46:00 by ozdemir           #+#    #+#             */
/*   Updated: 2024/03/05 13:08:34 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_textures(t_map *map)
{
	int	i;

	map->texture_tab[0].texture = mlx_load_png("img/sol.png");
	map->texture_tab[1].texture = mlx_load_png("img/mega.png");
	map->texture_tab[2].texture = mlx_load_png("img/mc1.png");
	map->texture_tab[3].texture = mlx_load_png("img/potion.png");
	map->texture_tab[4].texture = mlx_load_png("img/coffrefin1.png");
	i = 0;
	while (i < 5)
	{
		map->texture_tab[i].img = mlx_texture_to_image(map->mlx,
				map->texture_tab[i].texture);
		if (!map->texture_tab[i].img)
			exit_error("Erreur img", NULL);
		mlx_delete_texture(map->texture_tab[i].texture);
		i++;
	}
}

void	select_img(t_map *map, int x, int y)
{
	if (map->tab[y][x] == '0' || map->tab[y][x] == 'C' || map->tab[y][x] == 'E'
		|| map->tab[y][x] == 'P')
		mlx_image_to_window(map->mlx, map->texture_tab[0].img, x * TILE_SIZE, y
			* TILE_SIZE);
	if (map->tab[y][x] == '1')
		mlx_image_to_window(map->mlx, map->texture_tab[1].img, x * TILE_SIZE, y
			* TILE_SIZE);
	if (map->tab[y][x] == 'C')
		mlx_image_to_window(map->mlx, map->texture_tab[3].img, x * TILE_SIZE, y
			* TILE_SIZE);
	if (map->tab[y][x] == 'E')
		mlx_image_to_window(map->mlx, map->texture_tab[4].img, x * TILE_SIZE, y
			* TILE_SIZE);
	if (map->tab[y][x] != 'E' && map->tab[y][x] != 'C' && map->tab[y][x] != '1'
		&& map->tab[y][x] != '0' && map->tab[y][x] != 'P')
		exit_error("Incorrect map.ber", map);
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->lig)
	{
		x = 0;
		if (!map->tab[y])
			break ;
		while (x < map->col)
		{
			select_img(map, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(map->mlx, map->texture_tab[2].img, map->player_start[1]
		* TILE_SIZE, map->player_start[0] * TILE_SIZE);
}
