/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_error_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/08 15:21:00 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:18:42 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error_message, t_application *application)
{
	if (application != NULL)
		free_application(application);
	ft_putendl_fd("Error: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map != NULL && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free (map);
}

void	free_application(t_application *application)
{
	if (application->map != NULL)
		free_map(application->map);
	if (application->images != NULL)
		free(application->images);
}
