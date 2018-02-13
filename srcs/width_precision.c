/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:43:32 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 17:30:43 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_width(t_p *p, int start, int j, int end)
{
	end = p->f.width - p->value_len;
	if (p->left_justify && !(p->f.conversion == 'c' && p->value[0] == 0))
	{
		start = p->value_len;
		end = p->f.width;
	}
	while (start < end)
		p->output[start++] = ' ';
	if (p->left_justify)
	{
		start = p->space + p->prefix;
		end = p->value_len + p->space + p->prefix;
	}
	else
		end = p->f.width;
	if (p->f.conversion == 'c' && p->value[0] == 0 && p->left_justify)
	{
		write(1, p->value, p->value_len);
		p->out_len += p->value_len;
		p->value_len = 0;
		end = 0;
	}
	while (start < end && p->value != NULL)
		p->output[start++] = p->value[j++];
}

void	left_justify_precision(t_p *p, int start, int end, int j)
{
	if (p->prefix == 2)
	{
		start = p->prefix;
		p->f.precision += p->prefix;
	}
	else if (p->minus_sign)
	{
		start = p->minus_sign;
		p->f.precision += p->minus_sign;
	}
	else
		start = p->plus_sign;
	end = p->f.precision - p->value_len + p->minus_sign + p->plus_sign;
	while (start < end)
		p->output[start++] = '0';
	j = p->minus_sign;
	while (end < p->f.precision + p->plus_sign)
		p->output[end++] = p->value[j++];
}

void	string_precision(t_p *p, int start, int end, int j)
{
	if (p->f.width > p->f.precision || p->f.precision > p->value_len)
		end = p->f.width;
	else
		end = p->f.precision;
	if (p->f.precision > p->value_len)
	{
		if (p->f.width > p->value_len)
			end = p->f.width;
		else
			end = p->value_len;
	}
	while (start < end && p->f.width)
		p->output[start++] = ' ';
	j = 0;
	start = 0;
	if (p->value_len >= p->f.precision && !(p->left_justify))
		start = end - p->f.precision;
	else if (p->value_len < p->f.precision && p->f.width)
		start = end - p->value_len;
	if (p->left_justify && p->value_len > p->f.precision)
		end = p->f.precision;
	if (p->value_len < p->f.precision && !(p->f.width))
		end = p->value_len;
	while (start < end && p->value)
		p->output[start++] = p->value[j++];
}

void	manage_precision(t_p *p)
{
	int start;
	int end;
	int j;

	if (p->value_len <= p->f.precision && p->f.conversion != 's')
	{
		(p->f.width >= p->f.precision) ? (start = p->f.width - p->f.precision) :
			(start = p->minus_sign + p->prefix + p->space);
		(p->f.width >= p->f.precision) ? (end = p->f.width - p->value_len) :
			(end = p->f.precision - p->value_len +
				p->minus_sign + p->prefix + p->space);
		if ((p->minus_sign || !(p->left_justify)) && p->f.width)
		{
			if (p->minus_sign)
				p->output[start - p->minus_sign] = '-';
			end += p->minus_sign;
			while (start < end)
				p->output[start++] = '0';
			j = p->minus_sign;
			while (end < p->f.precision + p->minus_sign + p->prefix + p->space)
				p->output[end++] = p->value[j++];
		}
		else if (p->left_justify || !(p->f.width))
			left_justify_precision(p, 0, 0, 0);
	}
}
