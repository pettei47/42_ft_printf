/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_set_width_prec_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:15:02 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/27 19:00:21 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	my_set_width(const char **fmt, t_flag *f, va_list ap)
{
	long	tmp;

	if (**fmt == '*')
	{
		tmp = va_arg(ap, long);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			f->err = -1;
			return ;
		}
		f->width = (int)tmp;
		if (f->width < 0)
		{
			f->width *= -1;
			f->minus = 1;
		}
		*fmt += 1;
		return ;
	}
	f->width = 0;
	while ('0' <= **fmt && **fmt <= '9')
	{
		f->width = (f->width * 10) + (**fmt - '0');
		*fmt += 1;
	}
}

void	my_set_prec(const char **fmt, t_flag *f, va_list ap)
{
	long	tmp;

	f->prec = 1;
	*fmt += 1;
	if (**fmt == '*')
	{
		tmp = va_arg(ap, long);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			f->err = -1;
			return ;
		}
		f->prc_sz = (int)tmp;
		if (f->prc_sz < 0)
			f->prec = 0;
		*fmt += 1;
		return ;
	}
	f->prc_sz = 0;
	while ('0' <= **fmt && **fmt <= '9')
	{
		f->prc_sz = (f->prc_sz * 10) + (**fmt - '0');
		*fmt += 1;
	}
}
