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
#include <stdbool.h>
#include <stdint.h>

/* WHY DOESNT THIS SEEM TO DO ANYTHING KAYNE??
	if (conv->letter == 'd' || conv->letter == 'i')
	{
		if (conv->length == HH_LENGTH)
			result = (int)(char)result;
		else if (conv->length == H_LENGTH)
			result = (int)(short)result;
	}
	*/

static uintmax_t	get_num(t_conv *conv, va_list *ap)
{
	if (conv->length == L_LENGTH)
	{
		return ((long)va_arg(*ap, long int));
	}
	else if (conv->length == LL_LENGTH)
	{
		return ((long)va_arg(*ap, long long int));
	}
	else if (conv->length == 'j')
	{
		return (uintmax_t)va_arg(*ap, int);
	}
	else if (conv->letter == 'd' || conv->letter == 'i')
	{
		return ((int)va_arg(*ap, int));
	}
	else
	{
		return ((unsigned int)va_arg(*ap, unsigned int));
	}
}

static uintmax_t	handle_singed(t_conv *conv, uintmax_t num)
{
	if ((conv->letter == 'd' || conv->letter == 'i')
		&& (intmax_t)num < 0)
	{
		conv->flags = conv->flags | IS_NEG;
		return (ft_absolute((intmax_t)num));
	}
	return (num);
}

static char			*handle_num(t_conv *conv, va_list *ap)
{
	unsigned long long int		result;
	char						*str;

	
	result = get_num(conv, ap);
	result = handle_singed(conv, result);

	if (conv->letter == 'd' || conv->letter == 'i' || conv->letter == 'u')
		str = (ft_itoa_base(result, 10, false));
	else if (conv->letter == 'o')
		str = (ft_itoa_base(result, 8, false));
	else if (conv->letter == 'x')
		str = (ft_itoa_base(result, 16, false));
	else if (conv->letter == 'X')
		str = (ft_itoa_base(result, 16, true));

	if (conv->flags & IS_NEG)
		return (ft_strjoin("-", str)); //TODO: FIX THIS! MEMORY LEAK HERE
	else
		return (str);
}

static char			*pre_format(t_conv *conv, va_list *ap)
{
	if (conv->letter == 's')
	{
		return (ft_strdup(va_arg(*ap, char*)));
	}
	else if (ft_strchr("diuoxX", conv->letter))
	{
		return (handle_num(conv, ap));
	}
	else
		return (NULL);
}

void			print_arg(t_conv *conv, va_list *ap)
{
	char *result;

	//print_conv(conv);

	result = pre_format(conv, ap);
	if (result == NULL)
		ft_putstr("ERROR");
	else
	{
		ft_putstr(result);
		free(result);
	}
}
