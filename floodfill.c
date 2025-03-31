/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:57:44 by npederen          #+#    #+#             */
/*   Updated: 2025/03/31 17:57:44 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_tiles_e(t_map *map, int y, int x, int elem)
{
	map->map[y][x] = '1';
	return (elem + 1);
}

int	flood_fill(t_map *map, t_game *game, int y, int x)
{
	static int	elem = 0;
	static int	i = 0;

	if (y < 0 || y >= map->longeur || x < 0 || x >= map->largeur || \
		map->map[y][x] == '1' || map->map[y][x] == 'E' || map->map[y][x] == 'M')
	{
		if (map->map[y][x] == 'E')
			elem = is_tiles_e(map, y, x, elem);
		return (0);
	}
	if (map->map[y][x] == 'C')
	{
		elem++;
		map->map[y][x] = '1';
		if (game->collectibles[i].x == x && game->collectibles[i].y == y)
			i++;
		else
			return (0);
	}
	map->map[y][x] = '1';
	flood_fill(map, game, y, x - 1);
	flood_fill(map, game, y, x + 1);
	flood_fill(map, game, y - 1, x);
	flood_fill(map, game, y + 1, x);
	return (elem);
}
