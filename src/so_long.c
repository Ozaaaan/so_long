/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:44:22 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/23 16:25:19 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	window(void *param)
{
        mlx_params_t *params = param;
	mlx_t	*mlx = params->mlx;
        mlx_image_t *img = params->img;
        
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


int32_t	main(int argc, char **argv)
{
	mlx_params_t params;
	t_map *map;
	char **tab;

	if (argc != 2)
		exit_error("Incorrect args");
	if (map_is_ber(argv[1]) == 1)
	{
		tab = tab_map(argv[1]);
		map = check_map(tab);
		is_rectangle(map->tab);
		wall_checker(map->tab);
		if (!check_valid_path(map->tab, count_line_map(argv[1]), ft_strlen(map->tab[0])))
			exit_error("No valid path found");
		params.mlx = mlx_init(WIDTH, HEIGHT, "Jeu de fou", true);
		if (!params.mlx)
			exit_error("Erreur mlx init");
		params.texture = mlx_load_png("img/mc1.png");
		if (!params.texture)
			exit_error("Erreur texture");
		params.img = mlx_texture_to_image(params.mlx, params.texture);
		if (!params.img)
			exit_error("Erreur image");
		mlx_image_to_window(params.mlx, params.img, 0, 0);
		mlx_loop_hook(params.mlx, window, &params);
		mlx_loop(params.mlx);
		mlx_terminate(params.mlx);
	}
	else
		exit_error("map is not .ber");
	return(0);
}
