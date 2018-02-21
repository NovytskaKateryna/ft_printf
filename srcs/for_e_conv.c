/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_e_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:54:26 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/15 15:00:54 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_exponent(t_p *p, long double num)
{
	p->exp = 0;
	if (num >= 9.99)
	{
		while (num > 9.99)
		{
			p->exp++;
			num /= 10;
		}
		p->exp_sign = '+';
	}
	else if (num <= 1.0)
	{
		while (num < 1.0)
		{
			p->exp++;
			num *= 10;
		}
		p->exp_sign = '-';
	}
	p->num = num;
}

char	*e_str(t_p *p, char *str, int size)
{
	str[size] = '\0';
	while (p->exp_size-- > 0)
	{
		str[--size] = (p->exp % 10) + 48;
		p->exp /= 10;
	}
	str[--size] = p->exp_sign;
	str[--size] = p->f.conversion;
	while (p->fr_size-- > 0)
	{
		str[--size] = (p->fr_part % 10) + 48;
		p->fr_part /= 10;
	}
	p->dec_point ? str[--size] = '.' : size;
	while (p->i_size-- > 0)
	{
		str[--size] = (p->i_part % 10) + 48;
		p->i_part /= 10;
	}
	p->minus_sign ? (str[0] = '-') : 0;
	return (str);
}

char	*for_e_conv(t_p *p, long double num)
{
	char	*str;
	int		size;

	if (num < 0)
	{
		num *= (-1);
		p->minus_sign = 1;
	}
	(num != 0.0) ? get_exponent(p, num) : 0;
	(p->exp == 0) ? (p->exp_sign = '+') : 0;
	separate_num(p, p->num);
	p->exp_size = exp_size(p, p->exp);
	p->fr_size = p->f.precision;
	i_part_size(p, p->i_part);
	(!(p->f.precision) && p->precision) ? 0 : (p->dec_point = 1);
	size = p->i_size + p->fr_size + p->minus_sign + p->dec_point +
			p->exp_size + 2;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = e_str(p, str, size);
	return (str);
}
