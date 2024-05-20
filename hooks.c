/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:36:04 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/16 13:36:04 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectable_checker(int length, int width, t_application *game);
void	exit_after_collected_all_collectables(t_application *game);

static t_application	*move_up(t_application *game)
{
	if (game->map[game->player_pos_y - 1][game->player_pos_x] != '1')
	{
		game->player_pos_y--;
		game->total_moves++;
		game->images->player->instances->enabled = true;
		game->images->player->instances->y -= PIXELS;
		collectable_checker(game->player_pos_y, game->player_pos_x, game);
		ft_printf("Total moves: %d\n", game->total_moves);
	}
	return (game);
}

static t_application	*move_down(t_application *game)
{
	if (game->map[game->player_pos_y + 1][game->player_pos_x] != '1')
	{
		game->player_pos_y++;
		game->total_moves++;
		game->images->player->instances->enabled = true;
		game->images->player->instances->y += PIXELS;
		collectable_checker(game->player_pos_y, game->player_pos_x, game);
		ft_printf("Total moves: %d\n", game->total_moves);
	}
	return (game);
}

static t_application	*move_right(t_application *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x + 1] != '1')
	{
		game->player_pos_x++;
		game->total_moves++;
		game->images->player->instances->enabled = true;
		game->images->player->instances->x += PIXELS;
		collectable_checker(game->player_pos_y, game->player_pos_x, game);
		ft_printf("Total moves: %d\n", game->total_moves);
	}
	return (game);
}

static t_application	*move_left(t_application *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x - 1] != '1')
	{
		game->player_pos_x--;
		game->total_moves++;
		game->images->player->instances->enabled = true;
		game->images->player->instances->x -= PIXELS;
		collectable_checker(game->player_pos_y, game->player_pos_x, game);
		ft_printf("Total moves: %d\n", game->total_moves);
	}
	return (game);
}

void	key_hooks(mlx_key_data_t key_data, void *mlx)
{
	t_application	*game;

	game = (t_application *)mlx;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (key_data.action == MLX_PRESS)
	{
		if ((key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS) \
		|| (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS))
			move_up(game);
		if ((key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS) \
		|| (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS))
			move_down(game);
		if ((key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS) \
		|| (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS))
			move_right(game);
		if ((key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS) \
		|| (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS))
			move_left(game);
	}
	exit_after_collected_all_collectables(game);
}
