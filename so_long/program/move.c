/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:08:27 by nliu              #+#    #+#             */
/*   Updated: 2023/11/03 20:38:34 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	moves(t_game *game, char *str)
{
	t_image	image;

	image.relative_path = "./img/stone.xpm";
	image.wlx = *game;
	ft_printf("MOVES: %s\n", str);
	put_image(image, 17 * 48, 0);
	put_image(image, 17 * 48 + 50, 0);
	mlx_string_put(image.wlx.mlx, image.wlx.window,
		17 * 48, 20, 0x00FF66, "MOVES:");
	mlx_string_put(image.wlx.mlx, image.wlx.window,
		17 * 48 + 60, 20, 0x00FF66, str);
	free(str);
}

void	right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/shiteater.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x + 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.action++;
		str = ft_itoa(game->player.action);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/left.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x - 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.action++;
		str = ft_itoa(game->player.action);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/shiteater.xpm";
	image.wlx = *game;
	i = game->player.y - 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.action++;
		str = ft_itoa(game->player.action);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/shiteater.xpm";
	image.wlx = *game;
	i = game->player.y + 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.action++;
		str = ft_itoa(game->player.action);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}
