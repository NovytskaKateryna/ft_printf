/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:54:25 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/02 16:54:26 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	array_of_analizers(f_analizer *analizer)
{
	analizer[0] = &no_conversion_output;
	analizer['%'] = &persentage;
	analizer['s'] = &char_conversions;
	analizer['S'] = &wide_char_conversions;
	analizer['p'] = &pointer_conversions;
	analizer['d'] = &signed_conversions;
	analizer['D'] = &signed_conversions;
	analizer['i'] = &signed_conversions;
	analizer['o'] = &unsigned_conversions;
	analizer['O'] = &unsigned_conversions;
	analizer['u'] = &unsigned_conversions;
	analizer['U'] = &unsigned_conversions;
	analizer['x'] = &unsigned_conversions;
	analizer['X'] = &unsigned_conversions;
	analizer['c'] = &char_conversions;
	analizer['C'] = &wide_char_conversions;
}

void 	array_of_operation(f_operation *flag_operation)
{
	flag_operation['-'] = &alternative_output;
	flag_operation['0'] = &zero_padding;
	flag_operation['+'] = &sign_production;
	flag_operation[' '] = &space_production;
	flag_operation['#'] = &alternative_output;
}

void	output_analize(t_p *p, va_list ar)
{
	static f_analizer	*analizer = NULL;
	static f_operation 	*flag_operation = NULL;

	if (analizer == NULL && flag_operation == NULL)
	{
		analizer = (f_analizer*)malloc(sizeof(f_analizer) * 256);
		flag_operation = (f_operation*)malloc(sizeof(f_operation) * 256);
		array_of_analizers(analizer);
		array_of_operation(flag_operation);
	}
	p->out_len += analizer[(int)p->f.conversion](p, ar, flag_operation);
//	printf("out_len->%i\n", p->out_len);
//	printf("output->|%s| value_len->%i\n", p->output, p->value_len);
	if (p->output && p->value_len)
		{
			//printf("write\n");
			write(1, p->output, p->value_len);
		}
}

void	reset_values(t_p *p)
{
	ft_bzero(p->output, 2048);
	p->value_len = 0;
	p->value = NULL;
	p->f.conversion = 0;
	p->f.width = 0;
	p->f.precision = 0;
	p->minus_sign = 0;
	p->plus_sign = 0;
	p->left_justify = 0;
	p->prefix = 0;
	p->f.modifier = 0;
	p->zero_pad = 0;
	p->pointer = 0;
	p->precision = 0;
	p->flags = 0;
	ft_bzero(p->f.flags, 5);
}

t_p 	*p_initialise(const char *format)
{
	t_p *k;

	k = (t_p*)malloc(sizeof(t_p));
	k->output = (char*)malloc(sizeof(char) * 2048);
	ft_bzero(k->output, 2048);
	k->f.conversion = 0;
	k->out_len = 0;
	k->f.width = 0;
	k->f.precision = 0;
	k->minus_sign = 0;
	k->plus_sign = 0;
	k->left_justify = 0;
	k->prefix = 0;
	k->f.modifier = 0;
	k->zero_pad = 0;
	k->pointer = 0;
	k->precision = 0;
	k->flags = 0;
	ft_bzero(k->f.flags, 5);
	k->format = ft_strdup(format);
	k->format_len = ft_strlen(k->format);
	return (k);
}
