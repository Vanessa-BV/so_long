/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/23 14:29:59 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:33:30 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "Libft/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

# define PIXELS 64

typedef struct s_image
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collectable;
	mlx_image_t	*exit;
}	t_image;

typedef struct s_application
{
	mlx_t		*mlx;
	char		**map;
	int			width;
	int			length;
	int			total_moves;
	int			total_collectables;
	int			collectables_collected;
	int			player_pos_x;
	int			player_pos_y;
	int			exit_pos_x;
	int			exit_pos_y;
	bool		exit_exists;
	t_image		*images;
}	t_application;

// Utils
void	exit_error(char *error_message, t_application *application);
void	free_application(t_application *application);
void	printf_2d_array(char **map);

// Images and textures
t_image	*floor_texture(mlx_t *mlx, t_image *images);
t_image	*wall_texture(mlx_t *mlx, t_image *images);
t_image	*collectable_texture(mlx_t *mlx, t_image *images);
t_image	*player_texture(mlx_t *mlx, t_image *images);
t_image	*exit_texture(mlx_t *mlx, t_image *images);

void	place_floor_images_in_window(t_application *game);
void	place_wall_images_in_window(t_application *game);
void	place_collectable_images_in_window(t_application *game);
void	place_exit_images_in_window(t_application *game);
void	place_player_images_in_window(t_application *game);

#endif