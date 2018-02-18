/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_a_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:53:38 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/18 15:37:18 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_exponent_for_a(t_p *p, long double num)
{
	p->exp = 0;
	if (num > 9.99)
	{
		while (num > 1.99)
		{
			num /= 2;
			p->exp++;
		}
		p->exp_sign = '+';
	}
	else if (num < 0.2)
	{
		while (num < 1.0)
		{
			num *= 2;
			p->exp++;
		}
		p->exp_sign = '-';
	}
	p->num = num;
}

void	round_fract_for_a(t_p *p)
{
	int n;

	n = 0;
	while (p->fr_size-- > p->f.precision)
	{
		((p->fr_part % 16) >= 8 &&
		((p->fr_part / 16) % 16) != (p->fr_part % 16)) ?
		(p->fr_part = p->fr_part / 16 + 1) : (p->fr_part /= 16);
	}
	p->fr_size = p->f.precision;
}

char	*a_str(t_p *p, char *str, int size, char hex)
{
	while (p->exp_size-- > 0)
	{
		str[--size] = (p->exp % 10) + 48;
		p->exp /= 10;
	}
	str[--size] = p->exp_sign;
	str[--size] = p->f.conversion + 15;
	while (p->fr_size-- > 0)
	{
		while (p->zero_fr-- > 0 && p->fr_size-- > 0)
			str[--size] = '0';
		str[--size] = (p->fr_part % 16) +
			((p->fr_part % 16) >= 10 ? (hex - 10) : '0');
		p->fr_part /= 16;
	}
	p->dec_point ? str[--size] = '.' : size;
	while (p->i_size-- > 0)
	{
		str[--size] = (p->i_part % 16) +
			((p->i_part % 16) >= 10 ? (hex - 10) : '0');
		p->i_part /= 16;
	}
	(p->zero_pad) ? (str[--size] = '0') : size;
	str[--size] = p->f.conversion + 23;
	return (str);
}

void	separate_num_for_a(t_p *p, long double num)
{
	long double fract_part;
	int			pres;

	p->i_part = (unsigned long int)num;
	fract_part = num - p->i_part;
	p->fr_part = 0;
	pres = 0;
	while (pres < 52)
	{
		fract_part *= 2.0;
		p->fr_part = (unsigned long int)(fract_part + 0.1);
		if ((int)(fract_part * 4) == 0)
			p->zero_fr++;
		pres++;
	}
}

char	*for_a_conv(t_p *p, long double num)
{
	char	*str;
	int		size;

	if (num < 0)
	{
		num *= (-1);
		p->minus_sign = 1;
	}
	(num != 0.0) ? get_exponent_for_a(p, num) : 0;
	(p->exp == 0) ? (p->exp_sign = '+') : 0;
	separate_num_for_a(p, p->num);
	p->zero_fr *= 2;
	p->exp_size = exp_size(p, p->exp);
	((!(p->f.precision) && p->precision) || num == 0.0) ? (p->dec_point = 0) :
														(p->dec_point = 1);
	a_size(p, p->i_part, p->fr_part);
	size = p->i_size + p->fr_size + p->exp_size + p->dec_point +
		p->minus_sign + p->zero_pad + 4;
	str = (char*)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	(p->f.conversion == 'a') ? (str = a_str(p, str, size, 'a')) :
								(str = a_str(p, str, size, 'A'));
	str[p->minus_sign] = '0';
	p->minus_sign ? str[0] = '-' : 0;
	return (str);
}
