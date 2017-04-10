/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 21:51:08 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/11/01 11:38:24 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *small)
{
	int		len;

	if (!small[0])
		return ((char *)big);
	len = ft_strlen(small);
	if (len == 0)
		return ((char *)big);
	while (*big)
	{
		if (ft_memcmp(big++, small, len) == 0)
			return ((char *)big - 1);
	}
	return (NULL);
}
