/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:54:56 by mburson           #+#    #+#             */
/*   Updated: 2017/01/11 21:54:58 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <libft.h>
#include <ft_printf.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

static uintmax_t	get_num(t_conv *conv, va_list *ap)
{
	if (conv->length == HH_LENGTH)
	{
		return ((intmax_t)((char)va_arg(*ap, int)));
	}
	else if (conv->length == H_LENGTH)
	{
		return ((intmax_t)((short)va_arg(*ap, int)));
	}
	else if (conv->length == L_LENGTH)
	{
		return ((intmax_t)((long int)va_arg(*ap, long int)));
	}
	else if (conv->length == LL_LENGTH)
	{
		return ((intmax_t)((long long int)va_arg(*ap, long long int)));
	}
	else if (conv->length == J_LENGTH)
	{
		return (uintmax_t)va_arg(*ap, uintmax_t);
	}
	else if (conv->length == Z_LENGTH)
	{
		return ((size_t)va_arg(*ap, size_t));
	}
	else if (conv->letter == 'D' || conv->letter == 'U')
	{
		return ((intmax_t)((long int)va_arg(*ap, long int)));
	}
	else if (ft_strchr("oOuxX", conv->letter))
	{
		return ((unsigned int)va_arg(*ap, int));
	}
	else
	{
		return ((intmax_t)((int)va_arg(*ap, int)));
	}
}

static uintmax_t	handle_singed(t_conv *conv, uintmax_t num)
{
	if ((conv->letter == 'd' || conv->letter == 'D' || conv->letter == 'i')
		&& ((intmax_t)num < 0))
	{
		conv->flags = conv->flags | IS_NEG;
		return (ft_absolute((intmax_t)num));
	}
	return (num);
}

char				*num_to_string(t_conv *conv, uintmax_t num)
{
	char	*str;

	if (ft_strchr("dDiuU", conv->letter))
		str = ft_itoa_base(num, 10, false);
	else if (conv->letter == 'o' || conv->letter == 'O')
		str = ft_itoa_base(num, 8, false);
	else if (conv->letter == 'x')
		str = ft_itoa_base(num, 16, false);
	else if (conv->letter == 'X')
		str = ft_itoa_base(num, 16, true);
	else
		str = NULL;
	return (str);
}

char				*parse_int(t_conv *conv, va_list *ap)
{
	uintmax_t	result;

	result = get_num(conv, ap);
	result = handle_singed(conv, result);
	return (num_to_string(conv, result));
}
