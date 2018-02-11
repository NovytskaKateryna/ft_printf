/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:20:39 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:52:35 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_padding(t_p *p)
{
	int j;
	int end;

	j = p->f.width;
	end = p->plus_sign;
	if (p->left_justify || p->f.precision)
		return ;
	if (p->prefix)
		end = p->prefix + p->value_len;
	else if (p->plus_sign)
		end += p->value_len;
	while (j-- > end && (j - p->value_len) >= 0)
		p->output[j - p->value_len] = '0';
	if (p->minus_sign)
	{
		p->output[0] = '-';
		if (p->f.width - p->value_len > 0)
			p->output[p->f.width - p->value_len] = '0';
	}
}

void	sign_production(t_p *p)
{
	if (!(p->minus_sign) && p->value != NULL && !(p->pointer))
	{
		if (p->left_justify || !(p->f.width) || p->zero_pad)
			p->output[0] = '+';
		else
			p->output[p->f.width - p->value_len - p->plus_sign - 1] = '+';
	}
}

void	space_production(t_p *p)
{
	if (p->space && !(p->minus_sign) && p->f.conversion != '%' &&
			p->f.conversion != 0 && !(p->plus_sign) &&
			!(p->pointer) && p->f.conversion != 'c')
		p->output[0] = ' ';
}

void	alternative_output(t_p *p)
{
	if ((p->f.conversion == 'o' || p->f.conversion == 'O') && p->prefix)
	{
		if (p->left_justify || !(p->f.width))
			p->output[0] = '0';
		else
			p->output[p->f.width - p->value_len - 1] = '0';
	}
	if ((p->f.conversion == 'x' || p->f.conversion == 'X') && p->prefix)
	{
		if (p->f.width - p->value_len == 1)
			p->value_len--;
		if (p->left_justify || !(p->f.width) || p->zero_pad ||
				(p->f.precision > p->value_len))
		{
			p->output[0] = '0';
			p->output[1] = p->f.conversion;
		}
		else if (p->f.width)
		{
			p->output[p->f.width - p->value_len - 2] = '0';
			p->output[p->f.width - p->value_len - 1] = p->f.conversion;
		}
	}
}
