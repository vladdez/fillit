/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:53:50 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/10/08 18:27:34 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_mas(char **mas)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_strdel(mas + i);
		i++;
	}
}

int		*fill_coor(char **mas)
{
	int		*coor;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	coor = ft_memalloc(sizeof(int) * 8);
	while (y < 4)
	{
		while (x < 4)
		{
			if (mas[y][x] == '#')
			{
				coor[i] = x;
				coor[i + 1] = y;
				i += 2;
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (coor);
}

t_list	*get_list(char **mas)
{
	static int	c = 65;
	t_list		*list;
	int			*coor;

	valid_mas(mas);
	coor = fill_coor(mas);
	list = (t_list*)malloc(sizeof(t_list));
	list->content_size = c;
	list->content = ft_memalloc(sizeof(int) * 8);
	ft_memcpy(list->content, coor, sizeof(int) * 8);
	free(coor);
	list->next = NULL;
	c++;
	return (list);
}

t_list	*fill_list(char **mas, int log)
{
	static t_list	*first = NULL;
	static t_list	*tmp = NULL;

	if (!first && log)
	{
		first = get_list(mas);
		tmp = first;
	}
	else if (log)
	{
		tmp->next = get_list(mas);
		tmp = tmp->next;
	}
	return (first);
}

t_list	*get_tetriminos(char *name)
{
	char	*line;
	char	**mas;
	size_t	fd;
	int		log;
	int		i;

	i = 0;
	log = 1;
	mas = (char**)malloc(sizeof(char*) * 4);
	fd = open(name, O_RDONLY);
	while (log)
	{
		log = get_next_line(fd, &line);
		mas[i++] = line;
		if (i == 4)
		{
			i = 0;
			get_next_line(fd, &line);
			fill_list(mas, 1);
			free_mas(mas);
		}
	}
	free(mas);
	close(fd);
	return (fill_list(mas, 0));
}
