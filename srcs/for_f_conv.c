/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_f_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:52:19 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/15 15:04:48 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	separate_num(t_p *p, long double num)
{
	long double fract_part;
	int			n;

	p->i_part = (unsigned long int)num;
	fract_part = num - p->i_part;
	n = 0;
	while (n < p->f.precision)
	{
		fract_part *= 10.0000;
		p->fr_part = (unsigned long int)(fract_part + 0.5);
		if ((int)fract_part == 0)
			p->zero_fr++;
		n++;
	}
}

char	*f_str(t_p *p, char *str, int size)
{
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
	return (str);
}

char	*for_f_conv(t_p *p, long double num)
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
	separate_num(p, num);
	(!(p->f.precision) && p->precision) ? 0 : (p->dec_point = 1);
	p->fr_size = p->f.precision;
	i_part_size(p, p->i_part);
	size = p->i_size + p->fr_size + neg + p->dec_point;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = f_str(p, str, size);
	if (neg)
		str[0] = '-';
	return (str);
}
