/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:57:48 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/11 01:25:57 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit(long long a)
{
	int			i;
	long long	b;

	i = 0;
	b = a;
	if (b == 0)
		return (1);
	if (b < 0)
	{
		b *= -1;
		i++;
	}
	while (b > 0)
	{
		b /= 10;
		i++;
	}
	return (i);
}

static char	*my_itoa(long long d)
{
	char		*a;
	int			dig;
	int			i;
	int			m;

	dig = digit(d);
	m = 0;
	a = (char *)malloc(sizeof(char) * dig + 1);
	if (!a)
		return (NULL);
	i = 1;
	if (d < 0)
	{
		d *= -1;
		a[0] = '-';
		m = 1;
	}
	while (i <= (dig - m))
	{
		a[dig - i] = ((d % 10) + '0');
		i++;
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
		(f->space_plus != '\0' && d >= 0 && f->conv != 'u'))
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
	s = my_itoa((long long)d);
	if (!s)
		return (0);
	return (my_putnbr(s, f, ft_strlen(s)) + zero);
}
