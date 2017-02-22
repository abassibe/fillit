/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:48:49 by abassibe          #+#    #+#             */
/*   Updated: 2017/01/21 07:26:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t c;

	c = 0;
	while (src[c] != '\0' && c < n)
	{
		dst[c] = src[c];
		c++;
	}
	while (c < n)
	{
		dst[c] = '\0';
		c++;
	}
	return (dst);
}
