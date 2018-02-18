/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:20:15 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/18 15:37:43 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_non_printable(char c)
{
	if (c == '\0' || c == '\a' || c == '\b' ||
		c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == '\e')
		return (1);
	return (0);
}

int		write_nonpritable(t_p *p, char *s, int n, int j)
{
	if (is_non_printable(s[j]))
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
	n = -1;
	while (str[++n])
		((str[n] >= 0 && str[n] <= 31) || str[n] == 127 ||
			str[n + 1] == 0) ? (i += 1) : i;
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
