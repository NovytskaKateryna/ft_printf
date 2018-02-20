/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_g_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:13:18 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/15 14:55:39 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		round_parts_for_g(t_p *p)
{
	int n;

	n = p->f.precision - p->i_size;
	if (p->f.precision > p->i_size && p->i_part != 0)
	{
		while (n++ < p->f.precision)
			((p->fr_part % 10) > 5) ? (p->fr_part = p->fr_part / 10 + 1) :
				(p->fr_part /= 10);
		p->fr_size = p->f.precision - p->i_size;
		if (p->fr_part > 9 && !(p->exp))
		{
			p->fr_size = 0;
			p->i_part += 1;
			return (1);
		}
		if (p->fr_part == 1)
			p->zero_fr--;
		else if (p->fr_part == 0 && !(p->prefix))
		{
			p->dec_point = 0;
			p->fr_size = 0;
		}
	}
	else if (p->f.precision < p->i_size)
	{
		while (p->i_size-- > p->f.precision)
			((p->i_part % 10) > 5) ? (p->i_part = p->i_part / 10 + 1) :
				(p->i_part /= 10);
		return (1);
	}
	else if (p->i_size == p->f.precision && p->f.precision == 1)
	{
		((p->fr_part % 10) > 5 || (p->fr_part >= 5)) ? (p->i_part += 1) : p->i_part;
		(p->i_part > 9) ? (p->i_part /= 10) : p->i_part;
		p->fr_size = 0;
		return (1);
	}
	else if (p->i_size == p->f.precision || (p->exp && p->fr_size > p->f.precision))
	{
		while (p->fr_part > 10)
		((p->fr_part % 10) > 5) ? (p->fr_part = p->fr_part / 10 + 1) :
				(p->fr_part /= 10);
		((p->fr_part % 10) > 5) ? (p->i_part += 1) : p->i_part;
		if (p->fr_part > 9 && p->exp)
			p->i_part += 1;
		p->dec_point = 0;
		p->fr_size = 0;
		return (1);
	}
	return (0);
}

char	*exponent_g_str(t_p *p, char *str, int size)
{
	str[size] = '\0';
	while (p->exp_size-- > 0)
	{
		str[--size] = (p->exp % 10) + 48;
		p->exp /= 10;
	}
	str[--size] = p->exp_sign;
	str[--size] = p->f.conversion - 2;
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

char	*for_e_notation(t_p *p)
{
	char	*str;
	int		size;

	//printf("num->%Lf\n", p->num);
	separate_num(p, p->num);
	p->exp_size = exp_size(p, p->exp);
	g_size(p->fr_part, p);
//	printf("fr_part->%llu i_part->%llu\n", p->fr_part, p->i_part);
	size = p->fr_size + p->i_size + p->minus_sign +
			p->exp_size + p->dec_point + 2;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = exponent_g_str(p, str, size);
	return (str);
}

char	*for_f_notation(t_p *p, long double num)
{
	char	*str;
	int		size;

	//printf("num->%Lf\n", num);
	separate_num(p, num);
	p->exp = 0;
	g_size(p->fr_part, p);
//	printf("dec->%i\n", p->dec_point);
//	printf("i_part->%llu fr_part->%llu\n", p->i_part, p->fr_part);
	if (p->f.precision > p->i_size && p->prefix && p->i_part != 0)
		p->fr_size = p->f.precision - p->i_size;
//	printf("i_size->%i fr_size->%i\n", p->i_size, p->fr_size);
	size = p->fr_size + p->i_size + p->minus_sign + p->dec_point;
//	printf("size->%i\n", size);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
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

char	*for_g_conv(t_p *p, long double num)
{
	char	*str;

	if (num < 0.0 || num <= -0.0)
	{
		num *= (-1);
		p->minus_sign = 1;
	}
	(num != 0.0) ? get_exponent(p, num) : 0;
	(p->f.precision == 1 || num == 0.0) ? (p->dec_point = 0) :
		(p->dec_point = 1);
	(p->prefix) ? (p->dec_point = 1) : 0;
//	printf("exp->%i\n", p->exp);
//	printf("dec->%i\n", p->dec_point);
//	printf("pres->%i\n", p->f.precision);
//	printf("i_part->%llu fr_part->%llu \n", p->i_part, p->fr_part);
	if ((p->exp > 4 && p->exp_sign == '-' && p->f.precision > 1) ||
			(p->exp >= p->f.precision && p->exp_sign == '+'))
		str = for_e_notation(p);
	else
	{
		if (p->f.precision == 1 && p->exp > 4 && p->exp_sign == '-')
			p->f.precision = p->exp;
		str = for_f_notation(p, num);
	}
	return (str);
}
