/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:49:42 by aamoussa          #+#    #+#             */
/*   Updated: 2023/01/20 19:56:34 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	check_neighbors(char **map, int i, int j, t_map_data data)
{
	if (j < data.map_width - 1 && map[i][j + 1] == ' ')
		return (true);
	if (j > 0 && map[i][j - 1] == ' ')
		return (true);
	if (i > 0 && map[i - 1][j] == ' ')
		return (true);
	if (i < data.map_height - 1 && map[i + 1][j] == ' ')
		return (true);
	return (false);
}

bool	scan_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
		{
			printf("map has invalid chars\n");
			exit(1);
		}
		i++;
	}
	return (false);
}

void	check_map_walls(char **map, t_map_data data)
{
	int	i;
	int	j;

	i = 0;
	ft_check_first_line(map, data);
	while (map[i])
	{
		scan_line(map[i]);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (check_neighbors(map, i, j, data))
				{
					printf("map is not surrounded by walls\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}
