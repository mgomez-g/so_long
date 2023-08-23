/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomez-g <mgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:54:34 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/08/23 15:36:32 by mgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map_reader.h

#ifndef MAP_READER_H
# define MAP_READER_H

# include <stdbool.h>

char	**read_map(const char *filename);
static int	is_ber_file(const char *filename);

#endif
