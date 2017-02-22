/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:07:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/21 19:54:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		chk_tetri_nb(char *buf)
{
	int		i;
	int		c;
	int		k;

	i = 0;
	c = 0;
	k = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			c++;
		i++;
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
		{
			if (c != 4)
				return (0);
			c = 0;
			k++;
		}
	}
	return (k);
}

int		chk_struct(char *buf, int c)
{
	int		separate;

	separate = 3;
	while (buf[c + 1] != '\0')
	{
		while (separate > 0)
		{
			if (buf[c] != '\n' && buf[c] != '\0')
				return (0);
			c += 5;
			separate--;
		}
		if (separate == 0 && (buf[c + 1] != '\n' && buf[c + 1] != '\0'))
		{
			return (0);
		}
		separate = 3;
		if (buf[c + 1] != '\0')
			c += 6;
	}
	return (chk_tetri_nb(buf));
}

int		chk_file(char *buf)
{
	int		c;
	int		valid;

	c = 0;
	valid = 0;
	while (buf[c] != '\0')
	{
		if (buf[c] != '#' && buf[c] != '.' && buf[c] != '\n')
		{
			write(1, "error\n", 6);
			return (0);
		}
		c++;
	}
	c = 4;
	valid = chk_struct(buf, c);
	if (valid < 1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (valid);
}
