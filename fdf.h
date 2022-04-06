/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:37:22 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/05 21:58:19 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./libft_fdf/libft.h"
# define ESC 53

typedef struct t_verti_x_y{
	int	x;
	int	y;
	int	sx;
	int	sy;
	int	px;
	int	py;
	int	h;
}t_x_y;

typedef struct t_inc{
	int	i;
	int	j;
	int	len;
	int	k;
}t_inc;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct t_void{
	void	*mlx;
	void	*mlx_win;
	int		**ar;
	t_inc	inc;
}t_void;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_with_color(t_x_y d, t_data img);
void	ddaline(t_x_y put, int x1, int y1, t_data img);
void	ft_if1(int **ar, t_inc inc, t_x_y put, t_data img);
void	ft_if2(int **ar, t_inc inc, t_x_y put, t_data img);
void	ft_while(t_inc inc, t_data img, int **ar);
void	ft_ifwhile(int **ar, t_inc inc, t_x_y put, t_data img);
void	initialiser(t_x_y *put, int i);
char	*get_next_line(int fd);
int		**ft_map(char *av, t_inc *inc);
int		mapelentgh(char *av);
void	free_tab(int	**ar, char *av, int len);
void	clean(char **temp, int c);
void	fill_arr(char **temp, int **map_in_arr, int *k);
void	clean_memory(int **map_in_arr, char *av, int i, char *str);
void	free_s(char **temp, char *str, int i);
void	fill_map_in_arr(t_inc *inc, int **map_in_arr, int fd, char *av);
void	error(void);
int		ft_close_x(void);
int		ft_close(int keycode, t_data *m);

#endif
