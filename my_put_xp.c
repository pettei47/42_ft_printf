/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_xp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:41:31 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/11 00:10:18 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*my_itoa_hex(unsigned long x)
{
	unsigned long	n;
	char			*a;
	int				i;
	int				digit;

	n = x;
	digit = 1;
	i = 1;
	while ((n / 16) > 0)
	{
		n /= 16;
		digit++;
	}
	a = (char *)malloc(sizeof(char) * (digit + 1));
	while (i <= digit)
	{
		a[digit - i++] = "0123456789abcdef"[x % 16];
		x /= 16;
	}
	a[digit] = '\0';
	return (a);
}

int	my_put_x(t_flag *f, va_list ap)
{
	unsigned int	x;
	char			*s;
	int				i;

	i = 0;
	x = va_arg(ap, unsigned int);
	s = my_itoa_hex(x);
	if (!s)
		return (0);
	if (f->conv == 'X')
	{
		while (s[i])
		{
			if ('a' <= s[i] && s[i] <= 'z')
				s[i] -= 32;
			i++;
		}
	}
	return (my_putnbr(s, f, ft_strlen(s)));
}

static int	my_putptr(char *s, t_flag *f, int l)
{
	int		i;
	int		len;

	if (f->zero == 1)
		f->fill = '0';
	i = 0;
	len = l;
	if (l < f->prc_sz && f->prec == 1)
		len = f->prc_sz;
	if (l < f->prc_sz && f->prec == 1)
		s = my_prcnbr(s, l, len, 0);
	if (f->minus == 1)
		write(1, "0x", 2);
	if (f->minus == 1)
		write(1, s, len);
	while (f->width - i++ > (len + 2))
		write(1, &(f->fill), 1);
	if (f->minus == 0)
		write(1, "0x", 2);
	if (f->minus == 0)
		write(1, s, len);
	free(s);
	if (f->width > (len + 2))
		len = f->width - 2;
	return (len + 2);
}

int	my_put_p(t_flag *f, va_list ap)
{
	unsigned long	p;
	char			*s;
	int				i;

	i = 0;
	p = va_arg(ap, unsigned long);
	s = my_itoa_hex(p);
	if (!s)
		return (0);
	if (f->prec == 1 && f->prc_sz == 0)
	{
		if (f->minus == 1)
			write(1, "0x", 2);
		while (f->width - i++ > 2)
			write(1, " ", 1);
		if (f->minus == 0)
			write(1, "0x", 2);
		if (2 > f->width)
			return (2);
		return (f->width);
	}
	return (my_putptr(s, f, ft_strlen(s)));
}
