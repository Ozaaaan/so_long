/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:45:45 by ozdemir           #+#    #+#             */
/*   Updated: 2024/02/12 18:27:15 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_mlx_params
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}					t_mlx_params;

typedef struct s_map
{
	mlx_t			*mlx;
	t_mlx_params	texture_tab[5];
	char			**tab;
	int				player_start[2];
	int				player_count;
	int				exit_count;
	int				collectible_count;
	int				collectible_count2;
	int				collectible_max;
	int				**visited;

}					t_map;

void				exit_error(char *msg);
void				error_handler(int ac, char **av);
int					map_is_ber(char *filename);
t_map				*check_map(char **tab);
void				wall_checker(char **tab);
char				**tab_map(char *argv);
void				is_rectangle(char **tab);
int					count_line_map(char *argv);
int					count_tab(char **tab);
int					check_valid_path(t_map *map);
void				start_xy(t_map *map, int lig, int col);
void				load_textures(t_map *map);
void				draw_map(t_map *map, int lig, int col);
void				free_map(char **tab);

#endif
