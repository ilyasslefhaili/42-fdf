/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:45:53 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/04 13:45:54 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ddaline(t_x_y put, int x1, int y1, t_data img)
{
	float	len;
	t_x_y	d;
	float	xinc;
	float	yinc;

	d.sx = x1 - put.x;
	d.sy = y1 - put.y;
	d.h = 0;
	if (abs(d.sx) > abs(d.sy))
		len = abs(d.sx);
	else
		len = abs(d.sy);
	xinc = d.sx / len;
	yinc = d.sy / len;
	while (d.h <= len)
	{
		d.x = put.x + xinc * d.h;
		d.y = put.y + yinc * d.h;
		d.h++;
		if (d.x > 0 && d.x < 1920 && d.y > 0 && d.y < 1080)
			my_mlx_pixel_put(&img, d.x, d.y, 0x008000);
	}
}

void	ft_if1(int **ar, t_inc inc, t_x_y put, t_data img)
{
	int	temp;

	temp = 0;
	(void)img;
	if (ar[inc.i][inc.j] == 0 && ar[inc.i + 1][inc.j] == 0)
		ddaline(put, put.x + put.px, put.y + put.py, img);
	if (ar[inc.i][inc.j] == 0 && ar[inc.i + 1][inc.j] != 0)
		ddaline(put, put.x + put.px,
			put.y - ar[inc.i + 1][inc.j] * put.h + put.py, img);
	if (ar[inc.i][inc.j] != 0 && ar[inc.i + 1][inc.j] == 0)
	{
		temp = put.y;
		put.y -= ar[inc.i][inc.j] * put.h;
		ddaline(put, put.x + put.px, temp + put.py, img);
		put.y = temp;
	}
	if (ar[inc.i][inc.j] != 0 && ar[inc.i + 1][inc.j] != 0)
	{
		temp = put.y;
		put.y -= ar[inc.i][inc.j] * put.h;
		ddaline(put, put.x + put.px,
			temp - ar[inc.i + 1][inc.j] * put.h + put.py, img);
	}
}

void	ft_if2(int **ar, t_inc inc, t_x_y put, t_data img)
{
	int		temp;

	temp = 0;
	(void)img;
	if (ar[inc.i][inc.j] == 0 && ar[inc.i][inc.j + 1] != 0)
		ddaline(put, put.x + put.px,
			put.y - put.py - ar[inc.i][inc.j + 1] * put.h, img);
	if (ar[inc.i][inc.j] != 0 && ar[inc.i][inc.j + 1] == 0)
	{
		temp = put.y;
		put.y -= ar[inc.i][inc.j] * put.h;
		ddaline(put, put.x + put.px, temp - put.py, img);
		put.y = temp;
	}
	if (ar[inc.i][inc.j] != 0 && ar[inc.i][inc.j + 1] != 0)
	{
		temp = put.y;
		put.y -= ar[inc.i][inc.j] * put.h;
		ddaline(put, put.x + put.px,
			temp - ar[inc.i][inc.j + 1] * put.h - put.py, img);
	}
}
