/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_set_width_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:15:02 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/11 00:13:14 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_set_width(const char **fmt, t_flag *f, va_list ap)
{
	if (**fmt == '*')
	{
		f->width = va_arg(ap, int);
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
	f->prec = 1;
	*fmt += 1;
	if (**fmt == '*')
	{
		f->prc_sz = va_arg(ap, int);
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
