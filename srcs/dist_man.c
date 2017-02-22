/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:39:04 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/20 06:12:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		calc_yb(char *tetri)
{
	int		c;
	int		k;
	int		count;

	c = 0;
	k = 0;
	count = 10000;
	while (tetri[c] != '\0')
	{
		while (tetri[c] != '\n')
		{
			if (tetri[c] != '.' && tetri[c] != '\n')
				k = 0;
			k++;
			c++;
		}
		if (count > k)
			count = k;
		c++;
	}
	return (count);
}

int		calc_y(char *tetri)
{
	int		y;
	int		c;
	int		count;

	count = 10000;
	y = 0;
	c = 0;
	while (tetri[c] != '\0')
	{
		while (tetri[c] != '\n')
		{
			if (tetri[c] != '.' && tetri[c] != '\n' && count > y)
				count = y;
			c++;
			y++;
		}
		y = 0;
		c++;
	}
	c = 0;
	while (tetri[c] != '\n')
		c++;
	return ((c + 1) - (count + calc_yb(tetri)));
}

int		calc_x(char *tetri)
{
	int		x;
	int		c;
	int		flag;

	x = 0;
	c = 0;
	flag = 0;
	while (tetri[c] != '\0')
	{
		while (tetri[c] != '\n')
		{
			if (tetri[c] != '.' && flag == 0)
			{
				x++;
				flag = 1;
			}
			c++;
		}
		flag = 0;
		c++;
	}
	return (x);
}

int		calc_dist_man(t_tetri *s_tetri)
{
	int		res;
	int		y;
	int		x;

	y = calc_y(s_tetri->content);
	x = calc_x(s_tetri->content);
	res = y * x;
	return (res);
}

void	recursive_call(t_tetri *s_tetri, char *board)
{
	while (!(solve(s_tetri, board)))
	{
		board = up_board(board);
		s_tetri = grow_tetri(s_tetri, board);
	}
	ft_putstr(board);
}
