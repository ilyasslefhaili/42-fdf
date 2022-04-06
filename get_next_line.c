/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:37:49 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/05 22:01:26 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

char	*get_next_line(int fd)
{
	char	buff;
	char	r[700000];
	int		i;
	int		n;

	if (fd < 0)
		return (0);
	i = 0;
	n = read(fd, &buff, 1);
	while (n > 0)
	{
		r[i++] = buff;
		if (buff == '\n')
			break ;
		n = read(fd, &buff, 1);
	}
	r[i] = 0;
	if (n <= 0 && i == 0)
		return (0);
	return (ft_strdup(r));
}
