/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:08:03 by nliu              #+#    #+#             */
/*   Updated: 2023/11/03 20:59:44 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_destroy(t_game	*game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
}

void	create_map(t_game *game, int i)
{
	int		j;
	t_block	map;
	t_image	image;

	image.wlx = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			map = set_block(game->map[i][j]);
			image.relative_path = map.relative_path;
			put_image(image, (j * SIZE), (i * SIZE));
			j++;
		}
		i++;
	}
}

void	create_floor(t_game game, int b)
{
	int		j;
	t_image	image;

	image.wlx = game;
	j = 0;
	if (ft_strlen(game.map[b]) != game.size_x / 48 && b != (game.size_y / 48))
		message(RED"The map is not rectangular\n"ENDC, &game);
	if (game.map[(game.size_y / 48)] && game.map
		[(game.size_y / 48)][0] != '\0')
		message(RED"Wrong map\n"ENDC, &game);
	while (game.map[b])
	{
		j = 0;
		while (game.map[b][j])
		{
			if (!(ft_strchr("1PCE0N", game.map[b][j])))
				message(RED"Error\n"ENDC, &game);
			image.relative_path = "./img/black.xpm";
			put_image(image, (j * SIZE), (b * SIZE));
			j++;
		}
		b++;
	}
}

void	create_map_length(char *area, t_game *game, int i)
{
	int		j;
	t_image	image;

	image.wlx = *game;
	j = 0;
	game->map[i] = (char *)malloc(sizeof(char) * (9999));
	while (area[j])
	{
		if (area[j] == '\n')
			break ;
		game->map[i][j] = area[j];
		j++;
	}
	create_floor(*game, i);
	create_map(game, i);
}

void	create_map_line(t_game *game, char **argv)
{
	int		fd;
	char	*area;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (9999));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i <= game->size_y / 48)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_map_length(area, game, i);
		i++;
		free(area);
	}
	close(fd);
}
