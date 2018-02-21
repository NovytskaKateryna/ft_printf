/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sizes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:04:06 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/15 15:05:32 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		exp_size(t_p *p, int exp)
{
	int size;

	size = 0;
	if (exp == 0)
		size++;
	while (exp != 0)
	{
		exp /= 10;
		size++;
	}
	if (size < 2 && (p->f.conversion != 'a' && p->f.conversion != 'A'))
		size = 2;
	return (size);
}

void	i_part_size(t_p *p, unsigned long i_p)
{
	p->i_size = 0;
	if (i_p == 0)
		p->i_size++;
	while (i_p != 0)
	{
		i_p /= 10;
		p->i_size++;
	}
}

void 	f_part_size(t_p *p, unsigned long f_p)
{
	p->fr_size = 0;
	p->fr_size += p->zero_fr;
	while (f_p != 0)
	{
		f_p /= 10;
		p->fr_size++;
	}
}

void	round_ipart_for_a(t_p *p)
{
	p->f.precision = 1;
	round_fract_for_a(p);
//	printf("i_part->%llx fr_part->%llx\n", p->i_part, p->fr_part);
	if ((p->fr_part % 16) > 8)
		p->i_part = p->i_part + 1;
	p->fr_size = 0;
	p->dec_point = 0;
	p->f.precision = 0;
}

void	a_size(t_p *p, unsigned long i_p, unsigned long f_p)
{
	p->i_size = 0;
	if (i_p == 0)
		p->i_size++;
	while (i_p != 0)
	{
		i_p /= 16;
		p->i_size++;
	}
	p->fr_size = 0;
	f_p = p->fr_part;
	while (f_p != 0)
	{
		f_p /= 16;
		p->fr_size++;
	}
	if (p->f.precision)
		round_fract_for_a(p);
//	printf("fr->%llx size->%i\n", p->fr_part, p->fr_size);
	//printf("pres->%i\n", p->f.precision);
	while ((p->fr_part % 16) == 0 && p->fr_part != 0 && p->fr_size > 0 && !(p->f.precision))
	{
//		printf("while\n");
		p->fr_part /= 16;
		p->fr_size--;
	}
	if (!(p->f.precision) && p->precision)
		round_ipart_for_a(p);
}

void	g_size(unsigned long int f_p, t_p *p)
{
	while ((p->fr_part % 10) == 0 && p->fr_part != 0 && !(p->prefix) && !(p->exp))
		p->fr_part /= 10;
	i_part_size(p, p->i_part);
	f_part_size(p, p->fr_part);
	if ((p->i_size + p->fr_size) > p->f.precision)
	{
		if (round_parts_for_g(p))
			return ;
	}
	p->fr_size = 0;
	if (p->fr_part != 0 && p->f.precision != 1 && (p->i_size != p->f.precision))
	{
		p->dec_point = 1;
		p->fr_size += p->zero_fr;
	}
	else if (((p->fr_part == 0 && p->f.precision != 1) ||
		(p->i_size == p->f.precision)) && !(p->prefix))
		p->dec_point = 0;
	f_p = p->fr_part;
	while (f_p != 0 && (p->i_size + p->fr_size) < p->f.precision)
	{
		f_p /= 10;
		p->fr_size++;
	}
	(p->i_part == 0 && p->f.precision && p->fr_part != 0) ?
		(p->fr_size = p->f.precision) : p->fr_size;
}
