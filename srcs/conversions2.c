/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:34:10 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:50:57 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wide_char_conversions(t_p *p, va_list ar, t_operation *oper)
{
	if ((p->arg = va_arg(ar, void*)) == NULL && (p->f.conversion == 's' ||
		p->f.conversion == 'S'))
		return (write(1, "(null)", 6));
	put_marks(p, ft_strlen(p->f.flags));
	if (p->left_justify || !(p->f.precision))
	{
		(!(p->f.precision) && p->precision) ? p->f.width :
			(p->f.width -= get_value_len(p));
		p->value_len = 0;
		manage_operations(p, oper);
		if (!(p->f.width && !(p->left_justify)))
			get_wide_char(p);
	}
	p->value_len = ft_strlen(p->output);
	if (p->value_len && !(p->f.precision))
	{
		write(1, p->output, p->value_len);
		p->out_len += p->value_len;
		if (!(p->f.precision) && p->precision)
			p->f.width = 0;
	}
	if (!(p->left_justify) && (p->f.width || p->f.precision))
		get_wide_char(p);
	p->value_len = 0;
	return (p->value_len);
}

int		char_conversions(t_p *p, va_list ar, t_operation *oper)
{
	if (p->f.modifier == 'l')
		return (wide_char_conversions(p, ar, oper));
	if ((p->arg = va_arg(ar, void*)) == NULL && ((p->f.conversion == 's' ||
		p->f.conversion == 'S') && !(p->precision)))
		return (write(1, "(null)", 6));
	if (p->f.conversion == 'c')
		p->value = ft_strdup((char*)&p->arg);
	else if (p->f.conversion == 's' && p->arg != NULL)
		p->value = ft_strdup((char*)p->arg);
	if (p->value != NULL)
		p->value_len = ft_strlen(p->value);
	if (p->arg == NULL && p->f.width && p->f.conversion == 's')
		p->value_len = 0;
	else if (p->f.conversion == 'c')
		p->value_len = 1;
	if (!(p->f.precision) && p->precision && p->f.conversion == 's')
	{
		p->value_len = 0;
		p->precision = 0;
	}
//	manage_operations(p, oper);
	(p->arg != NULL) ? (p->value_len = ft_strlen(p->output)) :
			(p->value_len += ft_strlen(p->output));
	return (p->value_len);
}
