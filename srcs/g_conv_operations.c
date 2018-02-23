/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_conv_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:14:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/22 14:14:45 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		round_parts_for_g(t_out *out)
{
	out = 0;
	// int n;

	// n = out->f.precision - out->d.i_size;
	// if (out->f.precision > out->d.i_size && out->d.i_part != 0)
	// {
		// while (n++ < out->f.precision)
		// 	((out->d.fr_part % 10) > 5) ? (out->d.fr_part = out->d.fr_part / 10 + 1) :
		// 		(out->d.fr_part /= 10);
		// out->d.fr_size = out->f.precision - out->d.i_size;
		// if (out->d.fr_part > 9 && !(out->d.exp))
		// {
		// 	out->d.fr_size = 0;
		// 	out->d.i_part += 1;
		// 	return (1);
		// }
		// if (out->d.fr_part == 1)
		// 	out->d.zero_fr--;
		// else if (out->d.fr_part == 0 && !(out->prefix))
		// {
		// 	out->d.dec_point = 0;
		// 	out->d.fr_size = 0;
		// }
//	}
	// else if (out->f.precision < out->d.i_size)
	// {
	// 	while (out->d.i_size-- > out->f.precision)
	// 		((out->d.i_part % 10) > 5) ? (out->d.i_part = out->d.i_part / 10 + 1) :
	// 			(out->d.i_part /= 10);
	// 	return (1);
	// }
	// else if (out->d.i_size == out->f.precision || (out->d.exp && out->d.fr_size > out->f.precision))
	// {
	// 	while (out->d.fr_part > 10)
	// 	((out->d.fr_part % 10) > 5) ? (out->d.fr_part = out->d.fr_part / 10 + 1) :
	// 			(out->d.fr_part /= 10);
	// 	((out->d.fr_part % 10) > 5) ? (out->d.i_part += 1) : out->d.i_part;
	// 	if (out->d.fr_part > 9 && out->d.exp)
	// 		out->d.i_part += 1;
	// 	out->d.dec_point = 0;
	// 	out->d.fr_size = 0;
	// 	return (1);
	// }
	 return (0);
}

void	round_fpart_for_g(t_out *out)
{
	int n;

	n = out->f.precision - out->d.i_size;
	while (n++ < out->f.precision)
		((out->d.fr_part % 10) > 5) ? (out->d.fr_part = out->d.fr_part / 10 + 1) :
				(out->d.fr_part /= 10);
	out->d.fr_size = out->f.precision - out->d.i_size;
}

void	round_ipart_for_g(t_out *out)
{
	if (out->f.precision < out->d.i_size)
	{
		while (out->d.i_size-- > out->f.precision)
			((out->d.i_part % 10) > 5) ? (out->d.i_part = out->d.i_part / 10 + 1) :
				(out->d.i_part /= 10);
	}
	else if (out->f.precision == 1)
	{
		out->f.precision = 2;
		round_fpart_for_g(out);
		if (out->d.fr_part >= 5)
			out->d.i_part += 1;
	}
	out->d.dec_point = 0;
	out->d.fr_size = 0;
}

void	g_size(t_out *out)
{
	while ((out->d.fr_part % 10) == 0 && out->d.fr_part != 0 &&
		!(out->prefix) && !(out->d.exp))
		out->d.fr_part /= 10;
	i_part_size(out, out->d.i_part, 10);
	f_part_size(out, out->d.fr_part, 10);
	if ((out->d.i_size + out->d.fr_size) > out->f.precision)
		round_fpart_for_g(out);
	if (out->f.precision)
		round_ipart_for_g(out);
	// out->d.fr_size = 0;
	// if (out->d.fr_part != 0 && out->f.precision != 1 && (out->d.i_size != out->f.precision))
	// {
	// 	out->d.dec_point = 1;
	// 	out->d.fr_size += out->d.zero_fr;
	// }
	// else if (((out->d.fr_part == 0 && out->f.precision != 1) ||
	// 	(out->d.i_size == out->f.precision)) && !(out->prefix))
	// 	out->d.dec_point = 0;
	// f_p = out->d.fr_part;
	// if ((out->d.i_size + out->d.fr_size) < out->f.precision)
	// {
	// 	f_p /= 10;
	// 	out->d.fr_size++;
	// }
	(out->d.i_part == 0 && out->f.precision && out->d.fr_part != 0) ?
		(out->d.fr_size = out->f.precision) : out->d.fr_size;
}
