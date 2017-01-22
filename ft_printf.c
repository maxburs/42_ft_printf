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
#include <stdbool.h>

#include <stdio.h>

/*
** b conversion character: print an integers bits
*/

static char		*handle_conv(const char **format, va_list *ap)
{
	char	*result;
	t_conv	conv;

	build_conv(format, &conv);
	if (!conv.letter)
	{
		ft_putstr_fd("BUILD CONV ERROR", 0);
		return (NULL);
	}
	inference(&conv);
	if (!(result = parse(&conv, ap)))
	{
		ft_putstr_fd("PARSE ERROR", 0);
		return (NULL);
	}
	if (!(result = format_str(&conv, result)))
	{
		ft_putstr_fd("FORMAT ERROR", 0);
		return (NULL);
	}
	return (result);
}

static int			st_vasprintf(char **ret, const char *format, va_list *ap)
{
	int			len;
	t_lstr		*l;
	char		*swap;

	l = NULL;
	while (*format)
	{
		len = ft_strchri(format, '%');
		if (len > 0)
		{
			ft_lstr_add(&l, ft_strndup(format, len), false);
			format += len;
		}
		else if (*format == '%')
		{
			format++;
			if (*format != '%')
			{
				swap = handle_conv(&format, ap);
				if (swap)
					ft_lstr_add(&l, swap, false);
				else
				{
					free(ft_lstr_finish(&l));
					return (-1);
				}
			}
			else
			{
				ft_lstr_add(&l, "%", true);
				format++;
			}
		}
		else
		{
			ft_lstr_add(&l, ft_strdup(format), false);
			break;
		}
	}
	*ret = (ft_lstr_finish(&l));
	return (ft_strlen(*ret));
}

int				ft_asprintf(char **ret, const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = st_vasprintf(ret, format, &ap);
	va_end(ap);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	int			len;

	va_start(ap, format);
	len = st_vasprintf(&str, format, &ap);
	va_end(ap);
	ft_putstr(str);
	return (len);
}
