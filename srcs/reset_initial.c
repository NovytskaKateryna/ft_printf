/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_initial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:49:03 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 15:49:04 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_values(t_p *p)
{
	ft_bzero(p->output, 2048);
	p->value_len = 0;
	p->value = NULL;
	p->f.conversion = 0;
	p->f.width = 0;
	p->f.precision = 0;
	p->minus_sign = 0;
	p->apostr = 0;
	p->plus_sign = 0;
	p->left_justify = 0;
	p->prefix = 0;
	p->f.modifier = 0;
	p->zero_pad = 0;
	p->pointer = 0;
	p->precision = 0;
	p->space = 0;
	p->flags = 0;
	p->i_part = 0;
	p->fr_part = 0;
	p->zero_fr = 0;
	p->dec_point = 0;
	p->exp = 0;
	p->num = 0;
	ft_bzero(p->f.flags, 5);
}

t_p		*p_initialise(t_p *k)
{
	k = (t_p*)malloc(sizeof(t_p));
	ft_bzero(k->output, 2048);
	k->f.conversion = 0;
	k->out_len = 0;
	k->f.width = 0;
	k->f.precision = 0;
	k->minus_sign = 0;
	k->plus_sign = 0;
	k->left_justify = 0;
	k->prefix = 0;
	k->f.modifier = 0;
	k->zero_pad = 0;
	k->space = 0;
	k->pointer = 0;
	k->precision = 0;
	k->flags = 0;
	k->i_part = 0;
	k->fr_part = 0;
	k->zero_fr = 0;
	k->apostr = 0;
	k->dec_point = 0;
	k->exp = 0;
	k->num = 0;
	ft_bzero(k->f.flags, 5);
	return (k);
}
