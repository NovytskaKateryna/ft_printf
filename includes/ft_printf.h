/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:21:42 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/24 10:21:44 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct 	s_f
{
	char 		flags[5];
	int 		width;
	int 		precision;
	char 		modifier;
	char 		conversion;
}				t_f;

typedef struct	s_p
{
	int 		space;
	int 		left_justify;
	int 		minus_sign;
	int 		plus_sign;
	int 		prefix;
	int 		zero_pad;
	int 		pointer;
	int 		precision;
	int 		flags;
	char 		*value;
	int 		value_len;
	char 		*output;
	int 		out_len;
	char 		*format;
	int 		format_len;
	void 		*arg;
	t_f  		f;
}   			t_p;

typedef void 	(*f_operation)(t_p *p);
typedef int 	(*f_analizer)(t_p *p, va_list arg, f_operation *oper);

int			ft_printf(const char *format, ...);

int			output_length(const char *f, va_list ar);
void		char_conversion_specifiers(t_f *p, va_list ar, char sp);
void		string_conversion_specifiers(t_f *p, va_list ar, char sp);
void		int_conversion_specifiers(t_f *p, va_list ar, char sp);
void 		long_conversion_specifiers(t_f *p, va_list ar, char sp);
void 		pointer_conversion_specifier(t_f *p, va_list ar);

//working functions
char		*f_int_base(long long int n, int base);
char		*f_long_int_base(long long int n, int base);
char		*f_unsigned_int(unsigned long long int n, int base);

//libft functions
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s1);
char 		*ft_strcpy(char *dst, const char *src);

//check
int 		f_conversion(char f);
int 		f_size_modifier(char f);
int 		f_precision(char f);
int 		f_field_width( char f);
int 		f_flags(char f);

//conversion1
int 		signed_conversions(t_p *p, va_list ar, f_operation *oper);
int 		unsigned_conversions(t_p *p, va_list ar, f_operation *oper);
int 		persentage(t_p *p, va_list ar, f_operation *oper);
int			pointer_conversions(t_p *p, va_list ar, f_operation *oper);
int 		no_conversion_output(t_p *p, va_list ar, f_operation *oper);

//conversions2
int 		char_conversions(t_p *p, va_list ar, f_operation *oper);
int 		wide_char_conversions(t_p *p, va_list ar, f_operation *oper);

//flags_operations
void 		left_justification(t_p *p);
void 		zero_padding(t_p *p);
void 		sign_production(t_p *p);
void 		space_production(t_p *p);
void 		alternative_output(t_p *p);

//width_precision
void 		manage_width(t_p *p);
void 		manage_precision(t_p *p);
void 		string_precision(t_p *p, int start, int end, int j);

//utils
char 		*capital_hex(char *s);
void 		put_marks(t_p *p, int i);
void 		manage_operations(t_p *p, f_operation *oper);

//initialize
t_p 		*p_initialise(const char *format);
void		output_analize(t_p *p, va_list ar);
void		reset_values(t_p *p);

//modifiers
void 		manage_unsigned_modifier(t_p *p, int base);
void 		manage_decimal_modidfier(t_p *p, int base);

//for_wide_char
int 		get_value_len(t_p *p);
void 		get_wide_char(t_p *p);

#endif



