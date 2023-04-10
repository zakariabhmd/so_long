/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:37:30 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/10 02:40:29 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_items_help(t_savage *criminal)
{
	if (criminal->p == 0)
	{
		ft_printf("ERROR : makaynche player\n");
		exit (1);
	}
	if (criminal->p > 1)
	{
		ft_printf("ERROR : bzaf dyal player\n");
		exit (1);
	}
	if (criminal->c == 0)
	{
		ft_printf("ERROR : makaynche coins\n");
		exit (1);
	}
	check_items_help2(criminal);
}

void	check_items_help2(t_savage *criminal)
{
	if (criminal->e == 0)
	{
		ft_printf("ERROR : makaynche exit\n");
		exit (1);
	}
	if (criminal->e > 1)
	{
		ft_printf("ERROR : bzaf dyal exit\n");
		exit (1);
	}
}

void	check_items(t_savage *criminal, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	criminal->p = 0;
	criminal->c = 0;
	criminal->e = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map[i][j] == 'P')
				criminal->p++;
			if (criminal->map[i][j] == 'C')
				criminal->c++;
			if (criminal->map[i][j] == 'E')
				criminal->e++;
			j++;
		}
		i++;
		j = 0;
	}
	check_items_help(criminal);
}

void	check_len(t_savage *criminal, int y, int x)
{
	int	i;

	i = 0;
	while (i != y)
	{
		if (x != ft_strlen(criminal->map[i]))
		{
			ft_printf("ERROR : tol maci hwa hadak\n");
			exit (1);
		}
		i++;
	}
}

void	check_num(t_savage *criminal, int y, int x)
{
	int	i;

	i = 0;
	while (i != x)
	{
		if (criminal->map[0][i] != '1')
		{
			ft_printf("ERROR : maxi 1\n");
			exit (1);
		}
		if (criminal->map[y - 1][i] != '1')
		{
			ft_printf("ERROR : maxi 1\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i != y)
	{
		if (criminal->map[i][0] != '1' || criminal->map[i][x - 1] != '1')
		{
			ft_printf("ERROR : machi 1\n");
			exit (1);
		}
		i++;
	}
}