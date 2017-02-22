/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:27:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/21 17:36:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verif_htag_m(char *tetri, size_t c)
{
	int		connect;

	connect = 0;
	if (tetri[c + 1] == '#')
		connect++;
	if (tetri[c - 1] == '#')
		connect++;
	if (c > 4 && tetri[c - 5] == '#')
		connect++;
	if (c < 16 && tetri[c + 5] == '#')
		connect++;
	return (connect);
}

int		verif_htag_fl(char *tetri, size_t c, int count)
{
	int		connect;

	connect = 0;
	if (count == 1)
	{
		if (tetri[c + 1] == '#')
			connect++;
		if (tetri[c + 5] == '#')
			connect++;
	}
	if (count == 4)
	{
		if (tetri[c - 1] == '#')
			connect++;
		if (tetri[c - 5] == '#')
			connect++;
	}
	return (connect);
}

int		chk_tetri1(char *tetri)
{
	size_t	c;
	int		count;
	int		connect;

	c = 0;
	count = 0;
	connect = 0;
	while (tetri[c] != '\0')
	{
		if (tetri[c] == '#')
		{
			count++;
			if (count == 1 || count == 4)
				connect += verif_htag_fl(tetri, c, count);
			if (count == 2 || count == 3)
				connect += verif_htag_m(tetri, c);
		}
		c++;
	}
	if (connect == 6 || connect == 8)
		return (1);
	return (0);
}

void	chk_tetri(char **tab_tetri, int nb_tetri)
{
	int		c;
	int		valid;

	c = 0;
	valid = 0;
	while (c != nb_tetri)
	{
		valid = chk_tetri1(tab_tetri[c]);
		if (valid != 1)
		{
			write(1, "error\n", 6);
			return ;
			c = nb_tetri;
		}
		c++;
	}
	if (valid == 1)
		algo_dispatch(tab_tetri, nb_tetri);
}
