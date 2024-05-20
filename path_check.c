/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_check.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/08 15:20:48 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:32:31 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map);

int	enclosed_by_wall(char **map, int x, int y)
{
	if (map[y + 1][x] == '1' && map[y - 1][x] == '1' \
	&& map[y][x + 1] == '1' && map[y][x - 1] == '1')
		return (-1);
	return (0);
}

static bool	flood_fill(t_application *temp, int current_x, int current_y)
{
	if (temp->map[current_y][current_x] == '1')
		return (false);
	if (temp->map[current_y][current_x] == 'E')
		temp->exit_exists = true;
	if (temp->map[current_y][current_x] == 'C')
		temp->collectables_collected += 1;
	temp->map[current_y][current_x] = '1';
	if (flood_fill(temp, current_x + 1, current_y))
		return (true);
	if (flood_fill(temp, current_x - 1, current_y))
		return (true);
	if (flood_fill(temp, current_x, current_y + 1))
		return (true);
	if (flood_fill(temp, current_x, current_y - 1))
		return (true);
	return (false);
}

void	initialize_temp_data(t_application *temp, t_application game)
{
	int	i;

	i = 0;
	while (i < game.length)
	{
		temp->map[i] = ft_strdup(game.map[i]);
		i++;
	}
	temp->exit_exists = false;
	temp->collectables_collected = 0;
}

void	path_check(t_application game)
{
	t_application	temp;

	if (enclosed_by_wall(game.map, game.player_pos_x, \
	game.player_pos_y) == -1 || enclosed_by_wall(game.map, game.exit_pos_x, \
	game.exit_pos_y) == -1)
		exit_error("Player or exit is enclosed by a wall.", &game);
	temp.map = ft_calloc(sizeof(char), game.length * game.width);
	if (temp.map == NULL)
		exit_error("Could not create temporary map.", &game);
	initialize_temp_data(&temp, game);
	flood_fill(&temp, game.player_pos_x, game.player_pos_y);
	free_map(temp.map);
	temp.map = NULL;
	if (temp.collectables_collected != game.total_collectables \
	|| temp.exit_exists == false)
		exit_error("Invalid path.", &game);
}
