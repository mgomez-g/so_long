/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomez-g <mgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:53:25 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/08/23 15:33:46 by mgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include "libft/libft.h"

static int	is_ber_file(const char *filename)
{
	const char	*ext;

	ext = ft_strrchr(filename, '.'); // Obtiene un puntero al último punto en el nombre del archivo
	if (ext && ft_strncmp(ext, ".ber", 4) == 0) // Compara la extensión con ".ber"
		return (1); // Devuelve 1 si la extensión es ".ber"
	return (0); // Devuelve 0 si la extensión no es ".ber"
}

char	**read_map(const char *filename)
{
	int		fd; // Descriptor de archivo
	char	*line; // Línea leída del archivo
	char	**map; // Matriz para almacenar el mapa
	int		rows; // Número de filas en el mapa
	int		i; // Índice para recorrer la matriz

	if (!is_ber_file(filename))
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1) // Verifica si hubo un error al abrir el archivo
		return (NULL); // Devuelve NULL si no se pudo abrir el archivo

	rows = 0;
	while (get_next_line(fd)) // Lee cada línea del archivo usando get_next_line
		rows++;
	close(fd); // Cierra el archivo

	// Asigna memoria para la matriz de map
	map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!map) // Verifica si hubo un error al asignar memoria
		return (NULL); // Devuelve NULL si no se pudo asignar memoria

	// Abre nuevamente el archivo para leer el mapa
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(map); // Libera la memoria asignada si hubo un error
		return (NULL);
	}

	i = 0;
	while ((line = get_next_line(fd))) // Lee cada línea del archivo nuevamente
	{
		map[i] = line; // Almacena la línea en la matriz
		i++;
	}
	map[i] = NULL; // Agrega un marcador de final de matriz
	close(fd); // Cierra el archivo

	return (map); // Devuelve la matriz con el mapa cargado desde el archivo
}
