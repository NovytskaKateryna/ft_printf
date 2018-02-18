/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apostr_production.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:00 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/18 15:39:04 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_apostr(t_p *p, char *str, int value_len, int size)
{
	int	ap;

	ap = 0;
	str[size] = '\0';
	while (size > p->minus_sign)
	{
		str[--size] = p->value[--value_len];
		ap++;
		if (ap == 3)
		{
			str[--size] = ',';
			ap = 0;
		}
	}
	p->minus_sign ? (str[0] = '-') : 0;
	return (str);
}

void	apostr_production(t_p *p)
{
	char	*str;
	int		size;
	int		ap;

	ap = 0;
	p->value_len -= p->minus_sign;
	(p->value_len != 3) ? (ap = p->value_len / 3) : ap;
	((p->value_len % 3) == 0 && (p->value_len != 3)) ? (ap -= 1) : ap;
	p->value_len += p->minus_sign;
	size = p->value_len + ap;
	str = (char*)malloc(sizeof(char) * (size + 1));
	str = str_apostr(p, str, p->value_len, size);
	free(p->value);
	p->value = str;
	p->value_len = ft_strlen(p->value);
}

char	*str_f_apostr(t_p *p, char *str, int size)
{
	int ap;

	ap = 0;
	str[size] = '\0';
	while (p->fr_size-- > 0)
		str[--size] = p->value[p->fr_size + p->i_size];
	while (size > p->minus_sign)
	{
		str[--size] = p->value[--p->i_size];
		ap++;
		if (ap == 3)
		{
			str[--size] = ',';
			ap = 0;
		}
	}
	p->minus_sign ? (str[0] = '-') : 0;
	return (str);
}

void	apostr_f_production(t_p *p)
{
	char	*str;
	int		size;
	int		ap;

	ap = 0;
	p->i_size = 0;
	while (p->value[p->i_size] != '.' && p->value[p->i_size] != '\0')
		p->i_size++;
	p->fr_size = 0;
	while (p->value[p->i_size + p->fr_size] != '\0')
		p->fr_size++;
	p->i_size -= p->minus_sign;
	(p->i_size != 3) ? (ap = p->i_size / 3) : ap;
	((p->i_size % 3) == 0 && (p->i_size != 3)) ? (ap -= 1) : ap;
	p->i_size += p->minus_sign;
	size = p->i_size + p->fr_size + ap;
	str = (char*)malloc(sizeof(char) * (size + 1));
	str = str_f_apostr(p, str, size);
	free(p->value);
	p->value = str;
	p->value_len = ft_strlen(p->value);
}
