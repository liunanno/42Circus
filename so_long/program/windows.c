/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:09:43 by nliu              #+#    #+#             */
/*   Updated: 2023/11/03 20:53:16 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
		message(RED"Error\nFile can't be found\n"ENDC, data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		message(RED"Error\nMap should end with .ber\n"ENDC, data);
	data->size_x = (ft_line_length(fd) * 48);
	data->size_y = ft_count_lines(fd) * 48;
}
