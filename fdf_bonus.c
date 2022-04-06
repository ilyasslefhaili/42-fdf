/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:55:10 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/04 20:55:28 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf_bonus.h"

void	ft_while_bonus(t_data img, int k, int **ar, t_inc inc)
{
	t_x_y	put;

	inc.i = -1;
	initialiser_bonus(&put, 0, k);
	while (++inc.i < inc.k)
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
	}
}

void	ft_new_image(int a, t_void *m)
{
	t_data	img;

	mlx_clear_window(m->mlx, m->mlx_win);
	img.img = mlx_new_image(m->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_while_bonus(img, a, m->ar, m->inc);
	mlx_put_image_to_window(m->mlx, m->mlx_win, img.img, 0, 0);
}

int	ft_hook(int keyhook, t_void *m)
{
	if (keyhook == 126)
		ft_new_image(1, m);
	else if (keyhook == 125)
		ft_new_image(-1, m);
	else if (keyhook == 69)
		ft_new_image(0, m);
	else if (keyhook == 78)
		ft_new_image(2, m);
	else if (keyhook == 13)
		ft_new_image(4, m);
	else if (keyhook == 1)
		ft_new_image(5, m);
	else if (keyhook == 0)
		ft_new_image(6, m);
	else if (keyhook == 2)
		ft_new_image(7, m);
	else if (keyhook == ESC)
		exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_void	m;
	t_data	img;

	if (ac < 2 || ac > 2)
		error();
	m.ar = ft_map(av[1], &m.inc);
	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(m.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	m.inc.i = 0;
	ft_while(m.inc, img, m.ar);
	mlx_put_image_to_window(m.mlx, m.mlx_win, img.img, 0, 0);
	mlx_hook(m.mlx_win, 17, 0, ft_close_x, &m);
	mlx_mouse_hook(m.mlx_win, ft_hook, &m);
	mlx_key_hook(m.mlx_win, ft_hook, &m);
	mlx_loop(m.mlx);
}
