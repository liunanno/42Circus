/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhozkan <muhozkan@student.42.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:03:47 by muhozkan          #+#    #+#             */
/*   Updated: 2022/04/26 01:03:47 by muhozkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	message(BOLDRED"Game Ended\n"ENDC, game);
	map_destroy(game);
	exit(0);
}

void	ft_window_size(t_game *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message(RED"Error\nFile not found\n"ENDC, data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		message(RED"Error\nYour map does not have a .ber extension\n"ENDC, data);
	data->size_x = (ft_line_length(fd) * 48);
	data->size_y = ft_count_lines(fd) * 48;
}
