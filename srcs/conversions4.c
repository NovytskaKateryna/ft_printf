/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:56:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/18 15:37:56 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str_one_more(t_p *p, char *time, int size)
{
	while (size > 8)
	{
		time[--size] = ((int)p->day % 10) + 48;
		p->day /= 10;
	}
	time[--size] = '-';
	while (size > 5)
	{
		time[--size] = ((int)p->month % 10) + 48;
		p->month /= 10;
	}
	time[--size] = '-';
	while (size > 0)
	{
		time[--size] = ((int)p->year % 10) + 48;
		p->year /= 10;
	}
	return (time);
}

char	*get_time_str(t_p *p)
{
	char	*time;
	int		size;

	size = 16;
	time = (char*)malloc(sizeof(char) * (size + 1));
	time[size] = '\0';
	while (size > 14)
	{
		time[--size] = ((int)p->min % 10) + 48;
		p->min /= 10;
	}
	time[--size] = ':';
	while (size > 11)
	{
		time[--size] = ((int)p->hour % 10) + 48;
		p->hour /= 10;
	}
	time[--size] = 'T';
	return (get_str_one_more(p, time, size));
}

int		time_output(t_p *p, va_list ar, t_operation *oper)
{
	long long int	date;
	int				in_year;

	oper = 0;
	date = va_arg(ar, long long int);
	in_year = (date / 31556926);
	p->year = in_year + 1970;
	p->month = (date / 2629743.83) - in_year * 12 + 1;
	p->day = (date / 86400) - in_year * 365.24 - 30;
	p->hour = (date / 60 / 60) % 24 + 2;
	p->min = (date / 60) % 60;
	p->value = get_time_str(p);
	p->value_len = ft_strlen(p->value);
	write(1, p->value, p->value_len);
	p->out_len += p->value_len;
	return (0);
}
