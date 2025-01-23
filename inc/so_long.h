/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:45:45 by ozdemir           #+#    #+#             */
/*   Updated: 2024/03/05 12:03:09 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "MLX42.h"
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
	t_mlx_params	texture_tab[6];
	char			**tab;
	int				**visited;
	int				player_start[2];
	int				player_count;
	int				exit_count;
	int				collectible_count;
	int				collectible_count2;
	int				collectible_max;
	int				fd;
	int				lig;
	int				col;
	int				direction;
	int				move_cpt;
	int				found;
}					t_map;

int					count_tab(char **tab);
int					map_is_ber(char *filename);
int					check_valid_path(t_map *map);
int					iswall(t_map *map, size_t x, int y);
void				free_map(char **tab);
void				free_visited(int **tab);
void				exit_error(char *msg, t_map *map);
void				error_handler(int ac, char **av);
void				init_var(t_map *map);
void				init_map(t_map *map);
void				check_map(t_map *map);
void				is_rectangle(t_map *map);
void				wall_checker(t_map *map);
void				start_xy(t_map *map);
void				load_textures(t_map *map);
void				draw_map(t_map *map);
void				up(t_map *map, int x, int y);
void				down(t_map *map, int x, int y);
void				left(t_map *map, int x, int y);
void				right(t_map *map, int x, int y);
void				aff_map(t_map *map);

#endif
