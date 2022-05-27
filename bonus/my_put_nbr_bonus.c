/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_nbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 00:13:44 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/27 19:00:18 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*my_prcnbr(char *s, int l, int len, int i)
{
	char	*n;

	n = (char *)malloc(sizeof(char) * (len + 1));
	if (!n)
		return (s);
	if (s[0] == '-')
	{
		n[0] = '-';
		while (len - i++ > l)
			n[i] = '0';
	}
	else
	{
		while (len - i > l)
			n[i++] = '0';
	}
	while (s[i - (len - l)])
	{
		n[i] = s[i - (len - l)];
		i++;
	}
	n[i] = '\0';
	free(s);
	return (n);
}

int	my_putnbr(char *s, t_flag *f, int l)
{
	int		len;
	int		i;

	if (f->zero == 1)
		f->fill = '0';
	i = 0;
	len = l;
	if (f->prec == 1 && l <= f->prc_sz && s[0] == '-')
		len = f->prc_sz + 1;
	else if (f->prec == 1 && l - 1 < f->prc_sz && s[0] != '-')
		len = f->prc_sz;
	if (f->prc_sz == 0 && f->prec == 1 && s[0] == '0')
		len = 0;
	if (f->prec == 1 && l != len)
		s = my_prcnbr(s, l, len, 0);
	if (f->minus == 1)
		write(1, s, len);
	while (f->width - i++ > len)
		write(1, &(f->fill), 1);
	if (f->minus == 0)
		write(1, s, len);
	free(s);
	if (f->width > len)
		len = f->width;
	return (len);
}
