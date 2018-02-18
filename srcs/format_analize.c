/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_analize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:45:28 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 15:45:29 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_format2(t_p *p, char *format, int j)
{
	int i;

	i = -1;
	while (i++ < 2 && f_size_modifier(format[j]))
		j++;
	if (i != -1)
	{
		i == 1 ? (p->f.modifier = format[--j]) :
		(p->f.modifier = format[--j] - 32);
		j++;
	}
	if (f_conversion(format[j]))
		p->f.conversion = format[j];
	return (j);
}

int		write_width(t_p *p, char *format, va_list ar, int j)
{
	while (f_field_width(format[j]))
	{
		if (format[j] == '*')
		{
			if ((p->f.width = va_arg(ar, int)) < 0)
				p->left_justify = 1;
			p->f.width = ABS(p->f.width);
			j++;
		}
		else
		{
			p->f.width = ft_atoi(&format[j]);
			while (f_field_width(format[j]) && format[j] != '*')
				j++;
		}
	}
	return (j);
}

int		write_precision(t_p *p, char *format, va_list ar, int j)
{
	if (f_precision(format[j]))
	{
		p->precision = 1;
		if (format[++j] == '*')
		{
			if ((p->f.precision = va_arg(ar, int)) < 0)
			{
				p->f.precision = 0;
				p->precision = 0;
			}
		}
		else
			p->f.precision = ft_atoi(&format[j]);
		while (f_field_width(format[j]))
			j++;
	}
	return (j);
}

int		write_format(t_p *p, char *format, va_list ar, int j)
{
	int i;

	i = 0;
	while (f_flags(format[j]))
	{
		if (format[j] == 39)
		{
			p->apostr = 1;
			j++;
		}
		else
		{
			p->f.flags[i++] = format[j++];
			p->flags = 1;
		}
	}
	j = write_width(p, format, ar, j);
	j = write_precision(p, format, ar, j);
	return (write_format2(p, format, j));
}
