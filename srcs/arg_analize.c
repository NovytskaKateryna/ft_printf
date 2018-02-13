/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_analize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:21:01 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:45:56 by knovytsk         ###   ########.fr       */
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
		p->f.flags[i++] = format[j++];
		p->flags = 1;
	}
	j = write_width(p, format, ar, j);
	j = write_precision(p, format, ar, j);
	return (write_format2(p, format, j));
}

int		output_length(const char *f, va_list ar, t_p *p)
{
	int		j;
	int		format_len;
	char	*format;

	j = -1;
	format = ft_strdup(f);
	format_len = ft_strlen(format);
	while (++j < format_len)
	{
		if (format[j] == '%')
		{
			j = write_format(p, format, ar, ++j);
			if (!(p->f.conversion))
				p->value = ft_strdup(&format[j]);
		//printf("{flags->%s| width->%i precision->%i modifier->%c conversion->%c}\n", p->f.flags, p->f.width, p->f.precision, p->f.modifier, p->f.conversion);
			output_analize(p, ar);
			reset_values(p);
		}
		else
		{
			write(1, &format[j], 1);
			p->out_len++;
		}
	}
	ft_strdel(&format);
	return (p->out_len);
}
