/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:45:45 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/29 14:55:17 by ozdemir          ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 400
# define TILE_SIZE 32

typedef struct s_textab
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}					t_textab;

typedef struct s_map
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	char			**tab;
	t_textab		texture_array[6];
	int				player_start[2];
	int				map_exit[2];
	int				player_count;
	int				exit_count;
	int				collectible_count;

}					t_map;

void				exit_error(char *msg);
int					map_is_ber(char *filename);
t_map				*check_map(char **tab);
void				wall_checker(char **tab);
char				**tab_map(char *argv);
int					is_rectangle(char **tab);
int					count_line_map(char *argv);
int					count_tab(char **tab);
int					check_valid_path(t_map *map);
void				show_tab(int **tab, int lig, int col);
t_map				*start_xy(t_map *map, int lig, int col);
void				select_img(t_map *map, int x, int y);
void				initialize_img(t_map *map);

#endif
