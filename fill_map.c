/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:31:36 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/10/11 12:31:59 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_this_cage(t_list *trmo, int x, int y, char **map)
{
	int		log;
	int		*coor;
	int		i;

	i = 0;
	log = 1;
	coor = trmo->content;
	while (map[i])
		i++;
	if ((x + coor[0] >= i) || (y + coor[1] >= i) ||
			map[y + coor[1]][x + coor[0]] != '.')
		log = 0;
	if ((x + coor[2] >= i) || (y + coor[3] >= i) ||
			map[y + coor[3]][x + coor[2]] != '.')
		log = 0;
	if ((x + coor[4] >= i) || (y + coor[5] >= i) ||
			map[y + coor[5]][x + coor[4]] != '.')
		log = 0;
	if ((x + coor[6] >= i) || (y + coor[7] >= i) ||
			map[y + coor[7]][x + coor[6]] != '.')
		log = 0;
	if (log)
		return (1);
	else
		return (0);
}

void	paste_trmo(t_list *trmo, int x, int y, char **map)
{
	int		*coor;
	char	c;

	c = trmo->content_size;
	coor = trmo->content;
	map[y + coor[1]][x + coor[0]] = c;
	map[y + coor[3]][x + coor[2]] = c;
	map[y + coor[5]][x + coor[4]] = c;
	map[y + coor[7]][x + coor[6]] = c;
}

int		is_there_place(t_list *trmo, char **map, int *k)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (map[0][i])
		i++;
	x = *k % i;
	y = *k / i;
	while (y < i)
	{
		while (x < i)
		{
			if (is_this_cage(trmo, x, y, map))
			{
				paste_trmo(trmo, x, y, map);
				return (1);
			}
			x++;
			*k += 1;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	delete_trmo(char c, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

int		fill_map(char **map, t_list *trmo)
{
	int		k;

	k = 0;
	while (1)
	{
		if (!is_there_place(trmo, map, &k))
			return (0);
		if (trmo->next == NULL)
			return (1);
		if (fill_map(map, trmo->next))
			return (1);
		delete_trmo(trmo->content_size, map);
		k++;
	}
}
