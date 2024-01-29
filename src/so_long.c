/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:44:22 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/29 15:12:53 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	window(void *maps)
{
	t_map	*map;
	mlx_t			*mlx;
	mlx_image_t		*img;

	map = maps;
	mlx = map->mlx;
	img = map->img;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		img->instances[0].x += 5;
}

t_map	*afficher_image(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "Jeu de fou", true);
	if (!map->mlx)
		exit_error("Erreur mlx init");
	map->texture = mlx_load_png("img/mc1.png");
	if (!map->texture)
		exit_error("Erreur texture");
	map->img = mlx_texture_to_image(map->mlx, map->texture);
	if (!map->img)
		exit_error("Erreur image");
	return (map);
}

int32_t	main(int argc, char **argv)
{
	t_map			*map;
	char			**tab;

	if (argc != 2)
		exit_error("Incorrect args");
	if (map_is_ber(argv[1]) == 1)
	{
		tab = tab_map(argv[1]);
		map = check_map(tab);
		is_rectangle(map->tab);
		wall_checker(map->tab);
		map = start_xy(map, count_tab(tab), ft_strlen(tab[0]));
		if (!check_valid_path(map))
			exit_error("No valid path found");
		initialize_img(map);
		afficher_image(map);
		mlx_image_to_window(map->mlx, map->img, 0, 0);
		mlx_loop_hook(map->mlx, window, &map);
		mlx_loop(map->mlx);
		mlx_terminate(map->mlx);
	}
	else
		exit_error("map is not .ber");
	return (0);
}
