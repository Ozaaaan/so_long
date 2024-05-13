/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:31:26 by ozdemir           #+#    #+#             */
/*   Updated: 2024/03/07 10:53:07 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_visited(int **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	exit_error(char *msg, t_map *map)
{
	if (map != NULL && map->tab != NULL)
		free_map(map->tab);
	write(2, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	if (map != NULL)
		mlx_terminate(map->mlx);
	exit(EXIT_FAILURE);
}

void	error_handler(int ac, char **av)
{
	if (ac != 2)
		exit_error("Incorrect args", NULL);
	if (map_is_ber(av[1]) != 1)
		exit_error("Map is not .ber", NULL);
}

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
