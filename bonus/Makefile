# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 17:42:38 by tkitagaw          #+#    #+#              #
#    Updated: 2022/05/27 19:02:21 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLGS	=	-Wall -Wextra -Werror
LIBS	=	ar -rc
NAME	=	libftprintf.a
SRCS	=	ft_printf_bonus.c my_set_width_prec_bonus.c my_put_cs_bonus.c \
			my_put_diu_bonus.c my_put_xp_bonus.c my_put_nbr_bonus.c \
			
OBJS	=	$(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLGS) -c $< -o $@ -I./

all : $(NAME)

$(NAME) : $(OBJS)
	$(LIBS) $(NAME) $(OBJS)
	cp $(NAME) ../

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus: all

.PHONY: all clean fclean re bonus
