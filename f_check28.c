/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:26:42 by kysgramo          #+#    #+#             */
/*   Updated: 2019/10/11 19:41:30 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		f_side(int i, char *tet)
{
	int		side;

	side = 0;
	if (tet[i - 1])
	{
		if (tet[i - 1] == '#')
			side++;
	}
	if (tet[i + 1])
	{
		if (tet[i + 1] == '#')
			side++;
	}
	if (tet[i - 5])
	{
		if (tet[i - 5] == '#')
			side++;
	}
	if (tet[i + 5])
	{
		if (tet[i + 5] == '#')
			side++;
	}
	return (side);
}

int		f_hash(char *tet)
{
	int		i;
	int		hash;
	int		side;

	i = 0;
	hash = 0;
	side = 0;
	while (tet[i])
	{
		if (tet[i] != '.' && tet[i] != '#' && tet[i] != '\n')
			return (-1);
		if (tet[i] == '#')
		{
			hash++;
			side += f_side(i, tet);
		}
		i++;
	}
	if (hash != 4 || side < 6)
		return (-1);
	return (1);
}

int		f_check4(int fd)
{
	int		res;
	char	tet[21];

	res = read(fd, tet, 21);
	tet[res] = '\0';
	if (tet[4] != '\n' || tet[9] != '\n' || tet[14] != '\n')
		return (-1);
	else if (f_hash(tet) == -1)
		return (-1);
	else if (res == 20 && tet[20] == '\0')
		return (0);
	else if (tet[19] != '\n' || tet[20] != '\n')
		return (-1);
	return (1);
}

int		f_check28(char *argv)
{
	int		res;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < 26)
	{
		res = f_check4(fd);
		if (res == 0)
			return (1);
		if (res == -1)
			return (-1);
		i++;
	}
	return (-1);
}
