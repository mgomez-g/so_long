/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomez-g <mgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:01:27 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/09/13 13:55:16 by mgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h"
#include "graphic_management.h"
#include "get_next_line.h"
#include "libft/libft.h"

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
	
	//Posicion Inicial
	a.player_x = 2; // Coordenada X
    a.player_y = 2; // Coordenada Y
	
	a.collected_objects = 0;

	a.map = read_map("maps/map_level_1.ber");
	if (!a.map)
	{
		fprintf(stderr, "Error To Load Map");
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
	
	//Loops
	mlx_hook(a.windows, 17, 0, (void *) handle_x, &a); // Window Closing
	mlx_key_hook(a.windows, handle_key, &a);// Key handling
	mlx_loop_hook(a.mlx, ft_render, &a); // Render game images
	mlx_loop(a.mlx);
}
