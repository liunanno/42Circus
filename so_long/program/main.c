/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:07:30 by nliu              #+#    #+#             */
/*   Updated: 2023/11/01 19:56:04 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	update(t_game *game, int x, int y)
{
	t_image	image;

	image.relative_path = "./img/black.xpm";
	image.wlx = *game;
	put_image(image, game->player.x, game->player.y);
	put_image(image, x, y);
}

void	message(char *msg, t_game *game)
{
	printf("%s", msg);
	map_destroy(game);
	exit(0);
}

int	key_check(int key_code, t_game *game)
{
	if (key_code == ESC)
		destroy_window(game);
	if (key_code == UP)
		up(game);
	if (key_code == RIGHT)
		right(game);
	if (key_code == LEFT)
		left(game);
	if (key_code == DOWN)
		down(game);
	return (0);
}

void	game_start(t_game *game)
{
	game->coincheck = 0;
	game->exitcheck = 0;
	game->player.coin = 0;
	game->player.action = 0;
	game->playercheck = 0;
	game->enemycheck = 0;
	game->enemyspeed = 0;
	game->enemyindex = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		message(RED"You should load a map!\n", &game);
	ft_window_size(&game, argv);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx,
			game.size_x, game.size_y, "Shiteater");
	game_start(&game);
	create_map_line(&game, argv);
	game_control(&game);
	mlx_hook(game.window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.window, key_check, &game);
	mlx_loop_hook(game.mlx, anime, &game);
	mlx_loop(game.mlx);
	return (0);
}
