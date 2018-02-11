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
	while (f_flags(format[j]))                   //[flags]
	{
		p->f.flags[i++] = format[j++];
		p->flags = 1;
	}
	if (f_field_width(format[j]))                //[width]
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

int		output_length(const char *f, va_list ar, t_p *p)
{
	int 	j;
	int 	format_len;
	char 	*format;

	j = -1;
	format = ft_strdup(f);
	format_len = ft_strlen(format);
	//printf("format->|%s| format_len->%i\n", format, format_len);
	while (++j < format_len)
	{
		if (format[j] == '%')
		{
		//	printf("j->%c j->%i\n", p->format[j], j);
			j = write_format(p, format, ++j);
			// printf("{flags->%s| width->%i precision->%i modifier->%c conversion->%c}\n", p->f.flags, p->f.width, p->f.precision,
			// 	p->f.modifier, p->f.conversion);
			if (!(p->f.conversion))
				p->value = ft_strdup(&format[j]);
			output_analize(p, ar);
			reset_values(p);
			//printf("j->%c\n", p->format[j]);
		}
		else
		{
		//	printf("else\n");
			write(1, &format[j], 1);
			p->out_len++;
		}
	}
	//printf("outlen->%i\n", p->out_len);
	return (p->out_len);
}
