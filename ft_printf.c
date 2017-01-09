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

#include <stdarg.h>
#include <unistd.h>
#include <ft_printf.h>

int				ft_printf(const char *format, ...)
{
	t_conv		conv;
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
				print_arg(&conv, &ap);
			}
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (0);
}
