/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:24:32 by ozdemir           #+#    #+#             */
/*   Updated: 2024/03/11 13:20:58 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_var(t_map *map)
{
	map->collectible_count = 0;
	map->player_count = 0;
	map->exit_count = 0;
	map->fd = 0;
	map->lig = 0;
	map->col = 0;
	map->direction = 0;
	map->tab = NULL;
	map->visited = NULL;
	map->move_cpt = 0;
	map->found = 0;
}

void	remove_collectible(t_map *map, int x, int y)
{
	int	i;
	int	lig;
	int	col;

	i = 0;
	lig = y / TILE_SIZE;
	col = x / TILE_SIZE;
	if (map->tab[lig][col] == 'C')
	{
		while (i < map->collectible_max)
		{
			if (map->texture_tab[3].img->instances[i].x == x
				&& map->texture_tab[3].img->instances[i].y == y)
			{
				map->texture_tab[3].img->instances[i].enabled = false;
				map->tab[lig][col] = '0';
				map->collectible_count2--;
			}
			i++;
		}
	}
	else if ((map->tab[lig][col] == 'E') && map->collectible_count2 == 0)
		mlx_close_window(map->mlx);
}

int	iswall(t_map *map, size_t x, int y)
{
	if (map->tab[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (0);
	else
		return (1);
}

void	window(mlx_key_data_t keydata, void *param)
{
	t_map	*params;
	int		new_x;
	int		new_y;

	params = param;
	new_x = params->texture_tab[2].img->instances[0].x;
	new_y = params->texture_tab[2].img->instances[0].y;
	if (mlx_is_key_down(params->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(params->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		up(params, new_x, new_y);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		down(params, new_x, new_y);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		left(params, new_x, new_y);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		right(params, new_x, new_y);
	remove_collectible(params, params->texture_tab[2].img->instances[0].x,
		params->texture_tab[2].img->instances[0].y);
}

int	main(int ac, char **av)
{
	t_map	map;

	error_handler(ac, av);
	init_var(&map);
	map.fd = open(av[1], O_RDONLY);
	if (map.fd == -1)
		exit_error("Fichier inexistant", NULL);
	init_map(&map);
	map.mlx = mlx_init(ft_strlen(map.tab[0]) * TILE_SIZE, count_tab(map.tab)
			* TILE_SIZE, "so_long", true);
	check_map(&map);
	is_rectangle(&map);
	start_xy(&map);
	wall_checker(&map);
	if (!check_valid_path(&map))
		exit_error("No valid path found", &map);
	load_textures(&map);
	draw_map(&map);
	mlx_key_hook(map.mlx, window, &map);
	mlx_loop(map.mlx);
	free_map(map.tab);
	mlx_terminate(map.mlx);
	return (0);
}
