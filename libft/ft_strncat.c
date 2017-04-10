/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 21:49:48 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/07/22 21:49:51 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(dest);
	while (i < n && src[i])
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
