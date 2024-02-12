/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:24:44 by ozdemir           #+#    #+#             */
/*   Updated: 2024/02/12 18:27:23 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	error_handler(int ac, char ** av)
{
	if (ac != 2)
		exit_error("Incorrect args");
	if (map_is_ber(av[1]) != 1)
		exit_error("Map is not .ber");
}

int	map_is_ber(char *filename)
{
	const char	*extension = ".ber";
	const char	*point = strrchr(filename, '.');

	if (point != NULL && strcmp(point, extension) == 0)
		return (1);
	return (0);
}

int	count_line_map(char *argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit_error("fd error");
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
