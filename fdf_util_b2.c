/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util_b2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:51:10 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/05 21:57:48 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf_bonus.h"

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
