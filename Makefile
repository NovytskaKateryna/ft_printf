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
SRCS = ft_printf.c arg_analize.c check.c conversions1.c conversions2.c\
			for_digits.c ft_strlen.c ft_strdup.c ft_strdel.c\
			ft_atoi.c ft_bzero.c flags_operations.c width_precision.c \
			utils.c initialize.c modifiers.c for_wide_char.c
LIBFT = ./libft/libft.a
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
	/bin/rm -f $(OBJS)

fclean: clean
	rm -rf bin objs
	/bin/rm -f $(NAME)

re: fclean all

vpath %.c $(SRCS_PATH)

.PHONY: clean fclean re all