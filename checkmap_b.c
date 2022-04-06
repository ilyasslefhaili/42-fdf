/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:48:52 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/05 21:48:58 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf_bonus.h"

void	clean_memory(int **map_in_arr, char *av, int i, char *str)
{
	free_tab(map_in_arr, av, i);
	free(str);
	perror(NULL);
	exit(1);
}

void	free_s(char **temp, char *str, int i)
{
	clean(temp, i);
	free(str);
}

void	fill_map_in_arr(t_inc *inc, int **map_in_arr, int fd, char *av)
{
	char	**temp;
	char	*str;
	int		i;

	str = NULL;
	while (inc->k == 0 || str)
	{
		if (inc->k != 0)
			free_s(temp, str, i);
		str = get_next_line(fd);
		if (!str)
			break ;
		temp = ft_split(str, ' ');
		i = 0;
		while (temp[i] && ft_strncmp(temp[i], "\n", 1))
			i++;
		if (inc->k && i != inc->len)
		{
			clean_memory(map_in_arr, av, inc->k, str);
			clean(temp, i);
		}
		map_in_arr[inc->k] = malloc(sizeof(int) * i);
		fill_arr(temp, map_in_arr, &inc->k);
		inc->len = i;
	}
}

int	**ft_map(char *av, t_inc *inc)
{
	int	**map_in_arr;
	int	fd;

	fd = open(av, O_RDONLY);
	map_in_arr = malloc(sizeof(int *) * mapelentgh(av));
	inc->k = 0;
	inc->len = 0;
	fill_map_in_arr(inc, map_in_arr, fd, av);
	close(fd);
	return (map_in_arr);
}
