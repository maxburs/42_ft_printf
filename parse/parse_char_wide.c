/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_wide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:06:03 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:06:21 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <wchar.h>
#include <stdarg.h>

char		*parse_char_wide(va_list *ap)
{
	va_arg(*ap, wint_t);
	return (ft_strdup("ERROR WIDE CHARACTORS NOT SUPPORTED"));
}
