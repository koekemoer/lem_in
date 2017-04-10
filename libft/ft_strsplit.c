/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 22:18:31 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/11/01 11:42:48 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		parts_nr(char const *s, char c)
{
	int			i;
	int			len;
	int			is_word;

	i = 0;
	len = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] == c && is_word == 1)
			is_word = 0;
		if (s[i] != c && is_word == 0)
		{
			is_word = 1;
			len++;
		}
		i++;
	}
	return (len);
}

static int		part_len(char const *s, char c, int i)
{
	int			len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char			*new_str(char const *s, char c)
{
	int			i;
	char		*new;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(new = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	int			parts;
	int			y;
	int			i;

	y = 0;
	i = 0;
	if (s)
	{
		parts = parts_nr(s, c);
		if (!(arr = (char **)malloc(sizeof(*arr) * parts + 1)))
			return (NULL);
		while (parts > 0)
		{
			while (s[i] && s[i] == c)
				i++;
			arr[y] = new_str(&s[i], c);
			y++;
			i = i + part_len(s, c, i);
			parts--;
		}
		arr[y] = 0;
		return (arr);
	}
	return (NULL);
}
