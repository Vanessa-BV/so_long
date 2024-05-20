/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_input_verification.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/23 15:17:34 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:31:13 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check(t_application game)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (game.map[0][j] != '\0')
	{
		if (game.map[0][j] != '1')
			return (-1);
		j++;
	}
	j = 0;
	while (game.map[game.length - 1][j] != '\0')
	{
		if (game.map[game.length - 1][j] != '1')
			return (-1);
		j++;
	}
	while (i < game.length - 1)
	{
		if (game.map[i][0] != '1' || game.map[i][game.width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	invalid_characters(t_application game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i] != NULL)
	{
		j = 0;
		while (game.map[i][j] != '\0')
		{
			if (game.map[i][j] != '1' && game.map[i][j] != '0' \
			&& game.map[i][j] != 'P' && game.map[i][j] != 'E' \
			&& game.map[i][j] != 'C')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	nmb_occ_pec(t_application game)
{
	int	player_char;
	int	exit_char;
	int	collectable_char;
	int	i;
	int	j;

	player_char = 0;
	exit_char = 0;
	collectable_char = 0;
	i = 0;
	while (game.map[i] != NULL)
	{
		j = 0;
		while (game.map[i][j] != '\0')
		{
			player_char += (game.map[i][j] == 'P');
			exit_char += (game.map[i][j] == 'E');
			collectable_char += (game.map[i][j] == 'C');
			j++;
		}
		i++;
	}
	if (player_char != 1 || exit_char != 1 || collectable_char < 1)
		return (-1);
	return (0);
}

int	is_rectangle(t_application game)
{
	int	i;

	i = 0;
	while (game.map[i] != NULL)
	{
		if (ft_strlen(game.map[i]) != (size_t)game.width)
			return (-1);
		i++;
	}
	return (0);
}

void	map_verification(t_application game)
{
	if (wall_check(game) == -1)
		exit_error("Wall check failed.", &game);
	if (invalid_characters(game) == -1)
		exit_error("Invalid characters.", &game);
	if (nmb_occ_pec(game) == -1)
		exit_error("Invalid number of occurences. \
		Should be: P = 1, E = 1 and C > 1.", &game);
	if (is_rectangle(game) == -1)
		exit_error("Map is not a rectangle.", &game);
}
