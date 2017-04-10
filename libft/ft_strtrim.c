/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 22:18:22 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/11/01 11:43:11 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (!s)
		return ("");
	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (s[i] == '\0')
		return ("");
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len++;
	if (!(new = (char *)malloc(sizeof(char) * (len - i) + 1)))
		return (NULL);
	while (s[i] && i < len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
