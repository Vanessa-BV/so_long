/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/08 14:12:11 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:19:18 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hooks(mlx_key_data_t key_data, void *mlx);

t_image	*initialize_images(mlx_t *mlx)
{
	t_image	*images;

	images = ft_calloc(1, sizeof(t_image));
	if (images == NULL)
		return (NULL);
	if (floor_texture(mlx, images) == NULL)
		return (NULL);
	if (wall_texture(mlx, images) == NULL)
		return (NULL);
	if (collectable_texture(mlx, images) == NULL)
		return (NULL);
	if (exit_texture(mlx, images) == NULL)
		return (NULL);
	if (player_texture(mlx, images) == NULL)
		return (NULL);
	return (images);
}

void	place_images_in_window(t_application *game)
{
	place_floor_images_in_window(game);
	place_wall_images_in_window(game);
	place_collectable_images_in_window(game);
	place_exit_images_in_window(game);
	place_player_images_in_window(game);
}

void	create_game(t_application *game)
{
	game->mlx = mlx_init(game->width * PIXELS, \
		game->length * PIXELS, "So_long", false);
	if (game->mlx == NULL)
		exit_error("Could not initialize mlx.", game);
	game->images = initialize_images(game->mlx);
	if (game->images == NULL)
		exit_error("Could not load images.", game);
	place_images_in_window(game);
	mlx_key_hook(game->mlx, key_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
