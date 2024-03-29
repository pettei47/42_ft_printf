# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 17:42:38 by tkitagaw          #+#    #+#              #
#    Updated: 2022/05/29 18:52:41 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLGS	=	-Wall -Wextra -Werror
LIBS	=	ar -rc
NAME	=	libftprintf.a
SRCS	=	ft_printf.c my_set_width_prec.c my_put_cs.c \
			my_put_diu.c my_put_xp.c my_put_nbr.c \
			
OBJS	=	$(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLGS) -c $< -o $@ -I./

all : $(NAME)

$(NAME) : $(OBJS)
	$(LIBS) $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)
	make clean -C bonus

fclean : clean
	rm -f $(NAME)
	make fclean -C bonus

re : fclean all

bonus:
	make -C bonus

.PHONY: all clean fclean re bonus
