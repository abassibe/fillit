/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:11:09 by abassibe          #+#    #+#             */
/*   Updated: 2017/01/26 18:40:46 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_word(char const *s, char c)
{
	int		p;
	int		k;

	p = 0;
	k = 0;
	while (s[p] != '\0')
	{
		while (s[p] == c)
			p++;
		while (s[p] != c && s[p])
		{
			p++;
			if (s[p] == c || s[p] == '\0')
				k++;
		}
	}
	return (k);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tb;
	int		k;
	int		p;
	int		f;

	tb = NULL;
	k = 0;
	p = 0;
	f = 0;
	if (s == NULL || !(tb = (char **)malloc(sizeof(char *) * c_word(s, c) + 1)))
		return (NULL);
	while (p < c_word(s, c) && s[k])
	{
		while (s[k] == c && s[k])
			k++;
		f = k;
		while (s[f] != c && s[f])
			f++;
		if (p <= c_word(s, c))
			tb[p] = ft_strsub(s, k, f - k);
		k = f;
		p++;
	}
	tb[p] = 0;
	return (tb);
}
