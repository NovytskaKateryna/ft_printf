/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:34:01 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:49:55 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unsigned_conversions(t_p *p, va_list ar, t_operation *oper)
{
	p->arg = va_arg(ar, void*);
	if (p->f.conversion == 'x' || p->f.conversion == 'X')
		manage_unsigned_modifier(p, 16);
	else if (p->f.conversion == 'o' || p->f.conversion == 'O')
		manage_unsigned_modifier(p, 8);
	else if (p->f.conversion == 'u' || p->f.conversion == 'U')
		manage_unsigned_modifier(p, 10);
	else if (p->f.conversion == 'b')
		manage_unsigned_modifier(p, 2);
	p->value_len = ft_strlen(p->value);
	if (!(p->f.precision) && p->precision && !(p->flags))
	{
		p->value_len = 0;
		p->precision = 0;
	}
	manage_operations(p, oper);
	if (p->f.conversion == 'X')
		capital_hex(p->output);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		signed_conversions(t_p *p, va_list ar, t_operation *oper)
{
	p->arg = va_arg(ar, void*);
	manage_decimal_modidfier(p, 10);
	if (p->value[0] == '-')
		p->minus_sign = 1;
	p->value_len = ft_strlen(p->value);
	if (!(p->f.precision) && p->precision && p->value[0] == '0')
		p->value_len = 0;
	if (!(p->f.precision) && p->precision && !(p->flags))
		p->precision = 0;
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		pointer_conversions(t_p *p, va_list ar, t_operation *oper)
{
	int i;

	p->arg = va_arg(ar, void*);
	p->value = f_unsigned_int((unsigned long)p->arg, 16);
	p->value_len = ft_strlen(p->value);
	i = ft_strlen(p->f.flags);
	p->f.conversion = 'x';
	p->f.flags[i] = '#';
	p->pointer = 1;
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		persentage(t_p *p, va_list ar, t_operation *oper)
{
	ar = 0;
	p->value = ft_strdup("%");
	p->value_len = 1;
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}

int		no_conversion_output(t_p *p, va_list ar, t_operation *oper)
{
	int i;

	ar = 0;
	p->value_len = 1;
	i = ft_strlen(p->f.flags);
	put_marks(p, i);
	if (p->f.width)
		manage_width(p, 0, 0, 0);
	manage_operations(p, oper);
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}
