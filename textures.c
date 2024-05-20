/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/08 15:12:36 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:33:42 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*floor_texture(mlx_t *mlx, t_image *images)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("images/grass.png");
	if (floor == NULL)
		return (NULL);
	images->floor = mlx_texture_to_image(mlx, floor);
	if (images->floor == NULL)
		return (NULL);
	mlx_delete_texture(floor);
	return (images);
}

t_image	*wall_texture(mlx_t *mlx, t_image *images)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("images/wall.png");
	if (wall == NULL)
		return (NULL);
	images->wall = mlx_texture_to_image(mlx, wall);
	if (images->wall == NULL)
		return (NULL);
	mlx_delete_texture(wall);
	return (images);
}

t_image	*collectable_texture(mlx_t *mlx, t_image *images)
{
	mlx_texture_t	*collectable;

	collectable = mlx_load_png("images/bone.png");
	if (collectable == NULL)
		return (NULL);
	images->collectable = mlx_texture_to_image(mlx, collectable);
	if (images->collectable == NULL)
		return (NULL);
	mlx_delete_texture(collectable);
	return (images);
}

t_image	*player_texture(mlx_t *mlx, t_image *images)
{
	mlx_texture_t	*player;

	player = mlx_load_png("images/dog.png");
	if (player == NULL)
		return (NULL);
	images->player = mlx_texture_to_image(mlx, player);
	if (images->player == NULL)
		return (NULL);
	mlx_delete_texture(player);
	return (images);
}

t_image	*exit_texture(mlx_t *mlx, t_image *images)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("images/kennel.png");
	if (exit == NULL)
		return (NULL);
	images->exit = mlx_texture_to_image(mlx, exit);
	if (images->exit == NULL)
		return (NULL);
	mlx_delete_texture(exit);
	return (images);
}
