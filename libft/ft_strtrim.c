/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:33:55 by abassibe          #+#    #+#             */
/*   Updated: 2017/01/26 18:45:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		c;
	int		k;
	int		p;

	if (s == NULL)
		return (NULL);
	c = 0;
	k = ft_strlen(s) - 1;
	p = 0;
	while (s[c] == ' ' || s[c] == ',' || s[c] == '\n' || s[c] == '\t')
		c++;
	while (s[k] == ' ' || s[k] == ',' || s[k] == '\n' || s[k] == '\t')
		k--;
	if (!(str = (char *)malloc(sizeof(char) *
					ft_strlen(s) - ((ft_strlen(s) - k) - c) + 1)))
		return (NULL);
	while (c <= k)
		str[p++] = s[c++];
	str[p] = '\0';
	return (str);
}
