/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelgomezgomez <manuelgomezgomez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:54:34 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/09/19 14:45:10 by manuelgomez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map_reader.h

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include "graphic_management.h"

char	**read_map(const char *filename);
int     is_ber_file(char *filename);
bool	is_map_rectangular(char **map, int rows);
void	free_map(char **map, int rows);
bool	valid_walls(char **map, int rows);
bool    validar_letras(const char **map);
bool 	verify_map_characters(char **map);
void 	flood_fill(t_game *game, int x, int y);
char 	**duplicate_map(char **map, int rows, int cols);

#endif
