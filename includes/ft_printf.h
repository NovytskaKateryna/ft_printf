/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:21:42 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/18 15:36:08 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define RED_TEXT "\033[31;1m"
# define GREEN_TEXT "\033[32;1m"
# define YELLOW_TEXT "\033[33;1m"
# define BLUE_TEXT "\033[34;1m"
# define MAGNETA_TEXT "\033[35;1m"
# define CYAN_TEXT "\033[36;1m"
# define WHITE_TEXT "\033[37;1m"
# define EOC "\033[0m"

# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

typedef struct			s_f
{
	char				flags[5];
	int					width;
	int					precision;
	char				modifier;
	char				conversion;
}						t_f;

typedef struct			s_p
{
	int					space;
	int					left_justify;
	int					minus_sign;
	int					plus_sign;
	int					prefix;
	int					apostr;
	int					zero_pad;
	int					pointer;
	int					precision;
	int					flags;
	char				*value;
	int					value_len;
	char				output[2048];
	int					out_len;
	int					color;
	void				*arg;
	unsigned long long	fr_part;
	unsigned long long	i_part;
	int					fr_size;
	int					zero_fr;
	int					i_size;
	int					exp;
	int					exp_size;
	int					dec_point;
	char				exp_sign;
	long double			num;
	double				year;
	double				month;
	double				day;
	double				hour;
	double				min;
	t_f					f;
}						t_p;

typedef void			(*t_operation)(t_p *p);
typedef int				(*t_analizer)(t_p *p, va_list arg, t_operation *oper);

int						ft_printf(const char *format, ...);
int						write_format(t_p *p, char *format, va_list ar, int j);
int						output_length(const char *f, va_list ar, t_p *p);
char					*f_int_base(long long int n, int base);
char					*f_unsigned_int(unsigned long long int n, int base);
int						check_float_values(t_p *p, long double arg, char conv);
char					*for_f_conv(t_p *p, long double num);
char					*for_e_conv(t_p *p, long double num);
char					*for_g_conv(t_p *p, long double num);
char					*for_a_conv(t_p *p, long double num);
void					get_exponent(t_p *p, long double num);
void					separate_num(t_p *p, long double num);
void					i_part_size(t_p *p, unsigned long i_p);
void 					f_part_size(t_p *p, unsigned long f_p);
void					g_size(unsigned long int f_p, t_p *p);
void					a_size(t_p *p, unsigned long i_p, unsigned long f_p);
int						exp_size(t_p *p, int exp);
void					round_fract_for_a(t_p *p);
int						round_parts_for_g(t_p *p);
size_t					ft_strlen(const char *s);
int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
char					*ft_strdup(const char *s1);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_strdel(char **as);
int						f_conversion(char f);
int						f_size_modifier(char f);
int						f_precision(char f);
int						f_field_width(char f);
int						f_flags(char f);
int						signed_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						unsigned_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						persentage(t_p *p, va_list ar, t_operation *oper);
int						pointer_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						no_conversion_output(t_p *p, va_list ar,
											t_operation *oper);
int						char_conversions(t_p *p, va_list ar, t_operation *oper);
int						wide_char_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						float_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						exponent_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						scientific_notation_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						hexadecimal_notation_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						int_pointer_conversions(t_p *p, va_list ar,
											t_operation *oper);
int						time_output(t_p *p, va_list ar,
											t_operation *oper);
int						str_with_no_printable(t_p *p, va_list ar,
											t_operation *oper);
void					left_justification(t_p *p);
void					zero_padding(t_p *p);
void					sign_production(t_p *p);
void					apostr_production(t_p *p);
void					apostr_f_production(t_p *p);
void					space_production(t_p *p);
void					alternative_output(t_p *p);
void					manage_width(t_p *p, int start, int j, int end);
void					manage_precision(t_p *p);
void					string_precision(t_p *p, int start, int end, int j);
void					capital_hex(char *s);
void					put_marks(t_p *p, int i, char conv);
void					manage_operations(t_p *p, t_operation *oper);
t_p						*p_initialise(t_p *k);
void					output_analize(t_p *p, va_list ar);
void					reset_values(t_p *p);
void					manage_unsigned_modifier(t_p *p, int base);
void					manage_decimal_modidfier(t_p *p, int base);
int						check_undefined_behavior(t_p *p, char *format, int k);
int						write_width(t_p *p, char *format, va_list ar, int j);
int						get_value_len(t_p *p);
void					get_wide_char(t_p *p);
#endif
