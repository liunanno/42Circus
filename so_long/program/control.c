/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:02:12 by nliu              #+#    #+#             */
/*   Updated: 2023/11/03 20:38:53 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	wall_control(t_game *game)
{
	unsigned long	x;
	int				y;

	y = 0;
	while (y < (game->size_y / SIZE))
	{
		x = 0;
		while (x < (game->size_x / SIZE))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				message(RED"Error\nNo enough walls\n"ENDC, game);
			else if ((y == (game->size_y / SIZE - 1)
					|| x == (game->size_x / SIZE - 1))
				&& game->map[y][x] != '1')
				message(RED"Error\nNo enough walls\n"ENDC, game);
			x++;
		}
		y++;
	}
}

void	map_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exitcheck++;
			if (game->map[i][j] == 'N')
				game->enemycheck++;
			j++;
		}
		i++;
	}
	if (game->coincheck == 0)
		message(RED"No shit to eat!\n"ENDC, game);
	if (game->enemycheck == 0)
		message(RED"No hedgehog!\n"ENDC, game);
	if (game->exitcheck == 0)
		message("Error\nNo exit!\n", game);
	if (game->playercheck != 1)
		message("Error\nOnly one player\n", game);
}

void	game_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->coincheck++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * SIZE;
				game->player.y = i * SIZE;
				game->playercheck++;
			}
			j++;
		}
		i++;
	}
	map_control(game);
	wall_control(game);
}

int	move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'N')
		message(RED"You have eaten a hedgehog!\n", game);
	else if (game->map[i][j] == 'C')
	{
		game->player.coin++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->coincheck)
		{
			ft_printf(RED"Did you eat all shits?\n"ENDC);
			return (1);
		}
		message(GREEN"You have eaten all shits\n"ENDC, game);
		return (0);
	}
	return (0);
}
