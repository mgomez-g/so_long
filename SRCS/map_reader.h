/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomez-g <mgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:54:34 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/08/25 18:35:01 by mgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map_reader.h

#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "graphic_management.h"


char	**read_map(const char *filename);
int is_ber_file(char *filename);

#endif
