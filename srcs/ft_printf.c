/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:20:24 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/24 10:20:27 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args_ptr;

	va_start(args_ptr, format);
	ret = output_length(format, args_ptr);
	va_end(args_ptr);
	return (ret);
}