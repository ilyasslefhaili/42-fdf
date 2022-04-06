/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:33:58 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/04 20:34:00 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	initialiser(t_x_y *put, int i)
{
	if (i == 0)
	{
		put->y = 700;
		put->sy = 700;
		put->x = 50;
		put->sx = 50;
		put->px = 15;
		put->py = 10;
		put->h = 15;
	}
	else
	{
		put->sy += put->py;
		put->sx += put->px;
		put->x = put->sx;
		put->y = put->sy;
	}
}

void	error(void)
{
	perror(NULL);
	exit(1);
}
