/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:54:25 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 16:14:51 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	additional_array_of_analizers(t_analizer *analizer)
{
	analizer['e'] = &exponent_conversions;
	analizer['E'] = &exponent_conversions;
	analizer['f'] = &float_conversions;
	analizer['F'] = &float_conversions;
	analizer['g'] = &scientific_notation_conversions;
	analizer['G'] = &scientific_notation_conversions;
	analizer['a'] = &hexadecimal_notation_conversions;
	analizer['A'] = &hexadecimal_notation_conversions;
	analizer['n'] = &int_pointer_conversions;
	analizer['b'] = &unsigned_conversions;
	analizer['k'] = &time_output;
	analizer['r'] = &str_with_no_printable;
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
	additional_array_of_analizers(analizer);
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
}
