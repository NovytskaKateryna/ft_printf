/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_wide_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:44:04 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:55:43 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_char_bytes(unsigned int ch)
{
	if (ch <= 127 || (ch < 256 && MB_CUR_MAX == 1))
		return (1);
	else if (ch >= 128 && ch <= 2047)
		return (2);
	else if (ch >= 2048 && ch <= 65535)
		return (3);
	else if (ch >= 65536 && ch <= 1114111)
		return (4);
	return (-1);
}

void	write_wide_char(unsigned int ch)
{
	int				bytes;
	unsigned char	to_write[4];

	bytes = get_char_bytes(ch);
	if (bytes == 1)
		to_write[0] = (char)ch;
	else if (bytes == 2)
	{
		to_write[0] = (ch >> 6) | 192;
		to_write[1] = (ch & 63) | 128;
	}
	else if (bytes == 3)
	{
		to_write[0] = (ch >> 12) | 224;
		to_write[1] = ((ch >> 6) & 63) | 128;
		to_write[2] = (ch & 63) | 128;
	}
	else if (bytes == 4)
	{
		to_write[0] = (ch >> 18) | 240;
		to_write[1] = ((ch >> 12) & 63) | 128;
		to_write[2] = ((ch >> 6) & 63) | 128;
		to_write[3] = (ch & 63) | 128;
	}
	write(1, to_write, bytes);
}

int		manage_wide_char_operations(t_p *p, unsigned int *str, int i)
{
	int j;
	int	len;

	len = 0;
	j = get_char_bytes((unsigned int)str[++i]);
	while (j <= p->f.precision)
	{
		j += get_char_bytes((unsigned int)str[++i]);
		len++;
	}
	if (p->f.width > p->f.precision)
	{
		i = -1;
		j = p->f.width;
		while (++i < len)
			j = p->f.width - get_char_bytes((unsigned int)str[i]);
		i = -1;
		while (++i < j)
			p->output[i] = ' ';
		p->value_len = ft_strlen(p->output);
		p->out_len += p->value_len;
		write(1, p->output, p->value_len);
	}
	return (len);
}

void	get_wide_char(t_p *p)
{
	unsigned int		*str;
	int					len;
	int					i;

	if (p->f.conversion == 'C' || p->f.conversion == 'c')
	{
		write_wide_char((unsigned int)p->arg);
		p->out_len += get_char_bytes((unsigned int)p->arg);
	}
	else if (p->f.conversion == 'S' || p->f.conversion == 's')
	{
		i = -1;
		len = 0;
		str = (unsigned int*)p->arg;
		while (str[len])
			len++;
		if (p->f.precision || p->precision)
			len = manage_wide_char_operations(p, str, 0);
		i = -1;
		while (++i < len)
		{
			write_wide_char((unsigned int)str[i]);
			p->out_len += get_char_bytes((unsigned int)str[i]);
		}
	}
}

int		get_value_len(t_p *p)
{
	int					i;
	unsigned int		*str;
	int					len;

	if (p->f.conversion == 'C' || p->f.conversion == 'c')
		p->value_len = get_char_bytes((unsigned int)p->arg);
	else if (p->f.conversion == 'S' || p->f.conversion == 's')
	{
		i = -1;
		len = 0;
		str = (unsigned int*)p->arg;
		while (str[len])
			len++;
		while (++i < len)
			p->value_len += get_char_bytes((unsigned int)str[i]);
	}
	return (p->value_len);
}
