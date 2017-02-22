/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:01:55 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/22 17:51:53 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct		s_tetri
{
	char			*content;
	struct s_tetri	*next;
	struct s_tetri	*prev;
	char			letter;
}					t_tetri;

char				**div_tetri(char *buf, size_t nb_tetri);
int					cas_particulier(t_tetri *s_tetri);
int					pos_n(char *buf, size_t nb_tetri);

int					chk_file(char *buf);
int					chk_struct(char *buf, int c);
int					chk_tetri_nb(char *buf);

void				chk_tetri(char **tab_tetri, int nb_tetri);
int					chk_tetri1(char *tetri);
int					verif_htag_fl(char *tetri, size_t c, int count);
int					verif_htag_m(char *tetri, size_t c);

t_tetri				*reset_pos(t_tetri *s_tetri);
void				algo_dispatch(char **tab_tetri, int nb_tetri);
t_tetri				*init_lst(t_tetri *s_tetri);
t_tetri				*crea_lst(t_tetri *s_tetri, char *tab_t, int c, int nb_t);

int					calc_dist_man(t_tetri *s_tetri);
int					calc_y(char *tetri);
int					calc_yb(char *tetri);
int					calc_x(char *tetri);

void				cut_tetri(t_tetri *s_tetri, int nb_tetri);
void				repos_htag_y(char *s);
void				repos_htag_x(char *s);
char				*del_dot(char *s, int x, int y);
void				place_htag(char *s_ori, char *s, int x, int y);

char				*init_board(void);
int					index_n(char *board);
void				grow_tetri_b(char *tmp, char *tetri);
t_tetri				*grow_tetri(t_tetri *s_tetri, char *board);
void				full_dot(char *str);

char				*up_board(char *board);
void				recursive_call(t_tetri *s_tetri, char *board);

char				*pre_up(char *board, int nb_tetri);
int					solve(t_tetri *s_tetri, char *board);
int					try_place(t_tetri *s_tetri, char *board, int pos);
void				place(t_tetri *s_tetri, char *board, int pos, char c);

#endif
