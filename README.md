# ft_printf
This is one of 42 project's output.  

## Prototype:
	int ft_printf(const char *, ...);

## Description:  
This is a library that contains ft_printf, a function
that will mimic the real printf.

This can manage the following conversions: cspdiuxX%

This can manage any combination of the following flags: ’-0.*’ and  
minimum field width with all conversions

## Compilation
	make
then you can get **libftprintf.a**  
and at the directry your main.c exists  

	gcc main.c -L"filepath of libftprintf.a" -lftprintf