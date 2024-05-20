/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images_to_window.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/10 13:24:48 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:20:10 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_floor_images_in_window(t_application *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (mlx_image_to_window(game->mlx, game->images->floor, \
			j * PIXELS, i * PIXELS) == -1)
				exit_error("Could not place floor images in window", game);
			j++;
		}
		i++;
	}
}

void	place_wall_images_in_window(t_application *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->images->wall, \
				j * PIXELS, i * PIXELS) == -1)
					exit_error("Could not place wall images in window", game);
			}
			j++;
		}
		i++;
	}
}

void	place_collectable_images_in_window(t_application *game)
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
			{
				if (mlx_image_to_window(game->mlx, game->images->collectable, \
				j * PIXELS, i * PIXELS) == -1)
					exit_error("Could not place collectable \
					images in window", game);
			}
			j++;
		}
		i++;
	}
}

void	place_exit_images_in_window(t_application *game)
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
				if (mlx_image_to_window(game->mlx, game->images->exit, \
				j * PIXELS, i * PIXELS) == -1)
					exit_error("Could not place exit images in window", game);
			}
			j++;
		}
		i++;
	}
}

void	place_player_images_in_window(t_application *game)
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
				if (mlx_image_to_window(game->mlx, game->images->player, \
				j * PIXELS, i * PIXELS) == -1)
					exit_error("Could not place player images in window", game);
			}
			j++;
		}
		i++;
	}
}
