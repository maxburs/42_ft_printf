/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:07:06 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:07:23 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <libft.h>
#include <string.h>
#include <ft_printf.h>
#include <stdbool.h>

/*
static char		*parse_char_bitwise(char c)
{
	char	*str;

	str = ft_itoa_base((unsigned char)c, 2, true);
	format_precision(sizeof(char), str);
	return (str);
}

static char		*parse_str_alt(char *str)
{
	s_lstr	l;

	l = NULL;
	ft_lstr_add(&l, )
}
*/
char			*parse_str(t_conv *conv, va_list *ap)
{
	char *str;

	conv->precision++;
	str = (char*)va_arg(*ap, char*);
	//if (!(conv->flags & HASH_FLAG))
		return (ft_strdup(str));
	//else
	//	return (parse_str_alt(str));
	
}
