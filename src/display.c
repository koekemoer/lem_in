/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:44:12 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/06/09 13:44:16 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_arr(char **arr)
{
    ft_putstr(arr[0]);
    ft_putchar('-');
    ft_putendl(arr[1]);
}