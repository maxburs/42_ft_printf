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
#include <libft.h>
#include <stdlib.h>

static char		*handle_conv(const char **format, t_conv *conv, va_list *ap)
{
	char	*result;

	build_conv(format, conv);
	if (!conv->letter)
	{
		ft_putstr_fd("BUILD CONV ERROR", 0);
		return (NULL);
	}
	if (!(result = parse(conv, ap)))
	{
		ft_putstr_fd("PARSE ERROR", 0);
		return (NULL);
	}
	if (!(result = format_str(conv, result)))
	{
		ft_putstr_fd("FORMAT ERROR", 0);
		return (NULL);
	}
	return (result);
}

static void		print_arg(char *str)
{
	if (!str)
		return ;
	ft_putstr(str);
	free(str);
}

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
				print_arg(handle_conv(&format, &conv, &ap));
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
