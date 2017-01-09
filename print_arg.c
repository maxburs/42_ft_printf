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

/* WHY DOESNT THIS SEEM TO DO ANYTHING KAYNE??
	if (conv->letter == 'd' || conv->letter == 'i')
	{
		if (conv->length == HH_LENGTH)
			result = (int)(char)result;
		else if (conv->length == H_LENGTH)
			result = (int)(short)result;
	}
	*/

static char		*handle_int(t_conv *conv, va_list *ap)
{
	unsigned long long int		result;
	_Bool						neg;
	char						*str;

	if (conv->length <= 3)
	{
		result = (int)va_arg(*ap, int);
	}
	
	if ((conv->letter == 'd' || conv->letter == 'i')
		&& (signed long long int)result < 0)
	{
		neg = true;
		result = ft_absolute((signed long long int)result);
	}
	else
		neg = false;

	if (conv->letter == 'd' || conv->letter == 'i' || conv->letter == 'u')
		str = (ft_itoa_base(result, 10, false));
	else if (conv->letter == 'o')
		str = (ft_itoa_base(result, 8, false));
	else if (conv->letter == 'x')
		str = (ft_itoa_base(result, 16, false));
	else if (conv->letter == 'X')
		str = (ft_itoa_base(result, 16, true));

	if (neg)
		return (ft_strjoin("-", str)); //TODO: FIX THIS! MEMORY LEAK HERE
	else
		return (str);
}

static char		*pre_format(t_conv *conv, va_list *ap)
{
	if (conv->letter == 's')
	{
		return (ft_strdup(va_arg(*ap, char*)));
	}
	else if (ft_strchr("diuoxX", conv->letter))
	{
		return (handle_int(conv, ap));
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
