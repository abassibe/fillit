/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:35:36 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/22 17:55:11 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_htag(char *s_ori, char *s, int x, int y)
{
	int		c;
	int		i;
	int		n;

	c = 0;
	i = 0;
	n = 0;
	while (c != x * (y + 1))
	{
		if (i < (y + (5 * n)))
		{
			s[c] = s_ori[i];
			c++;
			if (s[c] == '\n')
				c++;
		}
		if (s_ori[i] == '\n')
			n++;
		i++;
	}
}

char	*del_dot(char *s, int x, int y)
{
	int		c;
	int		n;
	char	*ret;

	if (!(ret = (char *)malloc(sizeof((x * (y + 1)) + 1))))
		return (NULL);
	c = x * (y + 1);
	ret[c] = '\0';
	while (--c >= 0)
		ret[c] = '.';
	c = 5;
	n = y;
	while (--c)
	{
		ret[n] = '\n';
		n += y + 1;
	}
	ret[x * (y + 1)] = '\0';
	place_htag(s, ret, x, y);
	return (ret);
}

void	repos_htag_x(char *s)
{
	int		c;
	int		p;

	c = 0;
	p = 0;
	while (s[p] != '#' && s[p + 1] != '#' && s[p + 2] != '#' && \
			s[p + 3] != '#')
		p += 5;
	while (s[c] != '\0')
	{
		if (s[c] == '#')
		{
			s[c] = '.';
			s[c - p] = '#';
		}
		c++;
	}
}

void	repos_htag_y(char *s)
{
	int		c;
	int		p;

	c = 0;
	p = 0;
	while (s[p] != '#' && s[p + 5] != '#' && s[p + 10] != '#' && \
			s[p + 15] != '#')
		p++;
	while (s[c] != '\0')
	{
		if (s[c] == '#')
		{
			s[c] = '.';
			s[c - p] = '#';
		}
		c++;
	}
}

void	cut_tetri(t_tetri *s_tetri, int nb_tetri)
{
	int		y;
	int		x;
	char	*board;

	y = 0;
	x = 0;
	while (s_tetri->content != NULL)
	{
		y = calc_y(s_tetri->content);
		x = calc_x(s_tetri->content);
		repos_htag_y(s_tetri->content);
		repos_htag_x(s_tetri->content);
		s_tetri->content = del_dot(s_tetri->content, x, y);
		s_tetri = s_tetri->next;
	}
	board = init_board();
	board = pre_up(board, nb_tetri);
	if (nb_tetri == 2)
		if (cas_particulier(s_tetri))
			board = up_board(board);
	s_tetri = grow_tetri(s_tetri, board);
	recursive_call(s_tetri, board);
}
