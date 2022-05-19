/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:30:01 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/19 07:33:30 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_flag
{
	char	conv;
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		prc_sz;
	int		sharp;
	char	space_plus;
	char	fill;
	char	*x;
	int		err;
}				t_flag;

int				my_write(int fd, const char *s, int len);
int				ft_printf(const char *fmt, ...);
void			my_set_prec(const char **fmt, t_flag *f, va_list ap);
void			my_set_width(const char **fmt, t_flag *f, va_list ap);
int				my_put_c(t_flag *f, va_list ap);
int				my_put_s(t_flag *f, va_list ap);
int				my_put_diu(t_flag *f, va_list ap, int zero);
int				my_put_x(t_flag *f, va_list ap);
int				my_put_p(t_flag *f, va_list ap);
int				my_putnbr(char *s, t_flag *f, int l);
char			*ft_strchr(const char *s, int c);
int				ft_strlen(char *s);
char			*my_prcnbr(char *s, int l, int len, int i);

#endif
