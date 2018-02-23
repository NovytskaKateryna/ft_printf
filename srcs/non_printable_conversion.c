/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_printable_conversion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:07:45 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/21 14:07:47 by knovytsk         ###   ########.fr       */
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

void	write_non_pritable(char *s, char c)
{
	if (is_non_printable(*s))
		c = 92;
	s++;
	write(1, &c, 1);
	if ((*s >= 1 && *s <= 6) || (*s >= 14 && *s <= 31))
		c = *s + 64;
	else if (*s == '\0')
		c = '0';
	else if (*s == '\a')
		c = 'a';
	else if (*s == '\b')
		c = 'b';
	else if (*s == '\t')
		c = 't';
	else if (*s == '\n')
		c = 'n';
	else if (*s == '\v')
		c = 'v';
	else if (*s == '\f')
		c = 'f';
	else if (*s == '\r')
		c = 'r';
	else if (*s == '\e')
		c = 'e';
	write(1, &c, 1);
}

void	non_print_conversion(t_out *out, va_list ar, t_flags *oper)
{
	char	*str;
	int		len;
	int		n;

	oper = 0;
	len = 0;
	str = va_arg(ar, char*);
	n = -1;
	while (str[++n])
		((str[n] >= 0 && str[n] <= 31) || str[n] == 127 ||
			str[n + 1] == 0) ? (len += 1) : len;
	len += n;
	out->out_len += len;
	while (len-- > 0)
	{
		if (*str >= 0 && *str <= 31)
			write_non_pritable(str, 94);
		write(1, &str, 1);
		str++;
	}
}
