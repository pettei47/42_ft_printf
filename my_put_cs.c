/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:46:45 by tkitagaw          #+#    #+#             */
/*   Updated: 2022/05/11 09:55:31 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*out;

	out = (char *)s;
	while (*out)
	{
		if (*out == (char)c)
			return (out);
		out++;
	}
	if (*out == '\0' && c == '\0')
		return (out);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	my_put_c(t_flag *f, va_list ap)
{
	char	c;
	int		i;

	i = 0;
	c = '%';
	if (f->conv != '%')
		c = va_arg(ap, int);
	if (f->width < 1)
		f->width = 1;
	if (f->zero == 1)
		f->fill = '0';
	if (f->minus == 1)
		write(1, &c, 1);
	while (f->width - i++ > 1)
		write(1, &(f->fill), 1);
	if (f->minus == 0)
		write(1, &c, 1);
	return (f->width);
}

int	my_put_s(t_flag *f, va_list ap)
{
	char	*s;
	int		len;
	int		i;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = 0;
	if (f->zero == 1)
		f->fill = '0';
	i = 0;
	while (s[len] && (len < f->prc_sz || f->prec == 0))
		len++;
	if (f->minus == 1)
		write(1, s, len);
	while (f->width - i++ > len)
		write(1, &(f->fill), 1);
	if (f->minus == 0)
		write(1, s, len);
	if (f->width > len)
		len = f->width;
	return (len);
}
