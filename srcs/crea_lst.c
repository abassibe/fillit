/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 23:16:21 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/20 06:12:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*reset_pos(t_tetri *s_tetri)
{
	s_tetri = init_lst(s_tetri);
	while (s_tetri->content != NULL)
		s_tetri = s_tetri->next;
	s_tetri = init_lst(s_tetri);
	return (s_tetri);
}

t_tetri		*crea_lst(t_tetri *s_tetri, char *tab_t, int c, int nb_t)
{
	t_tetri		*new_tetri;

	if (!(new_tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	if (c == nb_t)
	{
		new_tetri->next = NULL;
		new_tetri->content = NULL;
		new_tetri->prev = NULL;
		new_tetri->letter = '\0';
	}
	else
	{
		new_tetri->next = s_tetri;
		new_tetri->content = tab_t;
		new_tetri->prev = NULL;
		new_tetri->next->prev = new_tetri;
		new_tetri->letter = 'A' + c;
	}
	return (new_tetri);
}

t_tetri		*init_lst(t_tetri *s_tetri)
{
	while (s_tetri->prev != NULL)
		s_tetri = s_tetri->prev;
	return (s_tetri);
}

void		algo_dispatch(char **tab_tetri, int nb_tetri)
{
	int			c;
	t_tetri		*s_tetri;

	c = nb_tetri;
	if (!(s_tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return ;
	while (c >= 0)
	{
		s_tetri = crea_lst(s_tetri, tab_tetri[c], c, nb_tetri);
		c--;
	}
	c = 0;
	s_tetri = init_lst(s_tetri);
	cut_tetri(s_tetri, nb_tetri);
}
