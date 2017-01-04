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

static const char *format_characters = "sSpdDioOuUxXcC";

static int		is_format_char(char c)
{
	 const char *compare;

	compare = format_characters;
	while (*compare)
	{
		if (*compare == c)
			return (true);
		compare++;
	}
	return (false);
}

int		ft_printf(const char *format, ...)
{
	t_conv	conv;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format != '%')
			{
				zero_conv(&conv);
				while (!conv.letter)
				{
					//TODO: BUILD CONV HERE, BREAK INTO ANOTHER FUNCTION
					if (is_format_char(*format))
						conv.letter = *format;
					format++;
				}
				//TODO: HANDLE FORMAT STUFF HERE
				printf("\nconversion char: %c\n", conv.letter);
			}
		}
		write(1, format, 1);
		format++;
	}

	/*
	va_list		ap;
	va_start(ap, format);
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
	va_end(ap);
	*/
	return (0);
}
