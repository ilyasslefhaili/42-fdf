/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_b_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:37:30 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/05 20:37:32 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf_bonus.h"

void	ft_mouse(int *mouse, double *mousey, int c)
{
	if (c == 0)
	{
		*mouse += 2;
		*mousey += 1;
	}
	else if (c == 2)
	{
		*mouse -= 2;
		*mousey -= 1;
	}
}

void	ft_move(int *moveh, int *mover, int c)
{
	if (c == 4)
		*moveh -= 10;
	else if (c == 5)
		*moveh += 10;
	else if (c == 6)
		*mover -= 10;
	else if (c == 7)
		*mover += 10;
}

void	ft_zoom(int c, int h, t_x_y *put)
{
	static int		mouse;
	static double	mousey;
	static int		moveh;
	static int		mover;

	ft_mouse(&mouse, &mousey, c);
	ft_move(&moveh, &mover, c);
	put->y = 700 + moveh;
	put->sy = 700 + moveh;
	put->x = 50 + mover;
	put->sx = 50 + mover;
	put->px = 15 + mouse;
	put->py = 10 + mousey;
	if (put->px < 2)
	{
		put->px = 2;
		put->py = 1;
	}
	put->h = h;
}

void	initialiser_bonus(t_x_y *put, int i, int c)
{
	static int	e;
	int			h;

	if (i == 0)
	{	
		h = 15;
		if (c == -1)
			e--;
		if (c == 1)
			e++;
		h += e;
		ft_zoom(c, h, put);
	}
	else
	{
		put->sy += put->py;
		put->sx += put->px;
		put->x = put->sx;
		put->y = put->sy;
	}
}
