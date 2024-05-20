/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_map_from_input.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/23 14:29:44 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/14 15:18:23 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		calculate_rows(char *str);
int		calculate_columns(char *str);

void	create_2d_map(char *map_str, t_application *game)
{
	game->map = ft_split(map_str, '\n');
	if (game->map == NULL)
	{
		free(map_str);
		exit_error("Could not create 2D array.", NULL);
	}
}

char	*reading(char *str, char *temp, int fd)
{
	char	*map_str;

	while (str != NULL)
	{
		map_str = ft_strjoin(temp, str);
		if (map_str == NULL)
		{
			free(str);
			return (free(temp), NULL);
		}
		free(temp);
		temp = map_str;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (map_str);
}

char	*initial_read(char *map)
{
	int		fd;
	char	*map_str;
	char	*str;
	char	*temp;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	temp = ft_strdup("");
	if (temp == NULL)
		return (free(str), NULL);
	map_str = reading(str, temp, fd);
	if (map_str == NULL)
		return (NULL);
	close (fd);
	return (map_str);
}

void	empty_line_check(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
		{
			free(map_str);
			exit_error("Empty line in map", NULL);
		}
		i++;
	}
}

void	create_map_from_input(char *argv, t_application *game)
{
	char	*map_str;

	map_str = initial_read(argv);
	if (map_str == NULL)
		exit_error("Could not read from \
		file to create an initial string.", NULL);
	empty_line_check(map_str);
	game->length = calculate_rows(map_str);
	game->width = calculate_columns(map_str);
	if (game->length < 3 || game->width < 3)
	{
		free(map_str);
		exit_error("Map size is too small", NULL);
	}
	create_2d_map(map_str, game);
	free (map_str);
}
