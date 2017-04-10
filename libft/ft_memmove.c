/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 21:44:31 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/01/13 12:28:58 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sdest;
	unsigned char	*ssrc;

	i = 0;
	ssrc = (unsigned char *)src;
	sdest = (unsigned char *)dest;
	if ((src < dest) && ((src + n) > dest))
	{
		while (n > 0)
		{
			sdest[n] = ssrc[n];
			n--;
		}
		sdest[n] = ssrc[n];
	}
	else
	{
		while (i < n)
		{
			sdest[i] = ssrc[i];
			i++;
		}
	}
	return (sdest);
}
