/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:11:40 by abassibe          #+#    #+#             */
/*   Updated: 2017/01/21 08:21:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			c;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	c = 0;
	while (c < n)
	{
		s2[c] = s1[c];
		c++;
	}
	return (dst);
}
