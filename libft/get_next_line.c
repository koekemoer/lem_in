/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:16:05 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/01/13 10:34:36 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_current_line(int const fd, char **part)
{
	char	*buf;
	char	*nstr;
	int		size;

	if (!(buf = ft_strnew(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	size = read(fd, buf, BUFF_SIZE);
	if (size > 0)
	{
		buf[size] = '\0';
		nstr = ft_strjoin(*part, buf);
		if (!(nstr))
			return (-1);
		free(*part);
		*part = nstr;
	}
	if (buf)
		free(buf);
	return (size);
}

int			get_next_line(int const fd, char **line)
{
	static char		*new = NULL;
	char			*endl_index;
	int				ret;

	if ((!new && (new = ft_strnew(sizeof(*new))) == NULL) || !line)
		return (-1);
	endl_index = ft_strchr(new, '\n');
	while (endl_index == NULL)
	{
		if ((ret = get_current_line(fd, &new)) == 0)
		{
			if (ft_strlen(new) == 0)
				return (0);
			new = ft_strjoin(new, "\n");
		}
		if (ret < 0)
			return (-1);
		else
			endl_index = ft_strchr(new, '\n');
	}
	*line = ft_strsub(new, 0, ft_strlen(new) - ft_strlen(endl_index));
	endl_index = ft_strdup(endl_index + 1);
	free(new);
	new = endl_index;
	return (1);
}
