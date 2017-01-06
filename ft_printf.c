/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:15:48 by mburson           #+#    #+#             */
/*   Updated: 2016/12/21 19:15:49 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <libft.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ft_printf.h>


int				ft_printf(const char *format, ...)
{
	ft_putstr("test");
	t_conv	conv;
	va_list		ap;
	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format != '%')
			{
				build_conv(&format, &conv);
				//TODO: PRINT FROM CONV HERE
				print_conv(&conv);
			}
		}
		write(1, format, 1);
		format++;
	}

	/*
	while (*format)
	{
		if (*format == 's')
		{
			printf("string: %s\n", va_arg(ap, char *));
		}
		else if (*format == 'd')
		{
			printf("int: %d\n", va_arg(ap, int));
		}
		format++;
	}
	*/

	va_end(ap);
	return (0);
}
