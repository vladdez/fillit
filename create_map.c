/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:49 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/10/11 15:49:52 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrtm(int n)
{
	int		i;

	i = 1;
	while (i * i < n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (i);
}

char	**cr_map(int l, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (l + 1))))
		return (NULL);
	while (i < l)
	{
		map[i] = ft_strnew(l);
		while (j < l)
		{
			map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**create_map(char **old_map, t_list *trmo)
{
	char		**map;
	static int	l = 0;
	int			i;

	i = 0;
	map = NULL;
	if (l == 0)
	{
		while (trmo && ++i)
			trmo = trmo->next;
		l = ft_sqrtm(i * 4);
	}
	else if (l++)
	{
		while (old_map[i])
		{
			ft_strdel(old_map + i);
			i++;
		}
		free(old_map);
	}
	return (cr_map(l, map));
}
