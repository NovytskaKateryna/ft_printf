/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_analize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:21:01 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/17 16:20:16 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_color(char *format, int j)
{
	char	color[100];
	int		i;

	i = 0;
	while (format[++j] != '}')
		color[i++] = format[j];
	color[i] = '\0';
	if (!(ft_strcmp(color, "white")))
		write(1, WHITE_TEXT, 8);
	else if (!(ft_strcmp(color, "red")))
		write(1, RED_TEXT, 8);
	else if (!(ft_strcmp(color, "green")))
		write(1, GREEN_TEXT, 8);
	else if (!(ft_strcmp(color, "yellow")))
		write(1, YELLOW_TEXT, 8);
	else if (!(ft_strcmp(color, "blue")))
		write(1, BLUE_TEXT, 8);
	else if (!(ft_strcmp(color, "magneta")))
		write(1, MAGNETA_TEXT, 8);
	else if (!(ft_strcmp(color, "cyan")))
		write(1, CYAN_TEXT, 8);
	else if (!(ft_strcmp(color, "eoc")))
		write(1, EOC, 5);
	else
		return (0);
	return (i + 2);
}

int		output_length(const char *f, va_list ar, t_p *p)
{
	int		j;
	int		format_len;
	char	*format;

	j = -1;
	format = ft_strdup(f);
	format_len = ft_strlen(format);
	while (++j < format_len)
	{
		if (format[j] == '{')
			j += check_color(format, j);
		if (format[j] == '%')
		{
			j = write_format(p, format, ar, ++j);
			if (!(p->f.conversion))
				p->value = ft_strdup(&format[j]);
			output_analize(p, ar);
			reset_values(p);
		}
		else if (format[j] != '{' || format[j] != '}')
		{
			write(1, &format[j], 1);
			p->out_len++;
		}
	}
	ft_strdel(&format);
	return (p->out_len);
}
