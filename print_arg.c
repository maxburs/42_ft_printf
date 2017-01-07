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

static char		*handle_int(t_conv *conv, va_list *ap)
{
	int		result;

	result = (int)va_arg(*ap, int);
	if (conv->letter == 'd' || conv->letter == 'i')
	{
		if (conv->length == HH_LENGTH)
			result = (int)(char)result;
		else if (conv->length == H_LENGTH)
			result = (int)(short)result;
	}
	return (ft_itoa(result));
}

static char		*pre_format(t_conv *conv, va_list *ap)
{
	if (conv->letter == 's')
	{
		return (ft_strdup(va_arg(*ap, char*)));
	}
	else if (conv->length == HH_LENGTH || conv->length == H_LENGTH
				|| (conv->length == 0 && (ft_strchr("diuoxX", conv->letter))))
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
