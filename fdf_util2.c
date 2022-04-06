/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:57:28 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/05 15:57:30 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_ifwhile(int **ar, t_inc inc, t_x_y put, t_data img)
{
	if (inc.i < inc.k - 1)
		ft_if1(ar, inc, put, img);
	if (inc.j < inc.len - 1)
		ft_if2(ar, inc, put, img);
}

void	ft_while(t_inc inc, t_data img, int **ar)
{
	t_x_y	put;

	initialiser(&put, 0);
	while (inc.i < inc.k)
	{
		inc.j = -1;
		while (++inc.j < inc.len)
		{
			ft_ifwhile(ar, inc, put, img);
			if (inc.j < inc.len - 1
				&& ar[inc.i][inc.j] == 0 && ar[inc.i][inc.j + 1] == 0)
			{
				ddaline(put, put.x + put.px, put.y - put.py, img);
				put.x += put. px;
				put.y -= put.py;
			}
			else
			{
				put.x += put.px;
				put.y -= put.py;
			}
		}
		initialiser(&put, 1);
		inc.i++;
	}
}

int	ft_close(int keycode, t_data *m)
{
	(void)m;
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	ft_close_x(void)
{
	exit(0);
}
