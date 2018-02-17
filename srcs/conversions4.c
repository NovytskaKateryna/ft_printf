/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:56:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 16:09:49 by knovytsk         ###   ########.fr       */
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

int		write_nonpritable(t_p *p, char *s, int n, int j)
{
	if (s[j] == '\0' || s[j] == '\a' || s[j] == '\b' ||
		s[j] == '\t' || s[j] == '\n' ||	s[j] == '\v' ||
		s[j] == '\f' || s[j] == '\r' || s[j] == '\e')
		p->output[n++] = 92;
	else
		p->output[n++] = 94;
	if ((s[j] >= 1 && s[j] <= 6) || (s[j] >= 14 && s[j] <= 31))
		p->output[n] = s[j] + 64;
	else if (s[j] == '\0')
		p->output[n] = '0';
	else if (s[j] == '\a')
		p->output[n] = 'a';
	else if (s[j] == '\b')
		p->output[n] = 'b';
	else if (s[j] == '\t')
		p->output[n] = 't';
	else if (s[j] == '\n')
		p->output[n] = 'n';
	else if (s[j] == '\v')
		p->output[n] = 'v';
	else if (s[j] == '\f')
		p->output[n] = 'f';
	else if (s[j] == '\r')
		p->output[n] = 'r';
	else if (s[j] == '\e')
		p->output[n] = 'e';
	return (2);
}

int		str_with_no_printable(t_p *p, va_list ar, t_operation *oper)
{
	char	*str;
	int		i;
	int		n;
	int		j;

	str = va_arg(ar, char*);
	oper = 0;
	i = 0;
	n = 0;
	while (str[n])
	{
		if ((str[n] >= 0 && str[n] <= 31) || str[n] == 127 ||
			str[n + 1] == 0)
			i++;
		n++;
	}
	i += n;
	n = -1;
	j = 0;
	while (++n < i)
	{
		if (str[j] >= 0 && str[j] <= 31)
			n += write_nonpritable(p, str, n, j++);
		p->output[n] = str[j++];
	}
	p->value_len = ft_strlen(p->output);
	return (p->value_len);
}
