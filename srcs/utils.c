/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:48:57 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 17:34:53 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	capital_hex(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] >= 97 && s[i] <= 102)
			s[i] -= 32;
	}
}

void	put_marks2(t_p *p)
{
	if ((p->f.conversion == 'x' || p->f.conversion == 'X') &&
		p->value[0] == '0' && !(p->f.precision))
		p->flags = 0;
	if ((p->f.conversion == 'c' || p->f.conversion == 'C' ||
		p->f.conversion == '%') && p->precision)
	{
		p->f.precision = 0;
		p->precision = 0;
	}
}

void	put_marks(t_p *p, int i)
{
	while (--i >= 0)
	{
		if (p->f.flags[i] == '-')
			p->left_justify = 1;
		else if (p->f.flags[i] == '+' && (p->f.conversion == 'i' ||
			p->f.conversion == 'd' || p->f.conversion == 'D'))
			p->plus_sign = 1;
		else if ((p->f.flags[i] == ' ' || p->f.flags[i] == '+') &&
				(p->f.conversion == 'i' || p->f.conversion == 'd' ||
				p->f.conversion == 'D') && !(p->minus_sign))
			p->space = 1;
		else if (p->f.flags[i] == '#' && (p->f.conversion == 'o' ||
			p->f.conversion == 'O') && p->value[0] != '0')
			p->prefix = 1;
		else if (p->f.flags[i] == '#' && (((p->f.conversion == 'x' ||
			p->f.conversion == 'X') && p->value[0] != '0') || p->pointer))
			p->prefix = 2;
		else if (p->f.flags[i] == '0')
			p->zero_pad = 1;
	}
	put_marks2(p);
}

void	manage_operations(t_p *p, t_operation *oper)
{
	int i;
	int j;

	put_marks(p, ft_strlen(p->f.flags));
	if (p->f.width && p->value_len < p->f.width)
		manage_width(p, 0, 0, 0);
	i = ft_strlen(p->f.flags);
	while (--i >= 0)
		oper[(int)p->f.flags[i]](p);
	if (p->f.precision && p->f.conversion == 's')
		string_precision(p, 0, 0, 0);
	else if ((!(p->f.width) || p->value_len >= p->f.width) &&
		p->value != NULL)
	{
		j = 0;
		p->plus_sign ? (i = p->prefix +
			p->plus_sign - p->minus_sign) : (i = p->prefix + p->space);
		while (j < p->value_len)
			p->output[i++] = p->value[j++];
	}
	if ((p->f.precision && p->value && p->precision))
		manage_precision(p);
	else if ((!(p->f.precision) && p->precision && !(p->flags)))
		p->output[p->prefix] = '\0';
}
