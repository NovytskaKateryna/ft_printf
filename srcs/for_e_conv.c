/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_e_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:54:26 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/13 11:54:27 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	get_exponent(t_p *p, long double num)
{
	p->exp = 0;
	if (num > 9.99)
	{
		while (num > 9.99)
		{
			num /= 10;
			p->exp++;
		}
		p->exp_sign = '+';
	}
	else if (num < 1.0)
	{
		while (num < 1.0)
		{
			num *= 10;
			p->exp++;
		}
		p->exp_sign = '-';
	}
}

static	char 	*make_str(t_p *p, char *str, int size, int neg)
{
	int n;
	int pres;

	str[size] = '\0';
	n = -1;
	pres = p->f.precision;
	while (++n < p->exp_size)
	{
		str[--size] = (p->exp % 10) + 48;
		p->exp /= 10;
	}
	str[--size] = p->exp_sign;
	str[--size] = p->f.conversion;
	while (pres-- > 0 && --size > 0)
	{
		str[size] = (p->fr_part % 10) + 48;
		p->fr_part /= 10;
	}
	str[--size] = '.';
	while (--size >= 0)
	{
		str[size] = (p->i_part % 10) + 48;
		p->i_part /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char 		*for_exponent(t_p *p, long double num)
{
	char	*str;
	int		size;
	int		neg;

	neg = 0;
	if (num < 0)
	{
		num *= (-1);
		neg = 1;
	}
	p->i_part = 0;
	get_exponent(p, num);
	separate_num(p, num);
	if ((p->exp_size = ft_double_size(p->exp)) < 2)
		p->exp_size = 2;
	size = ft_double_size(p->i_part) + neg + p->f.precision +
			p->exp_size + 3;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = make_str(p, str, size, neg);
	return (str);
}