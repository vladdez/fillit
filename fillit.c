/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:30:09 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/10/11 12:32:43 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_check(int ac, char *av)
{
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		exit(1);
	}
	if (f_check28(av) == -1)
	{
		ft_putendl("error");
		exit(1);
	}
}

void	put_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		ft_strdel(map + i);
		i++;
	}
	free(map);
}

int		main(int ac, char **av)
{
	t_list	*trmo;
	char	**map;

	map = NULL;
	error_check(ac, av[1]);
	trmo = get_tetriminos(av[1]);
	while (1)
	{
		map = create_map(map, trmo);
		if (fill_map(map, trmo))
			break ;
	}
	put_map(map);
	return (0);
}
