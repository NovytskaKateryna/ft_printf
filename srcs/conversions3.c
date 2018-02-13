/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:58:34 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/12 15:58:36 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	float_conversions(t_p *p, va_list ar, t_operation *oper)
{
	long double arg;

	if (p->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else 
		arg = va_arg(ar, double);
	if (!p->f.precision && !(p->precision))
		p->f.precision = 6;
	p->value = for_double(p, arg);
	p->value_len = ft_strlen(p->value);
	p->f.precision = 0;
	p->precision = 0;
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		exponent_conversions(t_p *p, va_list ar, t_operation *oper)
{
	long double	arg;

	if (p->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	if (!p->f.precision && !(p->precision))
		p->f.precision = 6;
	p->value = for_exponent(p, arg);
	p->value_len = ft_strlen(p->value);
	p->f.precision = 0;
	p->precision = 0;
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		scientific_notation_conversions(t_p *p, va_list ar, t_operation *oper)
{
	long double	arg;

	if (p->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	if (!(p->f.precision) && !(p->precision))
		p->f.precision = 6;
	else if (!(p->f.precision) && p->precision)
		p->f.precision = 1;
	p->value = for_g_notation(p, arg);
	p->value_len = ft_strlen(p->value);
	p->f.precision = 0;
	p->precision = 0;
//	printf("output->%s\n", p->output);
	//printf("value->%s len->%i\n", p->value, p->value_len);
	manage_operations(p, oper);
//	printf("output->%s\n", p->output);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}