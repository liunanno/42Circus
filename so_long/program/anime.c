/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:01:26 by nliu              #+#    #+#             */
/*   Updated: 2023/11/01 19:01:51 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	update2(t_game *game, int x, int y)
{
	t_image	image;

	image.relative_path = "./img/black.xpm";
	image.wlx = *game;
	put_image(image, x, y);
}

void	move_2(t_game *game, int x, int y)
{
	int		i;
	int		j;
	t_image	image;

	image.wlx = *game;
	image.relative_path = "./img/hedgehog.xpm";
	if (x * 48 == game->player.x && y * 48 == game->player.y)
		message(RED"You have eaten a hedgehog!\n", game);
	if (game->map[y][x - 1] != '1')
	{
		update2(game, (x * 48), y * 48);
		game->map[y][x] = '0';
		game->map[y][x -1] = 'N';
		i = y * 48;
		j = (x * 48) - 48;
		put_image(image, j, i);
	}
	else if (game->map[y][x + 1] == '0')
		move_4(game, x, y);
}

void	move_1(t_game *game, int x, int y)
{
	t_image	image;

	if (game->enemyindex >= 2)
		game->enemyindex = 0;
	image.wlx = *game;
	if (game->enemyindex == 0)
	{
		image.relative_path = "./img/black.xpm";
		put_image(image, x * 48, y * 48);
		image.relative_path = "./img/shit.xpm";
		put_image(image, x * 48, y * 48);
	}
	if (game->enemyindex == 1)
	{
		image.relative_path = "./img/black.xpm";
		put_image(image, x * 48, y * 48);
		image.relative_path = "./img/smellshit.xpm";
		put_image(image, x * 48, y * 48);
	}
}

void	move_anime(t_game *game)
{
	int				i;
	unsigned long	j;

	i = 0;
	while (i < game->size_y / 48)
	{
		j = 0;
		while (j < game->size_x / 48)
		{
			if (game->map[i][j] == 'N')
				move_2(game, j, i);
			if (game->map[i][j] == 'C')
				move_1(game, j, i);
			j++;
		}
		i++;
	}
	game->enemyindex++;
}

int	anime(t_game	*game)
{
	game->enemyspeed++;
	if (game->enemyspeed >= 3000)
	{
		move_anime(game);
		game->enemyspeed = 0;
	}
	return (0);
}
