/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:44:22 by ozdemir           #+#    #+#             */
/*   Updated: 2024/02/12 18:26:10 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	if (map->tab[y / TILE_SIZE][x / TILE_SIZE] == '1' || (map->tab[y
			/ TILE_SIZE][x / TILE_SIZE] == 'E' && map->collectible_count2 > 0))
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
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& iswall(params, new_x, new_y - 32))
		params->texture_tab[2].img->instances[0].y -= 32;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& iswall(params, new_x, new_y + 32))
		params->texture_tab[2].img->instances[0].y += 32;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& iswall(params, new_x - 32, new_y))
		params->texture_tab[2].img->instances[0].x -= 32;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& iswall(params, new_x + 32, new_y))
		params->texture_tab[2].img->instances[0].x += 32;
	remove_collectible(params, params->texture_tab[2].img->instances[0].x,
		params->texture_tab[2].img->instances[0].y);
}

int32_t	main(int argc, char **argv)
{
	t_map	*map;
	char	**tab;

	error_handler(argc, argv);
	tab = tab_map(argv[1]);
	map = check_map(tab);
	map->mlx = mlx_init(ft_strlen(tab[0]) * TILE_SIZE, count_tab(tab)
			* TILE_SIZE, "Jeu de fou", true);
	if (!map->mlx)
		exit_error("Erreur mlx init");
	is_rectangle(map->tab);
	wall_checker(map->tab);
	start_xy(map, count_tab(tab), ft_strlen(tab[0]));
	if (!check_valid_path(map))
		exit_error("No valid path found");
	load_textures(map);
	draw_map(map, ft_strlen(tab[0]), count_tab(tab));
	mlx_key_hook(map->mlx, window, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (0);
}
