/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_g_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:13:18 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/13 13:13:19 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_exp_size(unsigned long int i_p, unsigned long int f_p, t_p *p)
{
	int n;

	p->i_size = 0;
	n = 0;
	if (i_p == 0)
		p->i_size++;
	while (i_p != 0)
	{
		i_p /= 10;
		p->i_size++;
	}
	if (p->f.precision >= p->i_size)
	{
		n = p->f.precision - p->i_size;
		while (n++ < p->f.precision)
		{
			if ((p->fr_part % 10) > 5)
				p->fr_part = p->fr_part / 10 + 1;
			else
				p->fr_part /= 10;
		}
	}
	else if (p->i_size > p->f.precision)
	{
		n = p->i_size;
		while (n-- > p->f.precision)
		{
			if ((p->i_part % 10) > 5)
				p->i_part = p->i_part / 10 + 1;
			else
				p->i_part /= 10;
		}
		return (p->i_size);
	}
	while ((p->fr_part % 10) == 0 && p->fr_part != 0)
		p->fr_part /= 10;
	if (p->fr_part != 0)
	{
		p->dec_point = 1;
		p->fr_size += p->zero_fr;
	}
	f_p = p->fr_part;
	while (f_p != 0 && (p->i_size + p->fr_size) <= p->f.precision)
	{
		f_p /= 10;
		p->fr_size++;
	}
//	printf("i_part->%lu fr_part->%lu i_size->%i fr_size->%i\n", p->i_part, p->fr_part, p->i_size, p->fr_size);
	return (p->i_size + p->fr_size);
}

char	*exponent_g_notation(t_p *p, char *str, int size, int neg)
{
	int n;

	n = -1;
	str[size] = '\0';
	while (++n < p->exp_size)
	{
		str[--size] = (p->exp % 10) + 48;
		p->exp /= 10;
	}
	str[--size] = p->exp_sign;
	str[--size] = p->f.conversion;
	while ((p->fr_part % 10) == 0)
			p->fr_part /= 10;
	while (p->fr_size-- > 0)
	{
		if (p->fr_part == 0)
			str[--size] = '0';
		else
			str[--size] = (p->fr_part % 10) + 48;
		p->fr_part /= 10;
	}
	if (p->dec_point)
		str[--size] = '.';
	while (p->i_size-- > 0)
	{
		str[--size] = (p->i_part % 10) + 48;
		p->i_part /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char	*g_notation(t_p *p, char *str, int size, int neg)
{
	str[size] = '\0';
	while (p->fr_size-- > 0)
	{
		if (p->fr_part != 0)
			str[--size] = (p->fr_part % 10) + 48;
		else
			str[--size] = '0';
		p->fr_part /= 10;
	}
	if (p->dec_point)
		str[--size] = '.';
	while (p->i_size-- > 0)
	{
		str[--size] = (p->i_part % 10) + 48;
		p->i_part /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char	*for_g_notation(t_p *p, long double num)
{
	char		*str = NULL;
	int			size;
	int 		neg;

	neg = 0;
	if (num < 0)
	{
		num *= (-1);
		neg = 1;
	}
	p->i_part = 0;
	p->fr_size = 0;
	p->dec_point = 0;
	get_exponent(p, num);
	// printf("exp->%i sign->%c\n", p->exp, p->exp_sign);
	// printf("pres->%i\n", p->f.precision);
	if ((p->exp > 4 && p->exp_sign == '-') ||
		(p->exp >= p->f.precision && p->exp_sign == '+'))
	{
		separate_num(p, num);
		//printf("i_part->%lu fr_part->%lu\n", p->i_part, p->fr_part);
		if ((p->exp_size = ft_double_size(p->exp)) < 2)
			p->exp_size = 2;
		size = g_exp_size(p->i_part, p->fr_part, p) + 
				p->exp_size + p->dec_point;
		//printf("i_size->%i fr_size->%i\n", p->i_size, p->fr_size);
		if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		if (p->f.conversion == 'g')
			p->f.conversion = 'e';
		else if (p->f.conversion == 'g')
			p->f.conversion = 'E';
		str = exponent_g_notation(p, str, size, neg);
	}
	else
	{
	//	printf("num->%Lf\n", num);
		separate_num(p, num);
		//printf("i_part->%lu fr_part->%lu\n", p->i_part, p->fr_part);
		// printf("zero->%i\n", p->zero_fr);
		size = g_exp_size(p->i_part, p->fr_part, p) + neg + p->dec_point;
	//	printf("size->%i\n", size);
		if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		str = g_notation(p, str, size, neg);
	}
	//printf("str->%s\n", str);
	return (str);
}