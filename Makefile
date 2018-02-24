# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:34:33 by knovytsk          #+#    #+#              #
#    Updated: 2018/01/24 14:34:35 by knovytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ft_printf.c arg_analize.c format_analize.c analizers.c check_float.c check_format.c reset_initial.c\
		char_conversions.c integer_conversions.c other_conversions.c float_conversions.c time_conversion.c\
		non_printable_conversion.c a_conv_operations.c g_conv_operations.c for_int_conv.c for_wide_char.c\
		for_f_conv.c for_e_conv.c for_g_conv.c for_a_conv.c double_sizes.c width_precision.c manage_operations.c\
		modifiers.c flags_operations.c apostr_production.c put_marks.c ft_atoi.c ft_bzero.c ft_strcmp.c ft_strdup.c\
		ft_strlen.c ft_strdel.c
FLAGS = gcc -Wall -Wextra -Werror
INCLUDES = -I includes 

OBJS = $(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 

$(OBJS): | $(OBJS_PATH)

$(OBJS_PATH):
	mkdir $(OBJS_PATH)

$(OBJS_PATH)/%.o: %.c
	$(FLAGS) -c $< -o $@ $(INCLUDES) 

clean:
	rm -rf bin objs
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

vpath %.c $(SRCS_PATH)

.PHONY: clean fclean re all