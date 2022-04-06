/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:22:19 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/02 10:22:24 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_inc	inc;
	t_void	m;
	t_data	img;
	int		**ar;

	if (ac < 2 || ac > 2)
		error();
	ar = ft_map(av[1], &inc);
	m.mlx = mlx_init();
	if (m.mlx == NULL)
		error();
	m.mlx_win = mlx_new_window(m.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(m.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	inc.i = 0;
	ft_while(inc, img, ar);
	mlx_put_image_to_window(m.mlx, m.mlx_win, img.img, 0, 0);
	mlx_hook(m.mlx_win, 17, 0, ft_close_x, &m);
	mlx_key_hook(m.mlx_win, ft_close, &m);
	mlx_loop(m.mlx);
}
