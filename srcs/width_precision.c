/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:43:32 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/02 16:43:33 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	manage_width(t_p *p)
{
	int start;
	int j;
	int end;

//	printf("value_len->%i width->%i\n", p->value_len, p->f.width);
	j = 0;
	start = 0;
	end = p->f.width - p->value_len;
	//printf("output->|%s|\n", p->output);
	if (p->left_justify)
	{
		start = p->value_len;
		end = p->f.width;
	}
//	printf("for width: start->%i end->%i \n", start, end);
	while (start < end)                                  					//for width
		p->output[start++] = ' ';
	if (p->left_justify)
	{
		start = p->space + p->prefix;
		end = p->value_len + p->space + p->prefix;
	}
	else
		end = p->f.width;
//	printf("for value: end->%i start->%i\n", end, start);
	while (start < end && p->value != NULL)                                  //for value
		p->output[start++] = p->value[j++];
//	printf("width_output->%s|\n", p->output);
}

void 	left_justify_precision(t_p *p, int start, int end, int j)
{
//	printf("left\n");
	if (p->prefix == 2)
	{
		start = p->prefix;
		p->f.precision += p->prefix;
	}
	else if (p->minus_sign)
	{
		start = p->minus_sign;
		p->f.precision += p->minus_sign;
	}
	else
		start = p->plus_sign;
	//			printf("precision->%i\n", p->f.precision);
		end = p->f.precision - p->value_len + p->minus_sign + p->plus_sign;
	//		printf("start->%i end->%i\n", start, end);
	while (start < end)
		p->output[start++] = '0';
	j = p->minus_sign;
	//printf("j->%i prefix->%i precision->%i\n", j, p->prefix, p->f.precision);
	while (end < p->f.precision + p->plus_sign)
		p->output[end++] = p->value[j++];
}

void 	string_precision(t_p *p, int start, int end, int j)
{
//	printf("len->%i output->|%s|\n", p->value_len, p->output);
	start = 0;
	(p->f.width > p->f.precision) ? (end = p->f.width) : (end = p->f.precision);
	if (p->f.precision > p->value_len)
		(p->f.width > p->value_len) ? (end = p->f.width) : (end = p->value_len);
//	printf("start->%i end->%i\n", start,end);
//	printf("output->|%s|\n", p->output);
	while (start < end && p->f.width)                                   //for width
		p->output[start++] = ' ';
	//printf("output->|%s|\n", p->output);
	j = 0;
//	printf("len->%i\n", p->value_len);
	start = 0;
	if (p->value_len >= p->f.precision && !(p->left_justify))
		start = end - p->f.precision; 
	else if (p->value_len < p->f.precision && p->f.width)
		start = end - p->value_len;
	if (p->left_justify && p->value_len > p->f.precision)
		end = p->f.precision;
	if (p->value_len < p->f.precision && !(p->f.width))
		end = p->value_len;
	// printf("output->|%s|\n", p->output);
	// printf("start->%i end->%i\n", start, end);
	while (start < end && p->value)
		p->output[start++] = p->value[j++];
//	printf("output->|%s|\n", p->output);
}

void 	manage_precision(t_p *p)
{
	int start;
	int end;
	int j;

//	printf("prec->%i\n", p->f.precision);
//	printf("len->%i\n", p->value_len);
	if (p->value_len <= p->f.precision && p->f.conversion != 's')
	{
		(p->f.width >= p->f.precision) ? (start = p->f.width - p->f.precision) :
								(start = p->minus_sign + p->prefix);
		(p->f.width >= p->f.precision) ? (end = p->f.width - p->value_len) :
								(end = p->f.precision - p->value_len + p->minus_sign + p->prefix);
		if ((p->minus_sign || !(p->left_justify)) && p->f.width)
			{
				//printf("if\n");
			//	 printf("start->%i end->%i\n", start, end);
				// printf("pos->%i\n", p->f.width - p->f.precision - p->minus_sign);
				if (p->minus_sign)
					p->output[start - p->minus_sign] = '-';
				end += p->minus_sign;
			//	printf("start->%i end->%i\n", start, end);
				while (start < end)
					p->output[start++] = '0';
				j = p->minus_sign;
				//printf("j->end->%i\n", end);
				while (end < p->f.precision + p->minus_sign + p->prefix)
					p->output[end++] = p->value[j++];
			}
		else if (p->left_justify || !(p->f.width))
				left_justify_precision(p, 0, 0, 0);
	}
}