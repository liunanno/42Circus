/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:06:56 by nliu              #+#    #+#             */
/*   Updated: 2023/11/01 19:54:49 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	*put_image(t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx,
			image.relative_path, &image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, x, y);
	return (image.img);
}

t_block	set_block(char name)
{
	t_block	maps[7];
	int		i;

	maps[0] = (t_block){"1", "./img/stone.xpm"};
	maps[1] = (t_block){"0", "./img/black.xpm"};
	maps[2] = (t_block){"C", "./img/shit.xpm"};
	maps[3] = (t_block){"P", "./img/shiteater.xpm"};
	maps[4] = (t_block){"E", "./img/gate.xpm"};
	maps[5] = (t_block){"N", "./img/hedgehog.xpm"};
	maps[6] = (t_block){NULL, NULL};
	i = 0;
	while (maps[i].name != NULL)
	{
		if (maps[i].name[0] == name)
		{
			return (maps[i]);
			break ;
		}
		i++;
	}
	return (maps[6]);
}

void	move_4(t_game *game, int x, int y)
{
	int		i;
	int		j;
	t_image	image;

	image.wlx = *game;
	image.relative_path = "./img/hedgehog.xpm";
	while (game->map[y][x + 1] != '1')
	{
		update2(game, (x * 48), y * 48);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'N';
		i = y * 48;
		j = (x * 48) + 48;
		put_image(image, j, i);
		x++;
	}
}
