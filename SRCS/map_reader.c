/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomez-g <mgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:53:25 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/08/22 14:28:07 by mgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "map_reader.h"

char	**read_map(const char *filename)
{
	int		fd;
	char	*line;
	char	**map;
	int		rows;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
    
    
	return (map);
}
