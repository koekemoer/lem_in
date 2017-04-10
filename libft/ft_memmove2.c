/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:59:20 by mlamarre          #+#    #+#             */
/*   Updated: 2016/11/11 09:59:56 by mlamarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s2 < s1)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)s1)[i] = ((char *)s2)[i];
		}
	}
	else
	{
		while (i < n)
		{
			((char *)s1)[i] = ((char *)s2)[i];
			i++;
		}
	}
	return (s1);
}
