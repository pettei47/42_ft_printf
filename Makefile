# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 17:42:38 by tkitagaw          #+#    #+#              #
#    Updated: 2021/02/06 14:36:49 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLGS	=	-Wall -Wextra -Werror
LIBS	=	ar -rc
NAME	=	libftprintf.a
SRCS	=	ft_printf.c my_set_width_prec.c my_put_cs.c \
			my_put_diu.c my_put_xp.c my_put_nbr.c
OBJS	=	$(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLGS) -c $< -o $@ -I ft_printf.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(LIBS) $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
