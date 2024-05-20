/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/23 14:30:03 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:20:34 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game_data(t_application *game);
void	create_map_from_input(char *argv, t_application *game);
void	map_verification(t_application game);
void	initialize_remaining_data(t_application *game);
void	path_check(t_application game);
void	create_game(t_application *game);

void	map_file_type_verification(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4 || ft_strncmp(&file_name[len - 4], ".ber", 4) != 0)
		exit_error("The map needs to be a .ber file.", NULL);
}

int32_t	main(int argc, char **argv)
{
	t_application	game;

	if (argc != 2)
		exit_error("Insert one map. A map needs to be a .ber file.", NULL);
	map_file_type_verification(argv[1]);
	initialize_game_data(&game);
	create_map_from_input(argv[1], &game);
	map_verification(game);
	initialize_remaining_data(&game);
	path_check(game);
	create_game(&game);
	free_application(&game);
	return (EXIT_SUCCESS);
}
