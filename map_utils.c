/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 13:59:05 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/05/06 12:53:01 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calculate_rows(char *str)
{
	int	i;
	int	rows;

	i = 0;
	rows = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			rows++;
		i++;
	}
	return (rows);
}

int	calculate_columns(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	printf_2d_array(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
