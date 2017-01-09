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

	result = pre_format(conv, ap);
	if (result == NULL)
		ft_putstr("ERROR");
	else
	{
		ft_putstr(result);
		free(result);
	}
}
