/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomez-g <mgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:00:30 by mgomez-g          #+#    #+#             */
/*   Updated: 2023/09/13 14:38:36 by mgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_management.h"
#include "get_next_line.h"

// Declaración de la función ft_render
int ft_render(t_game *a);

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
		{
			game->map[new_y][new_x] = '0';
			game->collected_objects++;
		}
		game->player_x = new_x;
		game->player_y = new_y;
		game->movements++;
		if (game->collected_objects == game->total_collectibles && game->map[game->player_y][game->player_x] == 'E')
		{
            printf("¡You Win!\n");
            mlx_destroy_window(game->mlx, game->windows);
            exit(0);
        }
	}
}

void	handle_x(t_game *game)
{
	(void) game;
//	printf("handle_x\n");
	exit(0);
}

int handle_key(int keycode, t_game *game)
{
	if (keycode == 65307) // Código de la tecla Esc
	{
		mlx_destroy_window(game->mlx, game->windows);
		exit(0);
	}
	else if (keycode == 119) // Tecla W (arriba)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 115) // Tecla S (abajo)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 97) // Tecla A (izquierda)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 100) // Tecla D (derecha)
		move_player(game, game->player_x + 1, game->player_y);
	
	mlx_clear_window(game->mlx, game->windows);
	ft_render(game);
	return (0);
}

int calcular_total_collectibles(char **map)
{
	int total_collectibles = 0; 

	int y = 0;
	while(map[y]) // Cambia "a->map[y]" a "map[y]"
	{
		int x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'C')
				total_collectibles++;
			x++; 
		}
		y++;
	}

	return total_collectibles; 
}