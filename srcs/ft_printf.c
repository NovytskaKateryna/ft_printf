/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:20:24 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:57:27 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_p		*p;
	va_list	args_ptr;

	p = p_initialise();
	va_start(args_ptr, format);
	ret = output_length(format, args_ptr, p);
	va_end(args_ptr);
	return (ret);
}
