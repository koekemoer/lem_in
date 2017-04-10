/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 21:44:21 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/11/01 11:21:18 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*tmp_d;
	const unsigned char	*tmp_s;

	i = 0;
	tmp_d = dest;
	tmp_s = src;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		if (tmp_s[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
