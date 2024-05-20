/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_game_data.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 13:59:18 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:20:20 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_position(t_application *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_pos_x = j;
				game->player_pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	set_exit_position(t_application *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_pos_x = j;
				game->exit_pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	calculate_collectables(t_application *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				game->total_collectables++;
			j++;
		}
		i++;
	}
}

void	initialize_game_data(t_application *game)
{
	game->map = NULL;
	game->width = 0;
	game->length = 0;
	game->total_moves = 0;
	game->total_collectables = 0;
	game->collectables_collected = 0;
	game->mlx = NULL;
	game->images = NULL;
}

void	initialize_remaining_data(t_application *game)
{
	calculate_collectables(game);
	set_player_position(game);
	set_exit_position(game);
}
