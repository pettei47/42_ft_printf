/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:39:48 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/27 18:59:45 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	my_flag_reset(t_flag *f)
{
	f->conv = '\0';
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->prec = 0;
	f->prc_sz = 0;
	f->sharp = 0;
	f->space_plus = '\0';
	f->fill = ' ';
	f->x = "0x";
	f->err = 0;
}

static int	my_set_conv(char *fmt, t_flag *f)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (ft_strchr("cspdiuxX%", fmt[i]))
		{
			f->conv = fmt[i];
			return (1);
		}
		i++;
	}
	return (0);
}

static void	my_flag_chk(char **fmt, t_flag *f, va_list ap)
{
	while (**fmt != f->conv)
	{
		if (**fmt == '-')
			f->minus = 1;
		else if (**fmt == '0' && f->prec == 0)
			f->zero = 1;
		else if (**fmt == '#')
			f->sharp = 1;
		else if (ft_strchr(" +", **fmt) && f->space_plus != '+')
			f->space_plus = **fmt;
		else if (((47 < **fmt && **fmt < 58) || **fmt == '*') && f->prec < 1)
			my_set_width((const char **)fmt, f, ap);
		else if (**fmt == '.')
			my_set_prec((const char **)fmt, f, ap);
		else
			*fmt += 1;
		if ((**fmt == '0' && f->prec == 0) || ft_strchr("-# +", **fmt))
			*fmt += 1;
		if (f->err < 0)
			return ;
	}
	*fmt += 1;
	if (f->minus == 1 || (f->prec == 1 && ft_strchr("pdiuixX", f->conv)))
		f->zero = 0;
}

static int	my_chk_conv(char **fmt, t_flag *f, va_list ap, int *pc)
{
	int	ret;

	*fmt += 1;
	if (my_set_conv(*fmt, f) == 0)
		return (-1);
	my_flag_chk(fmt, f, ap);
	if (f->err < 0)
		return (-1);
	ret = -1;
	if (f->conv == 'c' || f->conv == '%')
		ret = my_put_c(f, ap);
	else if (f->conv == 's')
		ret = my_put_s(f, ap);
	else if (f->conv == 'p' || (ft_strchr("xX", f->conv) && f->sharp == 1))
		ret = my_put_p(f, ap);
	else if (f->conv == 'd' || f->conv == 'i' || f->conv == 'u')
		ret = my_put_diu(f, ap, 0);
	else if (f->conv == 'x' || f->conv == 'X')
		ret = my_put_x(f, ap);
	*pc = ret;
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_flag	f;
	long	ret;
	int		pc;

	va_start(ap, fmt);
	my_flag_reset(&f);
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (my_chk_conv((char **)&fmt, &f, ap, &pc) < 0)
				return (ret);
			my_flag_reset(&f);
		}
		else
			pc = my_write(1, fmt++, 1);
		ret += pc;
		if (ret > INT_MAX)
			return (-1);
	}
	va_end(ap);
	return (ret);
}
