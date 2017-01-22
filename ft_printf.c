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

static void		print_arg(char *str)
{
	if (!str)
		return ;
	ft_putstr(str);
	free(str);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	t_lstr		*l;

	va_start(ap, format);
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
				ft_lstr_add(&l, handle_conv(&format, &ap), false);
			}
			else
			{
				ft_lstr_add(&l, "%", true);
				format++;
			}
		}
		/*
		if (*format == '%')
		{

		}
		else
		{
			write(1, format, 1);
			format++;
		}
		*/
	}
	ft_pustr(ft_lstr_finish(&l));
	va_end(ap);
	return (0);
}
