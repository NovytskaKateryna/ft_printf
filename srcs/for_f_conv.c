/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_f_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:52:19 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/13 11:52:21 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_double_size(unsigned long i_p)
{
	int 	size;

	size = 0;
	if (i_p == 0)
		size++;
	while (i_p != 0)
	{
		i_p /= 10;
		size++;
	}
	return (size);
}

void 	separate_num(t_p *p, long double num)
{
	long double fract_part;
	int 		n;	

	p->i_part = (unsigned long int)num;
	fract_part = num - p->i_part;
//	printf("ffff->%Lf\n", fract_part);
	p->fr_part = 0;
	p->zero_fr = 0;
	n = 0;
	// if ((int)fract_part == 0)
	// 	p->zero_fr++;
//	printf("frat->%lu pre->%i\n", p->fr_part, p->f.precision);
	while (n < p->f.precision)
	{
		fract_part *= 10.0000;
	//	printf("fract->%Lf\n", fract_part);
		p->fr_part = (unsigned long int)(fract_part + 0.5);
		if ((int)fract_part == 0)
			p->zero_fr++;
	//	printf("fr->%lu\n", p->fr_part);
		n++;
	}
}

static char	*make_str(t_p *p, char *str, int size, int neg)
{
	int	pres;

	pres = p->f.precision;
	str[size] = '\0';
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

char	*for_double(t_p *p, long double num)
{
	char		*str;
	int			size;
	int 		neg;

	neg = 0;
	if (num < 0)
	{
		num *= (-1);
		neg = 1;
	}
	p->i_part = 0;
	separate_num(p, num);
	size = ft_double_size(p->i_part) + p->f.precision + neg + 1;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = make_str(p, str, size, neg);
	return (str);
}
