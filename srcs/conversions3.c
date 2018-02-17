/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:58:34 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 16:10:38 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		float_conversions(t_p *p, va_list ar, t_operation *oper)
{
	long double arg;

	if (p->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	if (!p->f.precision && !(p->precision))
		p->f.precision = 6;
	if (!(check_float_values(p, arg, p->f.conversion)))
		p->value = for_f_conv(p, arg);
	p->value_len = ft_strlen(p->value);
	p->f.precision = 0;
	p->precision = 0;
	if (p->value[0] == '-')
		p->minus_sign = 1;
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
	if (!(check_float_values(p, arg, p->f.conversion)))
		p->value = for_e_conv(p, arg);
	p->value_len = ft_strlen(p->value);
	p->f.precision = 0;
	p->precision = 0;
	if (p->value[0] == '-')
		p->minus_sign = 1;
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		scientific_notation_conversions(t_p *p, va_list ar, t_operation *oper)
{
	long double	arg;
	int			i;

	if (p->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	if (!(p->f.precision) && !(p->precision))
		p->f.precision = 6;
	else if (!(p->f.precision) && p->precision)
		p->f.precision = 1;
	i = ft_strlen(p->f.flags);
	while (--i >= 0)
		if (p->f.flags[i] == '#')
			p->prefix = 1;
	if (!(check_float_values(p, arg, p->f.conversion)))
		p->value = for_g_conv(p, arg);
	p->value_len = ft_strlen(p->value);
	p->f.precision = 0;
	p->precision = 0;
	(p->value[0] == '-') ? (p->minus_sign = 1) : 0;
	p->prefix = 0;
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		hexadecimal_notation_conversions(t_p *p, va_list ar, t_operation *oper)
{
	long double	arg;

	if (p->f.modifier == 'L')
		arg = va_arg(ar, long double);
	else
		arg = va_arg(ar, double);
	put_marks(p, ft_strlen(p->f.flags));
	if (!(check_float_values(p, arg, p->f.conversion)))
		p->value = for_a_conv(p, arg);
	p->value_len = ft_strlen(p->value);
	p->f.precision = 0;
	p->precision = 0;
	if (p->value[0] == '-')
		p->minus_sign = 1;
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		int_pointer_conversions(t_p *p, va_list ar, t_operation *oper)
{
	long int *arg;

	oper = 0;
	arg = va_arg(ar, long int*);
	*arg = (long int)p->out_len;
	return (0);
}
