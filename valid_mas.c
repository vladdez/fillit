/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:50:35 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/10/08 17:53:27 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	swap_y(char **mas)
{
	char	*tmp;
	int		i;
	int		log;

	log = 1;
	i = 0;
	while (i < 4)
	{
		if (mas[0][i] == '#')
			log = 0;
		i++;
	}
	if (log)
	{
		tmp = mas[0];
		mas[0] = mas[1];
		mas[1] = mas[2];
		mas[2] = mas[3];
		mas[3] = tmp;
	}
}

void	swap_x(char **mas)
{
	int		i;
	int		log;

	log = 1;
	i = 0;
	while (i < 4)
	{
		if (mas[i][0] == '#')
			log = 0;
		i++;
	}
	if (log)
	{
		ft_memmove(&mas[0][0], &mas[0][1], 3);
		ft_memmove(&mas[1][0], &mas[1][1], 3);
		ft_memmove(&mas[2][0], &mas[2][1], 3);
		ft_memmove(&mas[3][0], &mas[3][1], 3);
		mas[0][3] = '.';
		mas[1][3] = '.';
		mas[2][3] = '.';
		mas[3][3] = '.';
	}
}

void	valid_mas(char **mas)
{
	swap_y(mas);
	swap_y(mas);
	swap_y(mas);
	swap_x(mas);
	swap_x(mas);
	swap_x(mas);
}
