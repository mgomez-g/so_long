/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelgomezgomez <manuelgomezgomez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:01:27 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/09/19 14:37:40 by manuelgomez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h"
#include "graphic_management.h"
#include "get_next_line.h"
#include "libft/libft.h"

void	find_p(t_game	*a)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (a->map[y])
	{
		x = 0;
		while (a->map[y][x])
		{
			if (a->map[y][x] == 'P')
			{
				printf("\n x : %d | y : %d \n", x, y);
				a->player_x = x;
				a->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	ft_render(t_game *a)
{
	int y;
	int x;

	y = 0;
	while(a->map[y])
	{
		x = 0;
		while(a->map[y][x])
		{
			if (a->map[y][x] == '1')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_wall, x  * 32, y * 32);
			if (a->map[y][x] == '0')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_background, x  * 32, y * 32);
			if (a->map[y][x] == 'C')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_collectible, x  * 32, y * 32);
			if (a->map[y][x] == 'P')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_background, x  * 32, y * 32);
			if (a->map[y][x] == 'E')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_exit, x  * 32, y * 32);
			x++;
		}
		y++;
	}
	//printf("a\n");
	mlx_put_image_to_window(a->mlx, a->windows, a->img_player, a->player_x  * 32, a->player_y * 32);
	
	return (0);
}

int	main(void)
{
	static t_game	a;
	
	a.collected_objects = 0;

	a.map = read_map("maps/map_level_1.ber");

	if (!a.map)
	{
		fprintf(stderr, "Error al cargar el mapa");
		return(1);
	}
	map = duplicate_map(a.map, infos()->height, infos()->width);
	find_p(&a);
	printf("%i %i\n", infos()->height, infos()->width);
	a.valid_path = false;
	flood_fill(&a, a.player_x, a.player_y);
	if (a.valid_path == false)
	{
		fprintf(stderr, "Error: No valid path in the map.\n");
		free_map(map, infos()->height);
		free_map(a.map, infos()->height);
		exit(1);
	}
	a.map = map;
	if (!verify_map_characters(a.map))
	{
		free_map(a.map, infos()->height);
		return (1);
	}	

	a.mlx = mlx_init();
	a.windows = mlx_new_window(a.mlx, infos()->width * 32, infos()->height * 32, "Game");
	a.total_collectibles = calcular_total_collectibles(a.map);
	a.img_wall = mlx_xpm_file_to_image(a.mlx, "images/wall.xpm", &a.width, &a.height);
	a.img_background =  mlx_xpm_file_to_image(a.mlx, "images/background.xpm", &a.width, &a.height);
	a.img_collectible =  mlx_xpm_file_to_image(a.mlx, "images/collectible.xpm", &a.width, &a.height);
	a.img_player =  mlx_xpm_file_to_image(a.mlx, "images/player.xpm", &a.width, &a.height);
	a.img_exit =  mlx_xpm_file_to_image(a.mlx, "images/exit.xpm", &a.width, &a.height);

	mlx_hook(a.windows, 17, 0, (void *) handle_x, &a);
	mlx_key_hook(a.windows, handle_key, &a);
	mlx_loop_hook(a.mlx, ft_render, &a);
	mlx_loop(a.mlx);
}
