/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:05:14 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/22 17:54:43 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		cas_particulier(t_tetri *s_tetri)
{
	int	i;
	int	count_n;

	i = 0;
	count_n = 0;
	s_tetri = init_lst(s_tetri);
	while (s_tetri->next)
	{
		if (ft_strlen(s_tetri->content) == 8)
		{
			while (s_tetri->content[i])
			{
				if (s_tetri->content[i] == '\n')
					count_n++;
				i++;
			}
			if (count_n == 4)
				return (1);
		}
		s_tetri = s_tetri->next;
	}
	return (0);
}

int		pos_n(char *buf, size_t nb_tetri)
{
	int		c;
	size_t	t;

	c = 20;
	t = 1;
	if (nb_tetri != 1)
		while (t < nb_tetri)
		{
			if (buf[c] != '\n')
				return (0);
			c += 21;
			t++;
		}
	return (1);
}

char	**div_tetri(char *buf, size_t nb_tetri)
{
	char	**tab_tetri;
	size_t	c;
	char	*tmp;

	c = 0;
	tmp = buf;
	if (pos_n(buf, nb_tetri) != 1)
		return (NULL);
	if (!(tab_tetri = (char **)malloc(sizeof(char *) * nb_tetri + 1)))
		return (NULL);
	while (c < nb_tetri)
	{
		tab_tetri[c] = ft_strsub(tmp, 0, 20);
		c++;
		tmp += 21;
	}
	tab_tetri[c] = "\0";
	return (tab_tetri);
}

int		main(int ac, char **av)
{
	int		fd;
	int		b;
	size_t	nb_tetri;
	char	buf[546];

	if (ac != 2)
		write(1, "usage: fillit target_file_valid\
				\n       fillit ../target_file_valid\n", 72);
	if (!(fd = open(av[1], O_RDONLY)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (((b = read(fd, buf, 546) + 1) % 21) || !b)
	{
		write(1, "error\n", 6);
		return (0);
	}
	nb_tetri = chk_file(buf);
	buf[b - 1] = '\0';
	if (nb_tetri < 1)
		return (0);
	chk_tetri(div_tetri(buf, nb_tetri), nb_tetri);
	close(fd);
	return (0);
}
