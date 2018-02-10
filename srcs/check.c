/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:28:55 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/26 21:28:56 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	f_flags(char f)
{
	if (f == '-' || f == '0' || f == '+' || f == ' ' || f == '#')
		return (1);
	return (0);
}

int 	f_field_width(char f)
{
	if (f >= '0' && f <= '9')
		return (1);
	return (0);
}

int 	f_precision(char f)
{
	if (f == '.')
		return (1);
	return (0);
}

int 	f_size_modifier(char f)
{
	if (f == 'z' || f == 'j' || f == 'l' || f == 'h')
		return (1);
	return (0);
}

int 	f_conversion(char f)
{
	if (f == 'c' || f == 'C' || f == 's' || f == 'S' || f == '%' ||
		f == 'd' || f == 'i' || f == 'o' || f == 'u' || f == 'x' ||
		f == 'D' || f == 'O' || f == 'U' || f == 'X' || f == 'p')
		return (1);
	return (0);
}
