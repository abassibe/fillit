/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:16:35 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/21 16:40:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*up_board(char *board)
{
	int		y;
	int		x;
	int		i;
	int		j;

	y = index_n(board);
	x = y;
	i = 0;
	j = 0;
	while (x >= 0)
	{
		while (i <= y)
		{
			board[j] = '.';
			i++;
			j++;
		}
		board[j] = '\n';
		j++;
		i = 0;
		x--;
	}
	board[(y + 1) * (y + 2)] = '\0';
	return (board);
}

char	*pre_up(char *board, int nb_tetri)
{
	if (nb_tetri > 1)
		board = up_board(board);
	if (nb_tetri > 2)
		board = up_board(board);
	if (nb_tetri > 4)
		board = up_board(board);
	if (nb_tetri > 6)
		board = up_board(board);
	if (nb_tetri > 9)
		board = up_board(board);
	if (nb_tetri > 12)
		board = up_board(board);
	if (nb_tetri > 16)
		board = up_board(board);
	if (nb_tetri > 20)
		board = up_board(board);
	if (nb_tetri > 25)
		board = up_board(board);
	return (board);
}

int		solve(t_tetri *s_tetri, char *board)
{
	int		pos;

	pos = 0;
	while (board[pos])
	{
		if (try_place(s_tetri, board, pos))
		{
			if (s_tetri->next->content)
			{
				if (solve(s_tetri->next, board))
					return (1);
				else
					place(s_tetri, board, pos, '.');
			}
			else
				return (1);
		}
		pos++;
		if (board[pos] == '\n')
			pos++;
	}
	return (0);
}

int		try_place(t_tetri *s_tetri, char *board, int pos)
{
	int		i;

	i = 0;
	while (s_tetri->content[i])
	{
		if (s_tetri->content[i] == '#')
			if (board[i + pos] != '.')
				return (0);
		i++;
	}
	place(s_tetri, board, pos, s_tetri->letter);
	return (1);
}

void	place(t_tetri *s_tetri, char *board, int pos, char c)
{
	int		i;

	i = 0;
	while (s_tetri->content[i])
	{
		if (s_tetri->content[i] == '#')
			board[i + pos] = c;
		i++;
	}
}
