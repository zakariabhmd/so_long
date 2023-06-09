/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:40:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/14 00:57:01 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_path(t_savage *criminal, int y, int x)
{
	int	i;
	int	j;
	int	sum;

	sum = x * y;
	while (sum > 0)
	{
		i = 0;
		while (i < y)
		{
			while (j < x)
			{
				if (criminal->map1[i][j] == 'P')
				{
					valid_path1(criminal, i, j);
				}
				j++;
			}
			j = 0;
			i++;
		}
		sum--;
	}
	check_valid_path(criminal);
	exit_valid_path(criminal);
}

void	valid_path1(t_savage *criminal, int i, int j)
{
	if (criminal->map1[i][j - 1] != 'E' && criminal->map1[i][j - 1] != '1')
		criminal->map1[i][j - 1] = 'P';
	if (criminal->map1[i][j + 1] != 'E' && criminal->map1[i][j + 1] != '1')
		criminal->map1[i][j + 1] = 'P';
	if (criminal->map1[i + 1][j] != 'E' && criminal->map1[i + 1][j] != '1')
		criminal->map1[i + 1][j] = 'P';
	if (criminal->map1[i - 1][j] != 'E' && criminal->map1[i - 1][j] != '1')
		criminal->map1[i - 1][j] = 'P';
}

void	check_valid_path(t_savage *criminal)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < criminal->y)
	{
		while (j < criminal->x)
		{
			if (criminal->map1[i][j] == 'C')
			{
				ft_printf("invalid path\n");
				exit (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int	ft_help(t_savage *criminal, int i, int j, int e)
{
	if (criminal->map1[i][j] == 'E')
	{
		if (criminal->map1[i - 1][j] == 'P')
			e++;
		if (criminal->map1[i + 1][j] == 'P')
			e++;
		if (criminal->map1[i][j + 1] == 'P')
			e++;
		if (criminal->map1[i][j - 1] == 'P')
			e++;
	}
	return (e);
}

void	exit_valid_path(t_savage *criminal)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (i != criminal->y)
	{
		while (j != criminal->x)
		{
			e = ft_help(criminal, i, j, e);
			j++;
		}
		j = 0;
		i++;
	}
	if (e == 0)
	{
		ft_printf("invalid path\n");
		exit(1);
	}
}
