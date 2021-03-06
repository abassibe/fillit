/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:30:38 by abassibe          #+#    #+#             */
/*   Updated: 2017/01/20 23:47:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int c;
	int k;

	c = 0;
	k = 0;
	while (s1[c] != '\0')
		c++;
	while (s2[k] != '\0')
	{
		s1[c] = s2[k];
		c++;
		k++;
	}
	s1[c] = '\0';
	return (s1);
}
