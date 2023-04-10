/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:39:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/10 04:28:43 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error(t_savage *criminal, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map[i][j] != '1' && criminal->map[i][j] != '0' \
			&& criminal->map[i][j] != 'P' && criminal->map[i][j] != 'E' \
			&& criminal->map[i][j] != 'C')
			{
				ft_printf("ERROR : makaynche 1 || 0 || P || E || C");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_map(char *len)
{
	int	i;

	i = ft_strlen(len) - 1;
	if (len[i] != 'r')
		exit (1);
	if (len[i - 1] != 'e')
		exit (1);
	if (len[i - 2] != 'b')
		exit (1);
}

void	calyx(int *y, int *x, int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (str != NULL)
			(*x) = ft_strlen(str);
			(*y)++;
	}
	close (fd);
}

void	reader(t_savage *criminal, int fd)
{
	char	*str = get_next_line(fd);
	criminal->tol = ft_strlen(str)-1;
	char	*twile = malloc(1);
	while (str)
	{
		twile = ft_strjoin_get(twile, str);
		criminal->lines++;
		str = get_next_line(fd);
	}
	criminal->map = ft_split(twile, '\n');
	criminal->map1 = ft_split(twile, '\n');
	close (fd);
}

int	main(int ac, char **av)
{
	t_savage	criminal;
	int			x;
	int			y;
	int			fd;
	int			fd2;
	int			fd3;

	x = 0;
	y = 0;
	check_map(av[1]);
	fd = open(av[1], O_RDONLY);
	calyx(&criminal.y, &criminal.x, fd);
	fd2 = open(av[1], O_RDONLY);
	reader(&criminal, fd2);
	fd3 = open(av[1], O_RDONLY);
	reader(&criminal, fd3);
	valid_path(&criminal, criminal.y, criminal.x);
	check_len(&criminal, criminal.y, criminal.x);
	check_num(&criminal, criminal.y, criminal.x);
	check_items(&criminal, criminal.y, criminal.x);
	check_error(&criminal, criminal.y, criminal.x);
	initialisation(&criminal);
}

