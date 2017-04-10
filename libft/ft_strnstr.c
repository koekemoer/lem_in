/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 21:51:19 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/11/01 11:36:35 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t		len;

	len = ft_strlen(small);
	if (len == 0)
		return ((char *)big);
	while (*big && len <= n--)
	{
		if (ft_memcmp(big++, small, len) == 0)
			return ((char *)big - 1);
	}
	return (NULL);
}
