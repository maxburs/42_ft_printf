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
#include <string.h>

char			*parse_char(va_list *ap)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[1] = '\0';
	str[0] = (char)va_arg(*ap, int);
	return (str);
}

char			*parse_string(va_list *ap)
{
	return (ft_strdup((char*)va_arg(*ap, char*)));
}

char			*parse(t_conv *conv, va_list *ap)
{
	if (conv->letter == 's' || conv->letter == 'S')
	{
		return (parse_string(ap));
	}
	else if (ft_strchr("dDiuUoOxX", conv->letter))
	{
		return (parse_int(conv, ap));
	}
	else if (conv->letter == 'c' || conv->letter == 'C')
	{
		return (parse_char(ap));
	}
	else if (conv->letter == 'p')
	{
		return (parse_ptr(ap));
	}
	else
		return (NULL);
}
