/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:54:25 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:56:52 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	p->i_part = 0;
	p->fr_part = 0;
	p->zero_fr = 0;
	p->dec_point = 0;
	p->exp = 0;
	p->num = 0;
	ft_bzero(p->f.flags, 5);
}

t_p		*p_initialise(void)
{
	t_p *k;

	k = (t_p*)malloc(sizeof(t_p));
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
	k->i_part = 0;
	k->fr_part = 0;
	k->zero_fr = 0;
	k->dec_point = 0;
	k->exp = 0;
	k->num = 0;
	ft_bzero(k->f.flags, 5);
	return (k);
}

void	array_ot_analizers(t_analizer *analizer)
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
	analizer['e'] = &exponent_conversions;
	analizer['E'] = &exponent_conversions;
	analizer['f'] = &float_conversions;
	analizer['F'] = &float_conversions;
	analizer['g'] = &scientific_notation_conversions;
	analizer['G'] = &scientific_notation_conversions;
	analizer['a'] = &hexadecimal_notation_conversions;
	analizer['A'] = &hexadecimal_notation_conversions;
	analizer['n'] = &int_pointer_conversions;
}

void	array_ot_operation(t_operation *flag_operation)
{
	flag_operation['-'] = &alternative_output;
	flag_operation['0'] = &zero_padding;
	flag_operation['+'] = &sign_production;
	flag_operation[' '] = &space_production;
	flag_operation['#'] = &alternative_output;
}

void	output_analize(t_p *p, va_list ar)
{
	static t_analizer	*analizer = NULL;
	static t_operation	*flag_operation = NULL;

	if (analizer == NULL && flag_operation == NULL)
	{
		analizer = (t_analizer*)malloc(sizeof(t_analizer) * 256);
		flag_operation = (t_operation*)malloc(sizeof(t_operation) * 256);
		array_ot_analizers(analizer);
		array_ot_operation(flag_operation);
	}
	p->out_len += analizer[(int)p->f.conversion](p, ar, flag_operation);
	if (p->value_len)
		write(1, p->output, p->value_len);
	if (p->value)
		ft_strdel(&p->value);
}
