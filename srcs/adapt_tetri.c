/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 07:54:35 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/22 17:56:40 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*init_board(void)
{
	char	*board;

	board = (char *)malloc(150);
	ft_strcpy(board, "..\n..\n");
	return (board);
}

int			index_n(char *board)
{
	int		i;

	i = 0;
	while (board[i] != '\n')
		i++;
	return (i);
}

void		full_dot(char *str)
{
	int		c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] != '\0' && str[c] != '\n')
			str[c] = '.';
		c++;
	}
}

void		grow_tetri_b(char *tmp, char *tetri)
{
	int		c;
	int		d;

	c = 0;
	d = 0;
	while (tetri[c] != '\n')
	{
		if (tetri[c] == '#')
			tmp[c] = '#';
		c++;
	}
	while (tetri[c] != '\0')
	{
		if (tetri[c] == '\n')
			while (tmp[d] != '\n')
				d++;
		if (tetri[c] == '#')
			tmp[d] = '#';
		c++;
		d++;
	}
}

t_tetri		*grow_tetri(t_tetri *s_tetri, char *board)
{
	char	*tmp;
	char	*tetri;
	int		l_tetri;
	int		l_board;

	s_tetri = init_lst(s_tetri);
	tetri = s_tetri->content;
	while (s_tetri->content != NULL)
	{
		l_tetri = ft_strlen(tetri);
		l_board = ft_strlen(board);
		if (l_tetri < l_board)
		{
			tetri = s_tetri->content;
			tmp = ft_strdup(board);
			full_dot(tmp);
			grow_tetri_b(tmp, tetri);
			s_tetri->content = tmp;
		}
		s_tetri = s_tetri->next;
	}
	s_tetri = init_lst(s_tetri);
	return (s_tetri);
}
