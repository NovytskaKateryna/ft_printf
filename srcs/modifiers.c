/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:29:42 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/03 19:29:43 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	manage_unsigned_modifier(t_p *p, int base)
{
	if (p->f.modifier == 'z')
		p->value = f_unsigned_int((size_t)p->arg, base);
	else if (p->f.modifier == 'j')
		p->value = f_unsigned_int((uintmax_t)p->arg, base);
	else if (p->f.modifier == 'L')
		p->value = f_unsigned_int((unsigned long long int)p->arg, base);
	else if (p->f.modifier == 'l' || p->f.conversion == 'U' ||
		p->f.conversion == 'O')
			p->value = f_unsigned_int((unsigned long int)p->arg, base);
	else if (p->f.modifier == 'h')
		p->value = f_unsigned_int((unsigned short int)p->arg, base);
	else if (p->f.modifier == 'H')
		p->value = f_unsigned_int((unsigned char)p->arg, base);
	else
		p->value = f_unsigned_int((unsigned int)p->arg, base);	
}

void 	manage_decimal_modidfier(t_p *p, int base)
{
	if (p->f.modifier == 'z')
		p->value = f_int_base((size_t)p->arg, base);
	else if (p->f.modifier == 'j')
		p->value = f_int_base((intmax_t)p->arg, base);
	else if (p->f.modifier == 'L')
		p->value = f_int_base((long long int)p->arg, base);
	else if (p->f.modifier == 'l' || p->f.conversion == 'D')
		p->value = f_int_base((long int)p->arg, base);
	else if (p->f.modifier == 'h')
		p->value = f_int_base((short int)p->arg, base);
	else if (p->f.modifier == 'H')
		p->value = f_int_base((signed char)p->arg, base);
	else
		p->value = f_int_base((int)p->arg, base);
}
