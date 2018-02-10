/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_analize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:21:01 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/24 10:21:02 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	write_format2(t_p *p, char *format, int j)
{
	int i;

	i = -1;
	while (i++ < 2 && f_size_modifier(format[j]))                //[modifier]
			j++;
	if (i != -1)
	{
		i == 1 ? (p->f.modifier = format[--j]) :
		(p->f.modifier = format[--j] - 32);
			j++;
	}
	if (f_conversion(format[j]))                       //[conversion]
		p->f.conversion = format[j];
	return (j);
}

int 	write_format(t_p *p, char *format, int j)
{
	int i;
	
	i = 0;
	while (f_flags(p->format[j]))                   //[flags]
	{
		p->f.flags[i++] = p->format[j++];
		p->flags = 1;
	}
	if (f_field_width(p->format[j]))                //[width]
	{
		p->f.width = ft_atoi(&format[j]);
		while (f_field_width(format[j]))
			j++;
	}
	if (f_precision(format[j]))                      //[precision]
	{
		p->precision = 1;
		p->f.precision = ft_atoi(&format[++j]);
		while (f_field_width(format[j]))
			j++;
	}
	return (write_format2(p, format, j));
}

int		output_length(const char *f, va_list ar)
{
	t_p 	*p;
	int 	j;

	p = p_initialise(f);
	j = -1;
	while (++j < p->format_len)
	{
		if (p->format[j] == '%')
		{
			j = write_format(p, p->format, ++j);
			// printf("flags->%s| width->%i precision->%i modifier->%c conversion->%c\n", p->f.flags, p->f.width, p->f.precision,
			// 	p->f.modifier, p->f.conversion);
			if (!(p->f.conversion))
				p->value = ft_strdup(&p->format[j]);
			output_analize(p, ar);
			reset_values(p);
		}
		else
		{
			write(1, &p->format[j], 1);
			p->out_len++;
		}
	}
	//ft_strdel(&p->format);
	free(p);
	return (p->out_len);
}
