/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomez-g <mgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:42:34 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/08/22 13:47:02 by mgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	while (buffer[fd][0] != 0 || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_manage_buffer(buffer[fd]))
			break ;
	}
	return (line);
}