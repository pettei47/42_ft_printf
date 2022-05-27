/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_diu_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:57:48 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/27 19:00:16 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	digit(long a, t_flag *f)
{
	int		i;
	long	b;

	i = 0;
	b = a;
	if (b < 0 || \
	(f->zero == 0 && b >= 0 && f->space_plus != '\0' && f->conv != 'u'))
	{
		if (b < 0)
			b *= -1;
		i++;
	}
	if (b == 0)
		return (i + 1);
	while (b > 0)
	{
		b /= 10;
		i++;
	}
	return (i);
}

static char	*my_itoa(long d, int dig, int m, t_flag *f)
{
	char		*a;
	int			i;

	a = (char *)malloc(sizeof(char) * (dig + 1));
	if (!a)
		return (NULL);
	i = 1;
	if (d < 0)
	{
		d *= -1;
		a[0] = '-';
		m = 1;
	}
	else if (f->zero == 0 && d >= 0 && f->space_plus != '\0' && f->conv != 'u')
	{
		a[0] = f->space_plus;
		m = 1;
	}
	while (i <= (dig - m))
	{
		a[dig - i++] = ((d % 10) + '0');
		d /= 10;
	}
	a[dig] = '\0';
	return (a);
}

int	my_put_diu(t_flag *f, va_list ap, int zero)
{
	long	d;
	char	*s;

	if (f->conv == 'u')
		d = (long)va_arg(ap, unsigned int);
	else
		d = (long)va_arg(ap, int);
	if ((f->zero == 1 && d < 0) || \
		(f->zero == 1 && d >= 0 && f->space_plus != '\0' && f->conv != 'u'))
	{
		if (d < 0)
		{
			write(1, "-", 1);
			d *= -1;
		}
		else
			write(1, &(f->space_plus), 1);
		f->width -= 1;
		zero = 1;
	}
	s = my_itoa(d, digit(d, f), 0, f);
	if (!s)
		return (0);
	return (my_putnbr(s, f, ft_strlen(s)) + zero);
}
