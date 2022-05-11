/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 00:15:13 by teppei            #+#    #+#             */
/*   Updated: 2022/05/11 09:56:44 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int		a = 123456789;
	int		b = -123456789;
	char	c = '4';
	char	*s = "Born2Code";


	printf("========== Get Crasy ==========\n\n");
	printf("honke\n");
	printf("%%*.*s %*.*ddc%-20c\n", 11,5,s,3,7,a,c);
	printf("jisaku\n");
	ft_printf("%%*.*s %*.*ddc%-20c\n", 11,5,s,3,7,a,c);
	printf("========== Simple Conversion Management ==========\n\n");
	printf("<<<<<<<<<< Standard Input >>>>>>>>>>\n");
	printf("---- %%c ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%c", c));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%c", c));

	printf("---- %%s ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%s", s));

	printf("---- %%p ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%p", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%p", s));

	printf("---- %%d ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%d", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%d", a));

	printf("---- %%i ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%i", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%i", a));

	printf("---- %%u ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%u", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%u", a));

	printf("---- %%x ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%x", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%x", a));

	printf("---- %%X ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%X", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%X", a));

	printf("<<<<<<<<<< Special Case >>>>>>>>>>\n");
	printf("---- %%c NULL ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%c", NULL));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%c", NULL));

	printf("---- %%s NULL ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%s", NULL));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%s", NULL));

	printf("---- %%p NULL ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%p", NULL));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%p", NULL));

	printf("---- %%d -2147483648 ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%d", -2147483648));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%d", -2147483648));

	printf("---- %%i -2147483648 ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%i", -2147483648));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%i", -2147483648));

	printf("---- %%u -2147483648 ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%u", -2147483648));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%u", -2147483648));

	printf("---- %%x NULL ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%x", NULL));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%x", NULL));

	printf("---- %%X NULL ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%X", NULL));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%X", NULL));

	printf("<<<<<<<<<< Multiple Args / Conversions >>>>>>>>>>\n");
	printf("---- %%c %%s %%p ----\n");
	printf("printf    :");
	printf("|%d\n", printf("aaa %c bbb %s ccc %p ddd", '4', "42tokyo", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("aaa %c bbb %s ccc %p ddd", '4', "42tokyo", s));

	printf("========== For Bonus: Simple Flags Management ==========\n\n");
	printf("<<<<<<<<<< Min Field Width (string) >>>>>>>>>>\n");
	printf("---- %%20s (bigger) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%20s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%20s", s));

	printf("---- %%9s (equal) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%9s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%9s", s));

	printf("---- %%3s (small) ---\n");
	printf("printf    :");
	printf("|%d\n", printf("%3s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%3s", s));

	printf("<<<<<<<<<< Min Field Width (string with -) >>>>>>>>>>\n");
	printf("---- %%-20s (bigger) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%-20s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%-20s", s));

	printf("---- %%-9s (equal) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%-9s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%-9s", s));

	printf("---- %%-3s (small) ---\n");
	printf("printf    :");
	printf("|%d\n", printf("%-3s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%-3s", s));

	printf("<<<<<<<<<< Min Field Width (string with 0) >>>>>>>>>>\n");
	printf("---- %%020s (bigger) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%020s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%020s", s));

	printf("---- %%020d (bigger) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%020d", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%020d", a));

	printf("---- %%020x (bigger) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%020x", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%020x", a));

	printf("---- %%020p (bigger) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%020p", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%020p", a));

	printf("---- %%-20p (bigger) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%-20p", a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%-20p", a));

	printf("---- %%09s (equal) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%09s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%09s", s));

	printf("---- %%03s (small) ---\n");
	printf("printf    :");
	printf("|%d\n", printf("%03s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%03s", s));

	printf("<<<<<<<<<< Multiple Presicions >>>>>>>>>>\n");
	printf("---- %%020.5s (bigger) ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%020.5s", s));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%020.5s", s));

	printf("========== Advanced Flags Management ==========\n\n");
	printf("<<<<<<<<<< # flag >>>>>>>>>>\n");
	printf("---- %%#x %%#X ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%#x\nprintf    :%#X", a, a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%#x\nft_printf :%#X", a, a));

	printf("<<<<<<<<<< # flag2 >>>>>>>>>>\n");
	printf("---- %%#x %%#X ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%#020x\nprintf    :%#020X", a, a));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%#020x\nft_printf :%#020X", a, a));

	printf("<<<<<<<<<< ' ' flag >>>>>>>>>>\n");
	printf("---- %% a,b ----\n");
	printf("printf    :");
	printf("|%d\n", printf("% d\nprintf    :% d", a, b));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("% d\nft_printf :% d", a, b));

	printf("<<<<<<<<<< ' ' flag2 >>>>>>>>>>\n");
	printf("---- %% uint a,b ----\n");
	printf("printf    :");
	printf("|%d\n", printf("% u\nprintf    :% u", (unsigned int)a, (unsigned int)b));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("% u\nft_printf :% u", (unsigned int)a, (unsigned int)b));

	printf("<<<<<<<<<< ' ' flag3 >>>>>>>>>>\n");
	printf("---- %%0+a,b ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%0 20d\nprintf    :%0 20d", a, b));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%0 20d\nft_printf :%0 20d", a, b));

	printf("<<<<<<<<<< + flag >>>>>>>>>>\n");
	printf("---- %%+a,b ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%+d\nprintf    :%+d", a, b));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%+d\nft_printf :%+d", a, b));

	printf("<<<<<<<<<< + flag2 >>>>>>>>>>\n");
	printf("---- %% uint a,b ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%+u\nprintf    :%+u", (unsigned int)a, (unsigned int)b));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%+u\nft_printf :%+u", (unsigned int)a, (unsigned int)b));

	printf("<<<<<<<<<< + flag3 >>>>>>>>>>\n");
	printf("---- %%0+a,b ----\n");
	printf("printf    :");
	printf("|%d\n", printf("%0+20d\nprintf    :%0+20d", a, b));
	printf("ft_printf :");
	fflush(stdout);
	printf("|%d\n\n", ft_printf("%0+20d\nft_printf :%0+20d", a, b));

	return 0;
}
