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

/*
static void		handle_int(int argument, t_conv *conv)
{

}

static void		handle_float(int argument, t_conv *conv)
{
	
}

static void		handle_double(int argument, t_conv *conv)
{
	
}

static void		handle_char(int argument, t_conv *conv)
{
	
}
*/
static char		*pre_format(t_conv *conv, va_list *ap)
{
	if (conv->letter == 's')
		return (va_arg(*ap, char*));
	return (" NO FORMAT FOUND ");
}

void			print_arg(t_conv *conv, va_list *ap)
{
	char *result;

	//print_conv(conv);

	result = pre_format(conv, ap);
	//ft_putstr(result);
}
