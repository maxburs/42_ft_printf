/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:18:35 by mburson           #+#    #+#             */
/*   Updated: 2017/01/05 20:18:37 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

static char		*parse_char(va_list *ap)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[1] = '\0';
	str[0] = (char)va_arg(*ap, int);
	return (str);
}

static char		*parse_string(va_list *ap)
{
	return (ft_strdup((char*)va_arg(*ap, char*)));
}

static char		*parse_ptr(va_list *ap)
{
	void	*ptr;
	size_t	size;
	t_conv	tmp_conv;
	char	*str1;
	char	*str2;

	zero_conv(&tmp_conv);
	size = sizeof(void*);
	tmp_conv.letter = 'x';
	tmp_conv.precision = size * 2;
	ptr = (void*)va_arg(*ap, void*);
	str1 = num_to_string(&tmp_conv, (uintmax_t)ptr);
	str2 = ft_strjoin("0x", str1);
	free(str1);
	return (str2);
}

static char		*parse_char_wide(va_list *ap)
{
	va_arg(*ap, wint_t);
	return (ft_strdup("ERROR WIDE CHARACTORS NOT SUPPORTED"));
}

static char		*parse_string_wide(va_list *ap)
{
	va_arg(*ap, wchar_t);
	return (ft_strdup("ERROR WIDE CHARACTORS NOT SUPPORTED"));
}

char			*parse(t_conv *conv, va_list *ap)
{
	if (conv->letter == 's' || conv->letter == 'S')
	{
		if (conv->length == L_LENGTH || conv->letter == 'S')
			return (parse_string_wide(ap));
		else
			return (parse_string(ap));
	}
	else if (ft_strchr("dDiuUoOxX", conv->letter))
	{
		return (parse_int(conv, ap));
	}
	else if (conv->letter == 'c' || conv->letter == 'C')
	{
		if (conv->length == L_LENGTH || conv->letter == 'C')
			return (parse_char_wide(ap));
		else
			return (parse_char(ap));
	}
	else if (conv->letter == 'p')
	{
		return (parse_ptr(ap));
	}
	else
		return (NULL);
}
