/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:58:42 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/10/08 17:59:02 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 32

int		f_check28(char *argv);
char	**create_map(char **old_map, t_list *trmo);
int		fill_map(char **map, t_list *trmo);
void	valid_mas(char **mas);
t_list	*get_tetriminos(char *name);
int		get_next_line(const int fd, char **line);

#endif
