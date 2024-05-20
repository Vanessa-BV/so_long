/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_collectables.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:35:59 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/16 13:35:59 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectable_checker(int length, int width, t_application *game)
{
	int	i;

	i = 0;
	if (game->map[length][width] == 'C')
	{
		while (i < game->total_collectables)
		{
			if (((game->images->collectable->instances[i].y) / PIXELS) == length
				&& ((game->images->collectable->instances[i].x) \
				/ PIXELS) == width)
			{
				game->collectables_collected++;
				game->images->collectable->instances[i].enabled = false;
				game->map[length][width] = '0';
			}
			i++;
		}
	}
}

void	exit_after_collected_all_collectables(t_application *game)
{
	if (game->collectables_collected == game->total_collectables)
	{
		if (game->exit_pos_y == game->player_pos_y
			&& game->exit_pos_x == game->player_pos_x)
			mlx_close_window(game->mlx);
	}
}
