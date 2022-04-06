/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:38:24 by ilefhail          #+#    #+#             */
/*   Updated: 2022/04/04 15:38:31 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	mapelentgh(char *av)
{
	int		fd;
	int		len;
	char	*str;

	len = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error();
	while (!len || str)
	{
		if (len)
			free(str);
		str = get_next_line(fd);
		len++;
	}
	close(fd);
	return (len);
}

void	free_tab(int	**ar, char *av, int len)
{
	int	i;
	int	k;
	int	e;

	i = mapelentgh(av);
	e = 0;
	k = 0;
	while (k < len)
	{
		free(ar[k]);
		k++;
	}
	free(ar);
}

void	clean(char **temp, int c)
{
	while (c >= 0)
	{
		free(temp[c]);
		c--;
	}
	free(temp);
}

void	fill_arr(char **temp, int **map_in_arr, int *k)
{
	int	i;

	i = 0;
	while (temp[i] && ft_strncmp(temp[i], "\n", 1))
	{
		map_in_arr[*k][i] = atoi(temp[i]);
		i++;
	}
	*k = *k + 1;
}
